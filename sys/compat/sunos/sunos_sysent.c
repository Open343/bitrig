/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	OpenBSD: syscalls.master,v 1.4 1996/08/02 21:55:22 niklas Exp 
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/signal.h>
#include <sys/mount.h>
#include <sys/poll.h>
#include <sys/syscallargs.h>
#include <compat/sunos/sunos.h>
#include <compat/sunos/sunos_syscallargs.h>

#ifdef COMPAT_43
#define compat_43(func) __CONCAT(compat_43_,func)
#else
#define compat_43(func) sys_nosys
#endif

#ifdef COMPAT_09
#define compat_09(func) __CONCAT(compat_09_,func)
#else
#define compat_09(func) sys_nosys
#endif

#ifdef COMPAT_10
#define compat_10(func) __CONCAT(compat_10_,func)
#else
#define compat_10(func) sys_nosys
#endif

#define	s(type)	sizeof(type)

struct sysent sunos_sysent[] = {
	{ 0, 0,
	    sys_nosys },			/* 0 = syscall */
	{ 1, s(struct sys_exit_args),
	    sys_exit },				/* 1 = exit */
	{ 0, 0,
	    sys_fork },				/* 2 = fork */
	{ 3, s(struct sys_read_args),
	    sys_read },				/* 3 = read */
	{ 3, s(struct sys_write_args),
	    sys_write },			/* 4 = write */
	{ 3, s(struct sunos_sys_open_args),
	    sunos_sys_open },			/* 5 = open */
	{ 1, s(struct sys_close_args),
	    sys_close },			/* 6 = close */
	{ 4, s(struct sunos_sys_wait4_args),
	    sunos_sys_wait4 },			/* 7 = wait4 */
	{ 2, s(struct sunos_sys_creat_args),
	    sunos_sys_creat },			/* 8 = creat */
	{ 2, s(struct sys_link_args),
	    sys_link },				/* 9 = link */
	{ 1, s(struct sys_unlink_args),
	    sys_unlink },			/* 10 = unlink */
	{ 2, s(struct sunos_sys_execv_args),
	    sunos_sys_execv },			/* 11 = execv */
	{ 1, s(struct sys_chdir_args),
	    sys_chdir },			/* 12 = chdir */
	{ 0, 0,
	    sys_nosys },			/* 13 = obsolete time */
	{ 3, s(struct sunos_sys_mknod_args),
	    sunos_sys_mknod },			/* 14 = mknod */
	{ 2, s(struct sys_chmod_args),
	    sys_chmod },			/* 15 = chmod */
	{ 3, s(struct sys_chown_args),
	    sys_chown },			/* 16 = chown */
	{ 1, s(struct sys_obreak_args),
	    sys_obreak },			/* 17 = break */
	{ 0, 0,
	    sys_nosys },			/* 18 = obsolete stat */
	{ 3, s(struct compat_43_sys_lseek_args),
	    compat_43_sys_lseek },		/* 19 = lseek */
	{ 0, 0,
	    sys_getpid },			/* 20 = getpid */
	{ 0, 0,
	    sys_nosys },			/* 21 = obsolete sunos_old_mount */
	{ 0, 0,
	    sys_nosys },			/* 22 = unimplemented System V umount */
	{ 1, s(struct sys_setuid_args),
	    sys_setuid },			/* 23 = setuid */
	{ 0, 0,
	    sys_getuid },			/* 24 = getuid */
	{ 0, 0,
	    sys_nosys },			/* 25 = unimplemented sunos_stime */
	{ 5, s(struct sunos_sys_ptrace_args),
	    sunos_sys_ptrace },			/* 26 = ptrace */
	{ 0, 0,
	    sys_nosys },			/* 27 = unimplemented sunos_alarm */
	{ 0, 0,
	    sys_nosys },			/* 28 = unimplemented sunos_fstat */
	{ 0, 0,
	    sys_nosys },			/* 29 = unimplemented sunos_pause */
	{ 0, 0,
	    sys_nosys },			/* 30 = unimplemented sunos_utime */
	{ 0, 0,
	    sys_nosys },			/* 31 = unimplemented sunos_stty */
	{ 0, 0,
	    sys_nosys },			/* 32 = unimplemented sunos_gtty */
	{ 2, s(struct sunos_sys_access_args),
	    sunos_sys_access },			/* 33 = access */
	{ 0, 0,
	    sys_nosys },			/* 34 = unimplemented sunos_nice */
	{ 0, 0,
	    sys_nosys },			/* 35 = unimplemented sunos_ftime */
	{ 0, 0,
	    sys_sync },				/* 36 = sync */
	{ 2, s(struct sys_kill_args),
	    sys_kill },				/* 37 = kill */
	{ 2, s(struct sunos_sys_stat_args),
	    sunos_sys_stat },			/* 38 = stat */
	{ 0, 0,
	    sys_nosys },			/* 39 = unimplemented sunos_setpgrp */
	{ 2, s(struct sunos_sys_lstat_args),
	    sunos_sys_lstat },			/* 40 = lstat */
	{ 1, s(struct sys_dup_args),
	    sys_dup },				/* 41 = dup */
	{ 0, 0,
	    sys_pipe },				/* 42 = pipe */
	{ 0, 0,
	    sys_nosys },			/* 43 = unimplemented sunos_times */
	{ 4, s(struct sys_profil_args),
	    sys_profil },			/* 44 = profil */
	{ 0, 0,
	    sys_nosys },			/* 45 = unimplemented */
	{ 1, s(struct sys_setgid_args),
	    sys_setgid },			/* 46 = setgid */
	{ 0, 0,
	    sys_getgid },			/* 47 = getgid */
	{ 0, 0,
	    sys_nosys },			/* 48 = unimplemented sunos_ssig */
	{ 0, 0,
	    sys_nosys },			/* 49 = unimplemented reserved for USG */
	{ 0, 0,
	    sys_nosys },			/* 50 = unimplemented reserved for USG */
	{ 1, s(struct sys_acct_args),
	    sys_acct },				/* 51 = acct */
	{ 0, 0,
	    sys_nosys },			/* 52 = unimplemented */
	{ 4, s(struct sunos_sys_mctl_args),
	    sunos_sys_mctl },			/* 53 = mctl */
	{ 3, s(struct sunos_sys_ioctl_args),
	    sunos_sys_ioctl },			/* 54 = ioctl */
	{ 2, s(struct sunos_sys_reboot_args),
	    sunos_sys_reboot },			/* 55 = reboot */
	{ 0, 0,
	    sys_nosys },			/* 56 = obsolete sunos_owait3 */
	{ 2, s(struct sys_symlink_args),
	    sys_symlink },			/* 57 = symlink */
	{ 3, s(struct sys_readlink_args),
	    sys_readlink },			/* 58 = readlink */
	{ 3, s(struct sys_execve_args),
	    sys_execve },			/* 59 = execve */
	{ 1, s(struct sys_umask_args),
	    sys_umask },			/* 60 = umask */
	{ 1, s(struct sys_chroot_args),
	    sys_chroot },			/* 61 = chroot */
	{ 2, s(struct compat_43_sys_fstat_args),
	    compat_43_sys_fstat },		/* 62 = fstat */
	{ 0, 0,
	    sys_nosys },			/* 63 = unimplemented */
	{ 0, 0,
	    compat_43_sys_getpagesize },	/* 64 = getpagesize */
	{ 3, s(struct sunos_sys_omsync_args),
	    sunos_sys_omsync },			/* 65 = omsync */
	{ 0, 0,
	    sys_vfork },			/* 66 = vfork */
	{ 0, 0,
	    sys_nosys },			/* 67 = obsolete vread */
	{ 0, 0,
	    sys_nosys },			/* 68 = obsolete vwrite */
	{ 1, s(struct sys_sbrk_args),
	    sys_sbrk },				/* 69 = sbrk */
	{ 1, s(struct sys_sstk_args),
	    sys_sstk },				/* 70 = sstk */
	{ 6, s(struct sunos_sys_mmap_args),
	    sunos_sys_mmap },			/* 71 = mmap */
	{ 1, s(struct sys_ovadvise_args),
	    sys_ovadvise },			/* 72 = vadvise */
	{ 2, s(struct sys_munmap_args),
	    sys_munmap },			/* 73 = munmap */
	{ 3, s(struct sys_mprotect_args),
	    sys_mprotect },			/* 74 = mprotect */
	{ 3, s(struct sys_madvise_args),
	    sys_madvise },			/* 75 = madvise */
	{ 0, 0,
	    sunos_sys_vhangup },		/* 76 = vhangup */
	{ 0, 0,
	    sys_nosys },			/* 77 = unimplemented vlimit */
	{ 3, s(struct sys_mincore_args),
	    sys_mincore },			/* 78 = mincore */
	{ 2, s(struct sys_getgroups_args),
	    sys_getgroups },			/* 79 = getgroups */
	{ 2, s(struct sys_setgroups_args),
	    sys_setgroups },			/* 80 = setgroups */
	{ 0, 0,
	    sys_getpgrp },			/* 81 = getpgrp */
	{ 2, s(struct sunos_sys_setpgrp_args),
	    sunos_sys_setpgrp },		/* 82 = setpgrp */
	{ 3, s(struct sys_setitimer_args),
	    sys_setitimer },			/* 83 = setitimer */
	{ 0, 0,
	    sys_nosys },			/* 84 = unimplemented { int sunos_sys_wait ( void ) ; } */
	{ 1, s(struct sys_swapon_args),
	    sys_swapon },			/* 85 = swapon */
	{ 2, s(struct sys_getitimer_args),
	    sys_getitimer },			/* 86 = getitimer */
	{ 2, s(struct compat_43_sys_gethostname_args),
	    compat_43_sys_gethostname },	/* 87 = gethostname */
	{ 2, s(struct compat_43_sys_sethostname_args),
	    compat_43_sys_sethostname },	/* 88 = sethostname */
	{ 0, 0,
	    compat_43_sys_getdtablesize },	/* 89 = getdtablesize */
	{ 2, s(struct sys_dup2_args),
	    sys_dup2 },				/* 90 = dup2 */
	{ 0, 0,
	    sys_nosys },			/* 91 = unimplemented getdopt */
	{ 3, s(struct sunos_sys_fcntl_args),
	    sunos_sys_fcntl },			/* 92 = fcntl */
	{ 5, s(struct sys_select_args),
	    sys_select },			/* 93 = select */
	{ 0, 0,
	    sys_nosys },			/* 94 = unimplemented setdopt */
	{ 1, s(struct sys_fsync_args),
	    sys_fsync },			/* 95 = fsync */
	{ 3, s(struct sys_setpriority_args),
	    sys_setpriority },			/* 96 = setpriority */
	{ 3, s(struct sys_socket_args),
	    sys_socket },			/* 97 = socket */
	{ 3, s(struct sys_connect_args),
	    sys_connect },			/* 98 = connect */
	{ 3, s(struct compat_43_sys_accept_args),
	    compat_43_sys_accept },		/* 99 = accept */
	{ 2, s(struct sys_getpriority_args),
	    sys_getpriority },			/* 100 = getpriority */
	{ 4, s(struct compat_43_sys_send_args),
	    compat_43_sys_send },		/* 101 = send */
	{ 4, s(struct compat_43_sys_recv_args),
	    compat_43_sys_recv },		/* 102 = recv */
	{ 0, 0,
	    sys_nosys },			/* 103 = unimplemented old socketaddr */
	{ 3, s(struct sys_bind_args),
	    sys_bind },				/* 104 = bind */
	{ 5, s(struct sunos_sys_setsockopt_args),
	    sunos_sys_setsockopt },		/* 105 = setsockopt */
	{ 2, s(struct sys_listen_args),
	    sys_listen },			/* 106 = listen */
	{ 0, 0,
	    sys_nosys },			/* 107 = unimplemented vtimes */
	{ 3, s(struct sunos_sys_sigvec_args),
	    sunos_sys_sigvec },			/* 108 = sigvec */
	{ 1, s(struct compat_43_sys_sigblock_args),
	    compat_43_sys_sigblock },		/* 109 = sigblock */
	{ 1, s(struct compat_43_sys_sigsetmask_args),
	    compat_43_sys_sigsetmask },		/* 110 = sigsetmask */
	{ 1, s(struct sys_sigsuspend_args),
	    sys_sigsuspend },			/* 111 = sigsuspend */
	{ 2, s(struct compat_43_sys_sigstack_args),
	    compat_43_sys_sigstack },		/* 112 = sigstack */
	{ 3, s(struct compat_43_sys_recvmsg_args),
	    compat_43_sys_recvmsg },		/* 113 = recvmsg */
	{ 3, s(struct compat_43_sys_sendmsg_args),
	    compat_43_sys_sendmsg },		/* 114 = sendmsg */
	{ 0, 0,
	    sys_nosys },			/* 115 = obsolete vtrace */
	{ 2, s(struct sys_gettimeofday_args),
	    sys_gettimeofday },			/* 116 = gettimeofday */
	{ 2, s(struct sys_getrusage_args),
	    sys_getrusage },			/* 117 = getrusage */
	{ 5, s(struct sys_getsockopt_args),
	    sys_getsockopt },			/* 118 = getsockopt */
	{ 0, 0,
	    sys_nosys },			/* 119 = unimplemented */
	{ 3, s(struct sys_readv_args),
	    sys_readv },			/* 120 = readv */
	{ 3, s(struct sys_writev_args),
	    sys_writev },			/* 121 = writev */
	{ 2, s(struct sys_settimeofday_args),
	    sys_settimeofday },			/* 122 = settimeofday */
	{ 3, s(struct sys_fchown_args),
	    sys_fchown },			/* 123 = fchown */
	{ 2, s(struct sys_fchmod_args),
	    sys_fchmod },			/* 124 = fchmod */
	{ 6, s(struct compat_43_sys_recvfrom_args),
	    compat_43_sys_recvfrom },		/* 125 = recvfrom */
	{ 2, s(struct compat_43_sys_setreuid_args),
	    compat_43_sys_setreuid },		/* 126 = setreuid */
	{ 2, s(struct compat_43_sys_setregid_args),
	    compat_43_sys_setregid },		/* 127 = setregid */
	{ 2, s(struct sys_rename_args),
	    sys_rename },			/* 128 = rename */
	{ 2, s(struct compat_43_sys_truncate_args),
	    compat_43_sys_truncate },		/* 129 = truncate */
	{ 2, s(struct compat_43_sys_ftruncate_args),
	    compat_43_sys_ftruncate },		/* 130 = ftruncate */
	{ 2, s(struct sys_flock_args),
	    sys_flock },			/* 131 = flock */
	{ 0, 0,
	    sys_nosys },			/* 132 = unimplemented */
	{ 6, s(struct sys_sendto_args),
	    sys_sendto },			/* 133 = sendto */
	{ 2, s(struct sys_shutdown_args),
	    sys_shutdown },			/* 134 = shutdown */
	{ 4, s(struct sys_socketpair_args),
	    sys_socketpair },			/* 135 = socketpair */
	{ 2, s(struct sys_mkdir_args),
	    sys_mkdir },			/* 136 = mkdir */
	{ 1, s(struct sys_rmdir_args),
	    sys_rmdir },			/* 137 = rmdir */
	{ 2, s(struct sys_utimes_args),
	    sys_utimes },			/* 138 = utimes */
	{ 1, s(struct sunos_sys_sigreturn_args),
	    sunos_sys_sigreturn },		/* 139 = sigreturn */
	{ 2, s(struct sys_adjtime_args),
	    sys_adjtime },			/* 140 = adjtime */
	{ 3, s(struct compat_43_sys_getpeername_args),
	    compat_43_sys_getpeername },	/* 141 = getpeername */
	{ 0, 0,
	    compat_43_sys_gethostid },		/* 142 = gethostid */
	{ 0, 0,
	    sys_nosys },			/* 143 = unimplemented old sethostid */
	{ 2, s(struct sunos_sys_getrlimit_args),
	    sunos_sys_getrlimit },		/* 144 = getrlimit */
	{ 2, s(struct sunos_sys_setrlimit_args),
	    sunos_sys_setrlimit },		/* 145 = setrlimit */
	{ 2, s(struct compat_43_sys_killpg_args),
	    compat_43_sys_killpg },		/* 146 = killpg */
	{ 0, 0,
	    sys_nosys },			/* 147 = unimplemented */
	{ 0, 0,
	    sys_nosys },			/* 148 = unimplemented */
	{ 0, 0,
	    sys_nosys },			/* 149 = unimplemented */
	{ 3, s(struct compat_43_sys_getsockname_args),
	    compat_43_sys_getsockname },	/* 150 = getsockname */
	{ 0, 0,
	    sys_nosys },			/* 151 = unimplemented getmsg */
	{ 0, 0,
	    sys_nosys },			/* 152 = unimplemented putmsg */
	{ 3, s(struct sys_poll_args),
	    sys_poll },				/* 153 = poll */
	{ 0, 0,
	    sys_nosys },			/* 154 = unimplemented */
#ifdef NFSSERVER
	{ 1, s(struct sunos_sys_nfssvc_args),
	    sunos_sys_nfssvc },			/* 155 = nfssvc */
#else
	{ 0, 0,
	    sys_nosys },			/* 155 = unimplemented */
#endif
	{ 4, s(struct sys_getdirentries_args),
	    sys_getdirentries },		/* 156 = getdirentries */
	{ 2, s(struct sunos_sys_statfs_args),
	    sunos_sys_statfs },			/* 157 = statfs */
	{ 2, s(struct sunos_sys_fstatfs_args),
	    sunos_sys_fstatfs },		/* 158 = fstatfs */
	{ 1, s(struct sunos_sys_unmount_args),
	    sunos_sys_unmount },		/* 159 = unmount */
#ifdef NFSCLIENT
	{ 0, 0,
	    async_daemon },			/* 160 = async_daemon */
	{ 2, s(struct sys_getfh_args),
	    sys_getfh },			/* 161 = getfh */
#else
	{ 0, 0,
	    sys_nosys },			/* 160 = unimplemented */
	{ 0, 0,
	    sys_nosys },			/* 161 = unimplemented */
#endif
	{ 2, s(struct compat_09_sys_getdomainname_args),
	    compat_09_sys_getdomainname },	/* 162 = getdomainname */
	{ 2, s(struct compat_09_sys_setdomainname_args),
	    compat_09_sys_setdomainname },	/* 163 = setdomainname */
	{ 0, 0,
	    sys_nosys },			/* 164 = unimplemented rtschedule */
	{ 4, s(struct sunos_sys_quotactl_args),
	    sunos_sys_quotactl },		/* 165 = quotactl */
	{ 2, s(struct sunos_sys_exportfs_args),
	    sunos_sys_exportfs },		/* 166 = exportfs */
	{ 4, s(struct sunos_sys_mount_args),
	    sunos_sys_mount },			/* 167 = mount */
	{ 2, s(struct sunos_sys_ustat_args),
	    sunos_sys_ustat },			/* 168 = ustat */
#ifdef SYSVSEM
	{ 5, s(struct compat_10_sys_semsys_args),
	    compat_10_sys_semsys },		/* 169 = semsys */
#else
	{ 0, 0,
	    sys_nosys },			/* 169 = unimplemented semsys */
#endif
#ifdef SYSVMSG
	{ 6, s(struct compat_10_sys_msgsys_args),
	    compat_10_sys_msgsys },		/* 170 = msgsys */
#else
	{ 0, 0,
	    sys_nosys },			/* 170 = unimplemented msgsys */
#endif
#ifdef SYSVSHM
	{ 4, s(struct compat_10_sys_shmsys_args),
	    compat_10_sys_shmsys },		/* 171 = shmsys */
#else
	{ 0, 0,
	    sys_nosys },			/* 171 = unimplemented shmsys */
#endif
	{ 1, s(struct sunos_sys_auditsys_args),
	    sunos_sys_auditsys },		/* 172 = auditsys */
	{ 0, 0,
	    sys_nosys },			/* 173 = unimplemented rfssys */
	{ 3, s(struct sunos_sys_getdents_args),
	    sunos_sys_getdents },		/* 174 = getdents */
	{ 0, 0,
	    sys_setsid },			/* 175 = setsid */
	{ 1, s(struct sys_fchdir_args),
	    sys_fchdir },			/* 176 = fchdir */
	{ 1, s(struct sunos_sys_fchroot_args),
	    sunos_sys_fchroot },		/* 177 = fchroot */
	{ 0, 0,
	    sys_nosys },			/* 178 = unimplemented vpixsys */
	{ 0, 0,
	    sys_nosys },			/* 179 = unimplemented aioread */
	{ 0, 0,
	    sys_nosys },			/* 180 = unimplemented aiowrite */
	{ 0, 0,
	    sys_nosys },			/* 181 = unimplemented aiowait */
	{ 0, 0,
	    sys_nosys },			/* 182 = unimplemented aiocancel */
	{ 1, s(struct sunos_sys_sigpending_args),
	    sunos_sys_sigpending },		/* 183 = sigpending */
	{ 0, 0,
	    sys_nosys },			/* 184 = unimplemented */
	{ 2, s(struct sys_setpgid_args),
	    sys_setpgid },			/* 185 = setpgid */
	{ 2, s(struct sys_pathconf_args),
	    sys_pathconf },			/* 186 = pathconf */
	{ 2, s(struct sys_fpathconf_args),
	    sys_fpathconf },			/* 187 = fpathconf */
	{ 1, s(struct sunos_sys_sysconf_args),
	    sunos_sys_sysconf },		/* 188 = sysconf */
	{ 1, s(struct sunos_sys_uname_args),
	    sunos_sys_uname },			/* 189 = uname */
};

