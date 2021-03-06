/*	$OpenBSD: armreg.h,v 1.16 2015/05/29 05:48:07 jsg Exp $	*/
/*	$NetBSD: armreg.h,v 1.27 2003/09/06 08:43:02 rearnsha Exp $	*/

/*
 * Copyright (c) 1998, 2001 Ben Harris
 * Copyright (c) 1994-1996 Mark Brinicombe.
 * Copyright (c) 1994 Brini.
 * All rights reserved.
 *
 * This code is derived from software written for Brini by Mark Brinicombe
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
 *	This product includes software developed by Brini.
 * 4. The name of the company nor the name of the author may be used to
 *    endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _ARM_ARMREG_H
#define _ARM_ARMREG_H

/*
 * ARM Process Status Register
 *
 * The picture in the ARM manuals looks like this:
 *       3 3 2 2 2 2 2 2 2     2 1     1 1         1
 *       1 0 9 8 7 6 5 4 3     0 9     6 5         0 9 8 7 6 5 4       0
 *      +-+-+-+-+-+---+-+-------+-------+-----------+-+-+-+-+-+---------+
 *      |N|Z|C|V|Q|I I|J|reserv-|G G G G|I I I I I I|E|A|I|F|T|M M M M M|
 *      | | | | | |T T| |ed     |E E E E|T T T T T T| | | | | |         |
 *      | | | | | |1 0| |       |3 2 1 0|7 6 5 4 3 2| | | | | |4 3 2 1 0|
 *      +-+-+-+-+-+---+-+-------+-------+-----------+-+-+-+-+-+---------+
 *      | flags 'f'     | status 's'    | extension 'x' | control 'c'   |
 */

#define PSR_FLAGS 0xf0000000	/* flags */
#define PSR_N_bit (1U << 31)	/* negative */
#define PSR_Z_bit (1 << 30)	/* zero */
#define PSR_C_bit (1 << 29)	/* carry */
#define PSR_V_bit (1 << 28)	/* overflow */
#define PSR_Q_bit (1 << 27)	/* sticky overflow */
#define PSR_J_bit (1 << 24)	/* Java mode */
#define PSR_E_bit (1 << 9)	/* Data endianness */
#define PSR_A_bit (1 << 8)	/* Imprecise data abort disable */

#define A32_bit (1 << 8)	/* Asynchronous abort disable */
#define I32_bit (1 << 7)	/* IRQ disable */
#define F32_bit (1 << 6)	/* FIQ disable */

#define PSR_T_bit (1 << 5)	/* Thumb state */

#define PSR_MODE	0x0000001f	/* mode mask */
#define PSR_USR26_MODE	0x00000000
#define PSR_FIQ26_MODE	0x00000001
#define PSR_IRQ26_MODE	0x00000002
#define PSR_SVC26_MODE	0x00000003
#define PSR_USR32_MODE	0x00000010
#define PSR_FIQ32_MODE	0x00000011
#define PSR_IRQ32_MODE	0x00000012
#define PSR_SVC32_MODE	0x00000013
#define PSR_MON32_MODE	0x00000016
#define PSR_ABT32_MODE	0x00000017
#define PSR_HYP32_MODE	0x0000001a
#define PSR_UND32_MODE	0x0000001b
#define PSR_SYS32_MODE	0x0000001f
#define PSR_32_MODE	0x00000010

#define PSR_IN_USR_MODE(psr)	(!((psr) & 3))		/* XXX */

/*
 * Co-processor 15:  The system control co-processor.
 */

#define ARM_CP15_CPU_ID		0

/*
 * The CPU ID register is theoretically structured, but the definitions of
 * the fields keep changing.
 */

/* The high-order byte is always the implementor */
#define CPU_ID_IMPLEMENTOR_MASK	0xff000000
#define CPU_ID_ARM_LTD		0x41000000 /* 'A' */
#define CPU_ID_DEC		0x44000000 /* 'D' */
#define CPU_ID_INTEL		0x69000000 /* 'i' */
#define CPU_ID_TI		0x54000000 /* 'T' */

/* How to decide what format the CPUID is in. */
#define CPU_ID_ISOLD(x)		(((x) & 0x0000f000) == 0x00000000)
#define CPU_ID_IS7(x)		(((x) & 0x0000f000) == 0x00007000)
#define CPU_ID_ISNEW(x)		(!CPU_ID_ISOLD(x) && !CPU_ID_IS7(x))

/* On ARM3 and ARM6, this byte holds the foundry ID. */
#define CPU_ID_FOUNDRY_MASK	0x00ff0000
#define CPU_ID_FOUNDRY_VLSI	0x00560000

