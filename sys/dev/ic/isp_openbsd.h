/*      $OpenBSD: isp_openbsd.h,v 1.15 2001/08/12 20:33:50 mickey Exp $ */
/*
 * OpenBSD Specific definitions for the Qlogic ISP Host Adapter
 */
/*
 * Copyright (C) 1999, 2000, 2001 by Matthew Jacob
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef	_ISP_OPENBSD_H
#define	_ISP_OPENBSD_H

#include <sys/types.h>
#include <sys/param.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/errno.h>  
#include <sys/ioctl.h>
#include <sys/device.h>
#include <sys/malloc.h>
#include <sys/buf.h> 
#include <sys/proc.h>
#include <sys/user.h>
#include <sys/queue.h>

#include <scsi/scsi_all.h>
#include <scsi/scsi_all.h>
#include <scsi/scsiconf.h>

#include <scsi/scsi_message.h>
#include <scsi/scsi_debug.h>

#include <vm/vm.h>


#define	ISP_PLATFORM_VERSION_MAJOR	2
#define	ISP_PLATFORM_VERSION_MINOR	0

struct isposinfo {
	struct device		_dev;
	struct scsi_link	_link[2];
	struct scsi_adapter	_adapter;
	int			hiwater;
	int			splsaved;
	int			mboxwaiting;
	u_int32_t		islocked;
	u_int32_t		onintstack;
	unsigned int		: 28,
		
		rtpend		: 1,
		no_mbox_ints	: 1,
		blocked		: 2;
	union {
		u_int64_t 	_wwn;
		u_int16_t	_discovered[2];
	} un;
#define	discovered	un._discovered
	struct scsi_xfer	*wqf, *wqt;
	struct timeout rqt;
};
#define	MUST_POLL(isp)	\
	(isp->isp_osinfo.onintstack || isp->isp_osinfo.no_mbox_ints)

/*
 * Locking macros...
 */
#define	ISP_LOCK		isp_lock
#define	ISP_UNLOCK		isp_unlock

/*
 * Required Macros/Defines
 */

#define	INLINE			inline

#define	ISP2100_SCRLEN		0x400

#define	MEMZERO			bzero
#define	MEMCPY(dst, src, amt)	bcopy((src), (dst), (amt))
#define	SNPRINTF		snprintf
#define	STRNCAT			strncat
#define	USEC_DELAY(x)		delay(x)
#define	USEC_SLEEP(isp, x)		\
	if (!MUST_POLL(isp))		\
		ISP_UNLOCK(isp);	\
	delay(x);			\
	if (!MUST_POLL(isp))		\
		ISP_LOCK(isp)

#define	NANOTIME_T		struct timeval
#define	GET_NANOTIME		microtime
#define	GET_NANOSEC(x)		(((x)->tv_sec * 1000000 + (x)->tv_usec) * 1000)
#define	NANOTIME_SUB		isp_microtime_sub

#define	MAXISPREQUEST(isp)	256

#ifdef	__alpha__
#define	MEMORYBARRIER(isp, type, offset, size)	alpha_mb()
#else
#define	MEMORYBARRIER(isp, type, offset, size)
#endif

#define	MBOX_ACQUIRE(isp)
#define	MBOX_WAIT_COMPLETE	isp_wait_complete

#define	MBOX_NOTIFY_COMPLETE(isp)					\
	if (isp->isp_osinfo.mboxwaiting) {				\
                isp->isp_osinfo.mboxwaiting = 0;			\
                wakeup(&isp->isp_osinfo.mboxwaiting);			\
        }								\
	isp->isp_mboxbsy = 0

#define	MBOX_RELEASE(isp)

#ifndef	SCSI_GOOD
#define	SCSI_GOOD	0x0
#endif
#ifndef	SCSI_CHECK
#define	SCSI_CHECK	0x2
#endif
#ifndef	SCSI_BUSY
#define	SCSI_BUSY	0x8
#endif
#ifndef	SCSI_QFULL
#define	SCSI_QFULL	0x28
#endif

