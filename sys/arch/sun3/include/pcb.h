/*	$OpenBSD: pcb.h,v 1.4 2001/08/31 21:28:11 miod Exp $	*/
/*	$NetBSD: pcb.h,v 1.9 1996/06/18 16:03:45 gwr Exp $	*/

/*
 * Copyright (c) 1994 Gordon W. Ross
 * Copyright (c) 1993 Adam Glass
 * Copyright (c) 1988 University of Utah.
 * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * the Systems Programming Group of the University of Utah Computer
 * Science Department.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: Utah Hdr: pcb.h 1.14 91/03/25
 *	from: @(#)pcb.h	8.1 (Berkeley) 6/10/93
 */

#ifndef	_MACHINE_PCB_H_
#define	_MACHINE_PCB_H_

#include <machine/frame.h>

/*
 * Sun3 process control block
 */
struct pcb {
	short	pcb_flags;	/* misc. process flags */
	short	pcb_ps; 	/* processor status word */
	int	pcb_mmuctx;	/* MMU context number */
	int	pcb_usp;	/* user stack pointer */
	int	pcb_regs[12];	/* D2-D7, A2-A7 */
	caddr_t	pcb_onfault;	/* for copyin/out faults */
	struct	fpframe pcb_fpregs; /* 68881/2 context save area */
};

/*
 * The pcb is augmented with machine-dependent additional data for
 * core dumps. For the sun3, this includes just an exec header.
 */
struct md_coredump {
	int	md_exec[16];	/* exec structure for core dumps */
};

#endif	/* _MACHINE_PCB_H_ */