/* On ARM7 it holds the architecture and variant (sub-model) */
#define CPU_ID_7ARCH_MASK	0x00800000
#define CPU_ID_7ARCH_V3		0x00000000
#define CPU_ID_7ARCH_V4T	0x00800000
#define CPU_ID_7VARIANT_MASK	0x007f0000

/* On more recent ARMs, it does the same, but in a different format */
#define CPU_ID_ARCH_MASK	0x000f0000
#define CPU_ID_ARCH_V3		0x00000000
#define CPU_ID_ARCH_V4		0x00010000
#define CPU_ID_ARCH_V4T		0x00020000
#define CPU_ID_ARCH_V5		0x00030000
#define CPU_ID_ARCH_V5T		0x00040000
#define CPU_ID_ARCH_V5TE	0x00050000
#define CPU_ID_ARCH_V6		0x00070000
#define CPU_ID_ARCH_V7		0x00080000
#define CPU_ID_VARIANT_MASK	0x00f00000

/* Next three nybbles are part number */
#define CPU_ID_PARTNO_MASK	0x0000fff0

/* And finally, the revision number. */
#define CPU_ID_REVISION_MASK	0x0000000f

/* Individual CPUs are probably best IDed by everything but the revision. */
#define CPU_ID_CPU_MASK		0xfffffff0

/* Post-ARM7 CPUs */
#define CPU_ID_CORTEX_A5	0x410fc050
#define CPU_ID_CORTEX_A5_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A7	0x410fc070
#define CPU_ID_CORTEX_A7_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A8_R1	0x411fc080
#define CPU_ID_CORTEX_A8_R2	0x412fc080
#define CPU_ID_CORTEX_A8_R3	0x413fc080
#define CPU_ID_CORTEX_A8	0x410fc080
#define CPU_ID_CORTEX_A8_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A9	0x410fc090
#define CPU_ID_CORTEX_A9_R1	0x411fc090
#define CPU_ID_CORTEX_A9_R2	0x412fc090
#define CPU_ID_CORTEX_A9_R3	0x413fc090
#define CPU_ID_CORTEX_A9_R4	0x414fc090
#define CPU_ID_CORTEX_A9_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A15	0x410fc0f0
#define CPU_ID_CORTEX_A15_R1	0x411fc0f0
#define CPU_ID_CORTEX_A15_R2	0x412fc0f0
#define CPU_ID_CORTEX_A15_R3	0x413fc0f0
#define CPU_ID_CORTEX_A15_R4	0x414fc0f0
#define CPU_ID_CORTEX_A15_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A17	0x410fc0e0
#define CPU_ID_CORTEX_A17_R1	0x411fc0e0
#define CPU_ID_CORTEX_A17_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A53	0x410fd030
#define CPU_ID_CORTEX_A53_R1	0x411fd030
#define CPU_ID_CORTEX_A53_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A57	0x410fd070
#define CPU_ID_CORTEX_A57_R1	0x411fd070
#define CPU_ID_CORTEX_A57_MASK	0xff0ffff0
#define CPU_ID_CORTEX_A72	0x410fd080
#define CPU_ID_CORTEX_A72_R1	0x411fd080
#define CPU_ID_CORTEX_A57_MASK	0xff0ffff0
#define CPU_ID_MV88SV58XX_P(n)	((n & 0xff0fff00) == 0x560f5800)
#define CPU_ID_MV88SV581X_V6	0x560f5810 /* Marvell Sheeva 88SV581x v6 Core */
#define CPU_ID_MV88SV581X_V7	0x561f5810 /* Marvell Sheeva 88SV581x v7 Core */
#define CPU_ID_MV88SV584X_V6	0x561f5840 /* Marvell Sheeva 88SV584x v6 Core */
#define CPU_ID_MV88SV584X_V7	0x562f5840 /* Marvell Sheeva 88SV584x v7 Core */
/* Marvell's CPUIDs with ARM ID in implementor field */
#define CPU_ID_ARM_88SV581X_V6	0x410fb760 /* Marvell Sheeva 88SV581x v6 Core */
#define CPU_ID_ARM_88SV581X_V7	0x413fc080 /* Marvell Sheeva 88SV581x v7 Core */
#define CPU_ID_ARM_88SV584X_V6	0x410fb020 /* Marvell Sheeva 88SV584x v6 Core */

/* ARM3-specific coprocessor 15 registers */
#define ARM3_CP15_FLUSH		1
#define ARM3_CP15_CONTROL	2
#define ARM3_CP15_CACHEABLE	3
#define ARM3_CP15_UPDATEABLE	4
#define ARM3_CP15_DISRUPTIVE	5	