#define	XS_T			struct scsi_xfer
#define	XS_CHANNEL(xs)		(((xs)->sc_link->flags & SDEV_2NDBUS)? 1 : 0)
#define	XS_ISP(xs)		(xs)->sc_link->adapter_softc
#define	XS_LUN(xs)		((int) (xs)->sc_link->lun)
#define	XS_TGT(xs)		((int) (xs)->sc_link->target)
#define	XS_CDBP(xs)		((caddr_t) (xs)->cmd)
#define	XS_CDBLEN(xs)		(xs)->cmdlen
#define	XS_XFRLEN(xs)		(xs)->datalen
#define	XS_TIME(xs)		(xs)->timeout
#define	XS_RESID(xs)		(xs)->resid
#define	XS_STSP(xs)		(&(xs)->status)
#define	XS_SNSP(xs)		(&(xs)->sense)
#define	XS_SNSLEN(xs)		(sizeof (xs)->sense)
#define	XS_SNSKEY(xs)		((xs)->sense.flags)
#define	XS_TAG_P(xs)		(((xs)->flags & SCSI_POLL) != 0)
#define	XS_TAG_TYPE(xs)		REQFLAG_STAG

#define	XS_SETERR(xs, v)	(xs)->error = v

#	define	HBA_NOERROR		XS_NOERROR
#	define	HBA_BOTCH		XS_DRIVER_STUFFUP
#	define	HBA_CMDTIMEOUT		XS_TIMEOUT
#	define	HBA_SELTIMEOUT		XS_SELTIMEOUT
#	define	HBA_TGTBSY		XS_BUSY
#	define	HBA_BUSRESET		XS_RESET
#	define	HBA_ABORTED		XS_DRIVER_STUFFUP
#	define	HBA_DATAOVR		XS_DRIVER_STUFFUP
#	define	HBA_ARQFAIL		XS_DRIVER_STUFFUP

#define	XS_ERR(xs)		(xs)->error

#define	XS_NOERR(xs)		(xs)->error == XS_NOERROR

#define	XS_INITERR(xs)		(xs)->error = 0, XS_CMD_S_CLEAR(xs)

#define	XS_SAVE_SENSE(xs, sp)				\
	if (xs->error == XS_NOERROR) {			\
		xs->error = XS_SENSE;			\
	}						\
	bcopy(sp->req_sense_data, &(xs)->sense,		\
	    imin(XS_SNSLEN(xs), sp->req_sense_len))

#define	XS_SET_STATE_STAT(a, b, c)

#define	DEFAULT_IID(x)		7
#define	DEFAULT_LOOPID(x)	107
#define	DEFAULT_NODEWWN(isp)	(isp)->isp_osinfo.un._wwn
#define	DEFAULT_PORTWWN(isp)	(isp)->isp_osinfo.un._wwn
#define	ISP_NODEWWN(isp)	FCPARAM(isp)->isp_nodewwn
#define	ISP_PORTWWN(isp)	FCPARAM(isp)->isp_portwwn

#define	ISP_UNSWIZZLE_AND_COPY_PDBP(isp, dest, src)	\
	if((void *)src != (void *)dest) bcopy(src, dest, sizeof (isp_pdb_t))
#define	ISP_SWIZZLE_ICB(a, b)
#ifdef	__sparc__
#define ISP_SWIZZLE_REQUEST(a, b)			\
	ISP_SBUSIFY_ISPHDR(a, &(b)->req_header);	\
        ISP_SBUSIFY_ISPREQ(a, b)
#define ISP_UNSWIZZLE_RESPONSE(a, b, c)			\
	ISP_SBUSIFY_ISPHDR(a, &(b)->req_header)
#else
#define	ISP_SWIZZLE_REQUEST(a, b)
#define	ISP_UNSWIZZLE_RESPONSE(a, b, c)
#endif
#define	ISP_SWIZZLE_SNS_REQ(a, b)
#define	ISP_UNSWIZZLE_SNS_RSP(a, b, c)
#ifdef	__sparc__
#define	ISP_SWIZZLE_NVRAM_WORD(isp, rp)	\
	{								\
		u_int16_t tmp = *rp >> 8;				\
		tmp |= ((*rp & 0xff) << 8);				\
		*rp = tmp;						\
	}
#else
#define	ISP_SWIZZLE_NVRAM_WORD(isp, rp)
#endif

/*
 * Includes of common header files
 */

#include <dev/ic/ispreg.h>
#include <dev/ic/ispvar.h>
#include <dev/ic/ispmbox.h>

/*
 * isp_osinfo definitions, extensions and shorthand.
 */
#define	isp_name	isp_osinfo._dev.dv_xname
#define	isp_unit	isp_osinfo._dev.dv_unit

/*
 * Driver prototypes..
 */
void isp_attach(struct ispsoftc *);
void isp_uninit(struct ispsoftc *);

static inline void isp_lock(struct ispsoftc *);
static inline void isp_unlock(struct ispsoftc *);
static inline char *strncat(char *, const char *, size_t);
static inline u_int64_t
isp_microtime_sub(struct timeval *, struct timeval *);
static void isp_wait_complete(struct ispsoftc *);

