/*	$OpenBSD: dev_hppa.h,v 1.2 1998/09/29 07:30:59 mickey Exp $	*/


#define MINIOSIZ	64		/* minimum buffer size for IODC call */
#define MAXIOSIZ	(64 * 1024)	/* maximum buffer size for IODC call */
#define IONBPG		(2 * 1024)	/* page alignment for I/O buffers */
#define IOPGSHIFT	11		/* LOG2(IONBPG) */
#define IOPGOFSET	(IONBPG-1)	/* byte offset into I/O buffer */
#define	BTIOSIZ		(8 * 1024)	/* size of boot device I/O buffer */

struct disklabel;
struct hppa_dev {
	dev_t	bootdev;
	struct pz_device *pz_dev;	/* device descriptor */
	daddr_t	last_blk;		/* byte offset for last read blk */
	size_t	last_read;		/* amount read last time */
	char	buf[BTIOSIZ+MINIOSIZ];	/* will be used for unaligned io */

	struct disklabel *label;
};

#ifdef PDCDEBUG
#define	DEVPATH_PRINT(dp) \
	printf("%x, %d.%d.%d.%d.%d.%d, 0x%x, %x.%x.%x.%x.%x.%x\n", \
	       (dp)->dp_flags, (dp)->dp_bc[0], (dp)->dp_bc[1], (dp)->dp_bc[2], \
	       (dp)->dp_bc[3], (dp)->dp_bc[4], (dp)->dp_bc[5], (dp)->dp_mod, \
	       (dp)->dp_layers[0], (dp)->dp_layers[1], (dp)->dp_layers[2], \
	       (dp)->dp_layers[3], (dp)->dp_layers[4], (dp)->dp_layers[5]);
#define	PZDEV_PRINT(dp) \
	printf("devpath={%x, %d.%d.%d.%d.%d.%d, 0x%x, %x.%x.%x.%x.%x.%x}," \
	       "\n\thpa=%p, spa=%p, io=%p, class=%u\n", \
	       (dp)->pz_flags, (dp)->pz_bc[0], (dp)->pz_bc[1], (dp)->pz_bc[2], \
	       (dp)->pz_bc[3], (dp)->pz_bc[4], (dp)->pz_bc[5], (dp)->pz_mod, \
	       (dp)->pz_layers[0], (dp)->pz_layers[1], (dp)->pz_layers[2], \
	       (dp)->pz_layers[3], (dp)->pz_layers[4], (dp)->pz_layers[5], \
	       (dp)->pz_hpa, (dp)->pz_spa, (dp)->pz_iodc_io, (dp)->pz_class);
#endif

extern pdcio_t pdc;
extern int pdcbuf[];			/* PDC returns, pdc.c */
extern struct  pz_device ctdev;		/* cartridge tape (boot) device path */

int iodc_rw __P((char *, u_int, u_int, int func, struct pz_device *));