/* ARM3 Control register bits */
#define ARM3_CTL_CACHE_ON	0x00000001
#define ARM3_CTL_SHARED		0x00000002
#define ARM3_CTL_MONITOR	0x00000004

/*
 * Post-ARM3 CP15 registers:
 *
 *	1	Control register
 *
 *	2	Translation Table Base
 *
 *	3	Domain Access Control
 *
 *	4	Reserved
 *
 *	5	Fault Status
 *
 *	6	Fault Address
 *
 *	7	Cache/write-buffer Control
 *
 *	8	TLB Control
 *
 *	9	Cache Lockdown
 *
 *	10	TLB Lockdown
 *
 *	11	Reserved
 *
 *	12	Reserved
 *
 *	13	Process ID (for FCSE)
 *
 *	14	Reserved
 *
 *	15	Implementation Dependent
 */

/* Some of the definitions below need cleaning up for V3/V4 architectures */

/* CPU control register (CP15 register 1) */
#define CPU_CONTROL_MMU_ENABLE	0x00000001 /* M: MMU/Protection unit enable */
#define CPU_CONTROL_AFLT_ENABLE	0x00000002 /* A: Alignment fault enable */
#define CPU_CONTROL_DC_ENABLE	0x00000004 /* C: IDC/DC enable */
#define CPU_CONTROL_WBUF_ENABLE 0x00000008 /* W: Write buffer enable */
#define CPU_CONTROL_32BP_ENABLE 0x00000010 /* P: 32-bit exception handlers */
#define CPU_CONTROL_32BD_ENABLE 0x00000020 /* D: 32-bit addressing */
#define CPU_CONTROL_LABT_ENABLE 0x00000040 /* L: Late abort enable */
#define CPU_CONTROL_BEND_ENABLE 0x00000080 /* B: Big-endian mode */
#define CPU_CONTROL_SYST_ENABLE 0x00000100 /* S: System protection bit */
#define CPU_CONTROL_ROM_ENABLE	0x00000200 /* R: ROM protection bit */
#define CPU_CONTROL_CPCLK	0x00000400 /* F: Implementation defined */
#define CPU_CONTROL_BPRD_ENABLE 0x00000800 /* Z: Branch prediction enable */
#define CPU_CONTROL_IC_ENABLE   0x00001000 /* I: IC enable */
#define CPU_CONTROL_VECRELOC	0x00002000 /* V: Vector relocation */
#define CPU_CONTROL_ROUNDROBIN	0x00004000 /* RR: Predictable replacement */
#define CPU_CONTROL_V4COMPAT	0x00008000 /* L4: ARMv4 compat LDR R15 etc */

/* below were added by V6 */
#define CPU_CONTROL_FI		(1<<21) /* FI: fast interrupts */
#define CPU_CONTROL_U		(1<<22) /* U: Unaligned */
#define CPU_CONTROL_XP		(1<<23) /* XP: extended page table */
#define CPU_CONTROL_VE		(1<<24) /* VE: Vector enable */
#define CPU_CONTROL_EE		(1<<25) /* EE: Exception Endianness */
#define CPU_CONTROL_L2		(1<<25) /* L2: L2 cache enable */

/* added with v7 */
#define CPU_CONTROL_NMFI	(1<<27) /* NMFI: Non Maskable fast interrupt */ 
#define CPU_CONTROL_TRE		(1<<28) /* TRE: TEX Remap Enable */
#define CPU_CONTROL_AFE		(1<<29) /* AFE: Access Flag Enable */
#define CPU_CONTROL_TE		(1<<30) /* TE: Thumb Exception Enable */

#define CPU_CONTROL_IDC_ENABLE	CPU_CONTROL_DC_ENABLE

/* Cortex-A9 Auxillary Control Register (CP15 register 1, ocode2 1) */
#define CORTEX_A9_AUXCTL_FW			0x00000001
#define CORTEX_A9_AUXCTL_L1_PREFETCH_ENABLE	0x00000002
#define CORTEX_A9_AUXCTL_L2_PREFETCH_ENABLE	0x00000004
#define CORTEX_A9_AUXCTL_SMP			0x00000040

/* Cache type register definitions */
#define CPU_CT_ISIZE(x)		((x) & 0xfff)		/* I$ info */
#define CPU_CT_DSIZE(x)		(((x) >> 12) & 0xfff)	/* D$ info */
#define CPU_CT_S		(1U << 24)		/* split cache */
#define CPU_CT_CTYPE(x)		(((x) >> 25) & 0xf)	/* cache type */
/* Cache type register definitions for ARM v7 */
#define CPU_CT_IMINLINE(x)	((x) & 0xf)		/* I$ min line size */
#define CPU_CT_DMINLINE(x)	(((x) >> 16) & 0xf)	/* D$ min line size */