/*
 * Driver wide data...
 */

/*              
 * Platform private flags                                               
 */

#define	XS_PSTS_INWDOG		0x10000
#define	XS_PSTS_GRACE		0x20000
#define	XS_PSTS_TIMED		0x40000
#define	XS_PSTS_ALL		SCSI_PRIVATE

#define	XS_CMD_S_WDOG(xs)	(xs)->flags |= XS_PSTS_INWDOG
#define	XS_CMD_C_WDOG(xs)	(xs)->flags &= ~XS_PSTS_INWDOG
#define	XS_CMD_WDOG_P(xs)	(((xs)->flags & XS_PSTS_INWDOG) != 0)

#define	XS_CMD_S_TIMER(xs)	(xs)->flags |= XS_PSTS_TIMED
#define	XS_CMD_C_TIMER(xs)	(xs)->flags &= ~XS_PSTS_TIMED
#define	XS_CMD_TIMER_P(xs)	(((xs)->flags & XS_PSTS_TIMED) != 0)

#define	XS_CMD_S_GRACE(xs)	(xs)->flags |= XS_PSTS_GRACE
#define	XS_CMD_C_GRACE(xs)	(xs)->flags &= ~XS_PSTS_GRACE
#define	XS_CMD_GRACE_P(xs)	(((xs)->flags & XS_PSTS_GRACE) != 0)

#define	XS_CMD_S_DONE(xs)	(xs)->flags |= ITSDONE
#define	XS_CMD_C_DONE(xs)	(xs)->flags &= ~ITSDONE
#define	XS_CMD_DONE_P(xs)	(((xs)->flags & ITSDONE) != 0)

#define	XS_CMD_S_CLEAR(xs)	(xs)->flags &= ~XS_PSTS_ALL

/*
 * Platform specific 'inline' or support functions
 */
static inline void
isp_lock(struct ispsoftc *isp)
{
	int s = splbio();
	if (isp->isp_osinfo.islocked++ == 0) {
		isp->isp_osinfo.splsaved = s;
	} else {
		splx(s);
	}
}

static inline void
isp_unlock(struct ispsoftc *isp)
{
	if (isp->isp_osinfo.islocked-- <= 1) {
		isp->isp_osinfo.islocked = 0;
		splx(isp->isp_osinfo.splsaved);
	}
}

static inline char *
strncat(char *d, const char *s, size_t c)
{
        char *t = d;

        if (c) {
                while (*d)
                        d++;
                while ((*d++ = *s++)) {
                        if (--c == 0) {
                                *d = '\0';
                                break;
                        }
                }
        }
        return (t);
}

static inline u_int64_t
isp_microtime_sub(struct timeval *b, struct timeval *a)
{
	struct timeval x;
	u_int64_t elapsed;
	timersub(b, a, &x);
	elapsed = GET_NANOSEC(&x);
	if (elapsed == 0)
		elapsed++;
	return (elapsed);
}

static inline void
isp_wait_complete(struct ispsoftc *isp)
{
	if (MUST_POLL(isp)) {
		int usecs = 0;
		while (usecs < 2 * 1000000) {
			(void) isp_intr(isp);
			if (isp->isp_mboxbsy == 0) {
				break;
			}
			USEC_DELAY(500);
			usecs += 500;
		}
		if (isp->isp_mboxbsy != 0) {
			isp_prt(isp, ISP_LOGWARN,
			    "Polled Mailbox Command (0x%x) Timeout",
			    isp->isp_lastmbxcmd);
		}
	} else {
		int rv = 0;
                isp->isp_osinfo.mboxwaiting = 1;
                while (isp->isp_osinfo.mboxwaiting && rv == 0) {
			static struct timeval fivesec = { 5, 0 };
			int timo;
			struct timeval tv;
			microtime(&tv);
			timeradd(&tv, &fivesec, &tv);
			if ((timo = hzto(&tv)) == 0) {
				timo = 1;
			}
			rv = tsleep(&isp->isp_osinfo.mboxwaiting,
			    PRIBIO, "isp_mboxcmd", timo);
		}
		if (rv == EWOULDBLOCK) {
			isp->isp_mboxbsy = 0;
			isp->isp_osinfo.mboxwaiting = 0;
			isp_prt(isp, ISP_LOGWARN,
			    "Interrupting Mailbox Command (0x%x) Timeout",
			    isp->isp_lastmbxcmd);
		}
	}
}

/*
 * Common inline functions
 */
#include <dev/ic/isp_inline.h>

#endif	/* _ISP_NETBSD_H */