#define CPU_CT_CTYPE_WT		0	/* write-through */
#define CPU_CT_CTYPE_WB1	1	/* write-back, clean w/ read */
#define CPU_CT_CTYPE_WB2	2	/* w/b, clean w/ cp15,7 */
#define CPU_CT_CTYPE_WB6	6	/* w/b, cp15,7, lockdown fmt A */
#define CPU_CT_CTYPE_WB7	7	/* w/b, cp15,7, lockdown fmt B */

#define CPU_CT_xSIZE_LEN(x)	((x) & 0x3)		/* line size */
#define CPU_CT_xSIZE_M		(1U << 2)		/* multiplier */
#define CPU_CT_xSIZE_ASSOC(x)	(((x) >> 3) & 0x7)	/* associativity */
#define CPU_CT_xSIZE_SIZE(x)	(((x) >> 6) & 0x7)	/* size */

#define CPU_CT_ARMV7		0x4
/* ARM v7 Cache type definitions */
#define CPUV7_CT_CTYPE_WT	(1U << 31)
#define CPUV7_CT_CTYPE_WB	(1 << 30)
#define CPUV7_CT_CTYPE_RA	(1 << 29)
#define CPUV7_CT_CTYPE_WA	(1 << 28)

#define CPUV7_CT_xSIZE_LEN(x)	((x) & 0x7)		/* line size */
#define CPUV7_CT_xSIZE_ASSOC(x)	(((x) >> 3) & 0x3ff)	/* associativity */
#define CPUV7_CT_xSIZE_SET(x)	(((x) >> 13) & 0x7fff)	/* num sets */

#define CPU_CLIDR_CTYPE(reg,x)	(((reg) >> ((x) * 3)) & 0x7)
#define CPU_CLIDR_LOUIS(reg)	(((reg) >> 21) & 0x7)
#define CPU_CLIDR_LOC(reg)	(((reg) >> 24) & 0x7)
#define CPU_CLIDR_LOUU(reg)	(((reg) >> 27) & 0x7)

#define CACHE_ICACHE		1
#define CACHE_DCACHE		2
#define CACHE_SEP_CACHE		3
#define CACHE_UNI_CACHE		4

/* Fault status register definitions */

#define FAULT_USER      0x20

#define FAULT_WRTBUF_0  0x00 /* Vector Exception */
#define FAULT_WRTBUF_1  0x02 /* Terminal Exception */
#define FAULT_BUSERR_0  0x04 /* External Abort on Linefetch -- Section */
#define FAULT_BUSERR_1  0x06 /* External Abort on Linefetch -- Page */
#define FAULT_BUSERR_2  0x08 /* External Abort on Non-linefetch -- Section */
#define FAULT_BUSERR_3  0x0a /* External Abort on Non-linefetch -- Page */
#define FAULT_BUSTRNL1  0x0c /* External abort on Translation -- Level 1 */
#define FAULT_BUSTRNL2  0x0e /* External abort on Translation -- Level 2 */
#define FAULT_ALIGN_0   0x01 /* Alignment */
#define FAULT_ALIGN_1   0x03 /* Alignment */
#define FAULT_TRANS_S   0x05 /* Translation -- Section */
#define FAULT_TRANS_P   0x07 /* Translation -- Page */
#define FAULT_DOMAIN_S  0x09 /* Domain -- Section */
#define FAULT_DOMAIN_P  0x0b /* Domain -- Page */
#define FAULT_PERM_S    0x0d /* Permission -- Section */
#define FAULT_PERM_P    0x0f /* Permission -- Page */

#define	FAULT_EXT	0x00001000	/* external abort */
#define	FAULT_WNR	0x00000800	/* write fault */

#define	FAULT_TYPE(fsr)		(((fsr) & 0x0f) | (((fsr) & 0x00000400) >> 6))

/*
 * Address of the vector page, low and high versions.
 */
#define ARM_VECTORS_LOW		0x00000000U
#define ARM_VECTORS_HIGH	0xffff0000U

/*
 * ARM Instructions
 *
 *       3 3 2 2 2                              
 *       1 0 9 8 7                                                     0
 *      +-------+-------------------------------------------------------+
 *      | cond  |              instruction dependant                    |
 *      |c c c c|                                                       |
 *      +-------+-------------------------------------------------------+
 */

#define INSN_SIZE		4		/* Always 4 bytes */
#define INSN_COND_MASK		0xf0000000	/* Condition mask */
#define INSN_COND_AL		0xe0000000	/* Always condition */

#endif
