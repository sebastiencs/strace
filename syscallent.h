/* J'ai trouvé ca dans les sources de strace  - seb */

[  0] = { 3,	TD,		sys_read,			"read"			},
[  1] = { 3,	TD,		sys_write,			"write"			},
[  2] = { 3,	TD|TF,		sys_open,			"open"			},
[  3] = { 1,	TD,		sys_close,			"close"			},
[  4] = { 2,	TF,		sys_stat,			"stat"			},
[  5] = { 2,	TD,		sys_fstat,			"fstat"			},
[  6] = { 2,	TF,		sys_lstat,			"lstat"			},
[  7] = { 3,	TD,		sys_poll,			"poll"			},
[  8] = { 3,	TD,		sys_lseek,			"lseek"			},
[  9] = { 6,	TD|TM|SI,	sys_mmap,			"mmap"			},
[ 10] = { 3,	TM|SI,		sys_mprotect,			"mprotect"		},
[ 11] = { 2,	TM|SI,		sys_munmap,			"munmap"		},
[ 12] = { 1,	TM|SI,		sys_brk,			"brk"			},
[ 13] = { 4,	TS,		sys_rt_sigaction,		"rt_sigaction"		},
[ 14] = { 4,	TS,		sys_rt_sigprocmask,		"rt_sigprocmask"	},
[ 15] = { 0,	TS,		sys_sigreturn,			"rt_sigreturn"		},
[ 16] = { 3,	TD,		sys_ioctl,			"ioctl"			},
[ 17] = { 4,	TD,		sys_pread,			"pread"			},
[ 18] = { 4,	TD,		sys_pwrite,			"pwrite"		},
[ 19] = { 3,	TD,		sys_readv,			"readv"			},
[ 20] = { 3,	TD,		sys_writev,			"writev"		},
[ 21] = { 2,	TF,		sys_access,			"access"		},
[ 22] = { 1,	TD,		sys_pipe,			"pipe"			},
[ 23] = { 5,	TD,		sys_select,			"select"		},
[ 24] = { 0,	0,		sys_sched_yield,		"sched_yield"		},
[ 25] = { 5,	TM|SI,		sys_mremap,			"mremap"		},
[ 26] = { 3,	TM,		sys_msync,			"msync"			},
[ 27] = { 3,	TM,		sys_mincore,			"mincore"		},
[ 28] = { 3,	TM,		sys_madvise,			"madvise"		},
[ 29] = { 3,	TI,		sys_shmget,			"shmget"		},
[ 30] = { 3,	TI|TM|SI,	sys_shmat,			"shmat"			},
[ 31] = { 3,	TI,		sys_shmctl,			"shmctl"		},
[ 32] = { 1,	TD,		sys_dup,			"dup"			},
[ 33] = { 2,	TD,		sys_dup2,			"dup2"			},
[ 34] = { 0,	TS,		sys_pause,			"pause"			},
[ 35] = { 2,	0,		sys_nanosleep,			"nanosleep"		},
[ 36] = { 2,	0,		sys_getitimer,			"getitimer"		},
[ 37] = { 1,	0,		sys_alarm,			"alarm"			},
[ 38] = { 3,	0,		sys_setitimer,			"setitimer"		},
[ 39] = { 0,	0,		sys_getpid,			"getpid"		},
[ 40] = { 4,	TD|TN,		sys_sendfile64,			"sendfile"		},
[ 41] = { 3,	TN,		sys_socket,			"socket"		},
[ 42] = { 3,	TN,		sys_connect,			"connect"		},
[ 43] = { 3,	TN,		sys_accept,			"accept"		},
[ 44] = { 6,	TN,		sys_sendto,			"sendto"		},
[ 45] = { 6,	TN,		sys_recvfrom,			"recvfrom"		},
[ 46] = { 3,	TN,		sys_sendmsg,			"sendmsg"		},
[ 47] = { 3,	TN,		sys_recvmsg,			"recvmsg"		},
[ 48] = { 2,	TN,		sys_shutdown,			"shutdown"		},
[ 49] = { 3,	TN,		sys_bind,			"bind"			},
[ 50] = { 2,	TN,		sys_listen,			"listen"		},
[ 51] = { 3,	TN,		sys_getsockname,		"getsockname"		},
[ 52] = { 3,	TN,		sys_getpeername,		"getpeername"		},
[ 53] = { 4,	TN,		sys_socketpair,			"socketpair"		},
[ 54] = { 5,	TN,		sys_setsockopt,			"setsockopt"		},
[ 55] = { 5,	TN,		sys_getsockopt,			"getsockopt"		},
[ 56] = { 5,	TP,		sys_clone,			"clone"			},
[ 57] = { 0,	TP,		sys_fork,			"fork"			},
[ 58] = { 0,	TP,		sys_vfork,			"vfork"			},
[ 59] = { 3,	TF|TP|SE|SI,	sys_execve,			"execve"		},
[ 60] = { 1,	TP|SE,		sys_exit,			"_exit"			},
[ 61] = { 4,	TP,		sys_wait4,			"wait4"			},
[ 62] = { 2,	TS,		sys_kill,			"kill"			},
[ 63] = { 1,	0,		sys_uname,			"uname"			},
[ 64] = { 3,	TI,		sys_semget,			"semget"		},
[ 65] = { 3,	TI,		sys_semop,			"semop"			},
[ 66] = { 4,	TI,		sys_semctl,			"semctl"		},
[ 67] = { 1,	TI|TM|SI,	sys_shmdt,			"shmdt"			},
[ 68] = { 2,	TI,		sys_msgget,			"msgget"		},
[ 69] = { 4,	TI,		sys_msgsnd,			"msgsnd"		},
[ 70] = { 5,	TI,		sys_msgrcv,			"msgrcv"		},
[ 71] = { 3,	TI,		sys_msgctl,			"msgctl"		},
[ 72] = { 3,	TD,		sys_fcntl,			"fcntl"			},
[ 73] = { 2,	TD,		sys_flock,			"flock"			},
[ 74] = { 1,	TD,		sys_fsync,			"fsync"			},
[ 75] = { 1,	TD,		sys_fdatasync,			"fdatasync"		},
[ 76] = { 2,	TF,		sys_truncate,			"truncate"		},
[ 77] = { 2,	TD,		sys_ftruncate,			"ftruncate"		},
[ 78] = { 3,	TD,		sys_getdents,			"getdents"		},
[ 79] = { 2,	TF,		sys_getcwd,			"getcwd"		},
[ 80] = { 1,	TF,		sys_chdir,			"chdir"			},
[ 81] = { 1,	TD,		sys_fchdir,			"fchdir"		},
[ 82] = { 2,	TF,		sys_rename,			"rename"		},
[ 83] = { 2,	TF,		sys_mkdir,			"mkdir"			},
[ 84] = { 1,	TF,		sys_rmdir,			"rmdir"			},
[ 85] = { 2,	TD|TF,		sys_creat,			"creat"			},
[ 86] = { 2,	TF,		sys_link,			"link"			},
[ 87] = { 1,	TF,		sys_unlink,			"unlink"		},
[ 88] = { 2,	TF,		sys_symlink,			"symlink"		},
[ 89] = { 3,	TF,		sys_readlink,			"readlink"		},
[ 90] = { 2,	TF,		sys_chmod,			"chmod"			},
[ 91] = { 2,	TD,		sys_fchmod,			"fchmod"		},
[ 92] = { 3,	TF,		sys_chown,			"chown"			},
[ 93] = { 3,	TD,		sys_fchown,			"fchown"		},
[ 94] = { 3,	TF,		sys_chown,			"lchown"		},
[ 95] = { 1,	0,		sys_umask,			"umask"			},
[ 96] = { 2,	0,		sys_gettimeofday,		"gettimeofday"		},
[ 97] = { 2,	0,		sys_getrlimit,			"getrlimit"		},
[ 98] = { 2,	0,		sys_getrusage,			"getrusage"		},
[ 99] = { 1,	0,		sys_sysinfo,			"sysinfo"		},
[100] = { 1,	0,		sys_times,			"times"			},
[101] = { 4,	0,		sys_ptrace,			"ptrace"		},
[102] = { 0,	NF,		sys_getuid,			"getuid"		},
[103] = { 3,	0,		sys_syslog,			"syslog"		},
[104] = { 0,	NF,		sys_getgid,			"getgid"		},
[105] = { 1,	0,		sys_setuid,			"setuid"		},
[106] = { 1,	0,		sys_setgid,			"setgid"		},
[107] = { 0,	NF,		sys_geteuid,			"geteuid"		},
[108] = { 0,	NF,		sys_getegid,			"getegid"		},
[109] = { 2,	0,		sys_setpgid,			"setpgid"		},
[110] = { 0,	0,		sys_getppid,			"getppid"		},
[111] = { 0,	0,		sys_getpgrp,			"getpgrp"		},
[112] = { 0,	0,		sys_setsid,			"setsid"		},
[113] = { 2,	0,		sys_setreuid,			"setreuid"		},
[114] = { 2,	0,		sys_setregid,			"setregid"		},
[115] = { 2,	0,		sys_getgroups,			"getgroups"		},
[116] = { 2,	0,		sys_setgroups,			"setgroups"		},
[117] = { 3,	0,		sys_setresuid,			"setresuid"		},
[118] = { 3,	0,		sys_getresuid,			"getresuid"		},
[119] = { 3,	0,		sys_setresgid,			"setresgid"		},
[120] = { 3,	0,		sys_getresgid,			"getresgid"		},
[121] = { 1,	0,		sys_getpgid,			"getpgid"		},
[122] = { 1,	NF,		sys_setfsuid,			"setfsuid"		},
[123] = { 1,	NF,		sys_setfsgid,			"setfsgid"		},
[124] = { 1,	0,		sys_getsid,			"getsid"		},
[125] = { 2,	0,		sys_capget,			"capget"		},
[126] = { 2,	0,		sys_capset,			"capset"		},
[127] = { 2,	TS,		sys_rt_sigpending,		"rt_sigpending"		},
[128] = { 4,	TS,		sys_rt_sigtimedwait,		"rt_sigtimedwait"	},
[129] = { 3,	TS,		sys_rt_sigqueueinfo,		"rt_sigqueueinfo"	},
[130] = { 2,	TS,		sys_rt_sigsuspend,		"rt_sigsuspend"		},
[131] = { 2,	TS,		sys_sigaltstack,		"sigaltstack"		},
[132] = { 2,	TF,		sys_utime,			"utime"			},
[133] = { 3,	TF,		sys_mknod,			"mknod"			},
[134] = { 1,	TF,		sys_uselib,			"uselib"		},
[135] = { 1,	0,		sys_personality,		"personality"		},
[136] = { 2,	0,		sys_ustat,			"ustat"			},
[137] = { 2,	TF,		sys_statfs,			"statfs"		},
[138] = { 2,	TD,		sys_fstatfs,			"fstatfs"		},
[139] = { 3,	0,		sys_sysfs,			"sysfs"			},
[140] = { 2,	0,		sys_getpriority,		"getpriority"		},
[141] = { 3,	0,		sys_setpriority,		"setpriority"		},
[142] = { 2,	0,		sys_sched_setparam,		"sched_setparam"	},
[143] = { 2,	0,		sys_sched_getparam,		"sched_getparam"	},
[144] = { 3,	0,		sys_sched_setscheduler,		"sched_setscheduler"	},
[145] = { 1,	0,		sys_sched_getscheduler,		"sched_getscheduler"	},
[146] = { 1,	0,		sys_sched_get_priority_max,	"sched_get_priority_max"},
[147] = { 1,	0,		sys_sched_get_priority_min,	"sched_get_priority_min"},
[148] = { 2,	0,		sys_sched_rr_get_interval,	"sched_rr_get_interval"	},
[149] = { 2,	TM,		sys_mlock,			"mlock"			},
[150] = { 2,	TM,		sys_munlock,			"munlock"		},
[151] = { 1,	TM,		sys_mlockall,			"mlockall"		},
[152] = { 0,	TM,		sys_munlockall,			"munlockall"		},
[153] = { 0,	0,		sys_vhangup,			"vhangup"		},
[154] = { 3,	0,		sys_modify_ldt,			"modify_ldt"		},
[155] = { 2,	TF,		sys_pivotroot,			"pivot_root"		},
[156] = { 1,	0,		sys_sysctl,			"_sysctl"		},
[157] = { 5,	0,		sys_prctl,			"prctl"			},
[158] = { 2,	TP,		sys_arch_prctl,			"arch_prctl"		},
[159] = { 1,	0,		sys_adjtimex,			"adjtimex"		},
[160] = { 2,	0,		sys_setrlimit,			"setrlimit"		},
[161] = { 1,	TF,		sys_chroot,			"chroot"		},
[162] = { 0,	0,		sys_sync,			"sync"			},
[163] = { 1,	TF,		sys_acct,			"acct"			},
[164] = { 2,	0,		sys_settimeofday,		"settimeofday"		},
[165] = { 5,	TF,		sys_mount,			"mount"			},
[166] = { 2,	TF,		sys_umount2,			"umount2"		},
[167] = { 2,	TF,		sys_swapon,			"swapon"		},
[168] = { 1,	TF,		sys_swapoff,			"swapoff"		},
[169] = { 4,	0,		sys_reboot,			"reboot"		},
[170] = { 2,	0,		sys_sethostname,		"sethostname"		},
[171] = { 2,	0,		sys_setdomainname,		"setdomainname"		},
[172] = { 1,	0,		sys_iopl,			"iopl"			},
[173] = { 3,	0,		sys_ioperm,			"ioperm"		},
[174] = { 2,	0,		sys_create_module,		"create_module"		},
[175] = { 3,	0,		sys_init_module,		"init_module"		},
[176] = { 2,	0,		sys_delete_module,		"delete_module"		},
[177] = { 1,	0,		sys_get_kernel_syms,		"get_kernel_syms"	},
[178] = { 5,	0,		sys_query_module,		"query_module"		},
[179] = { 4,	TF,		sys_quotactl,			"quotactl"		},
[180] = { 3,	0,		sys_nfsservctl,			"nfsservctl"		},
[181] = { 5,	0,		sys_getpmsg,			"getpmsg"		},
[182] = { 5,	0,		sys_putpmsg,			"putpmsg"		},
[183] = { 5,	0,		sys_afs_syscall,		"afs_syscall"		},
[184] = { 3,	0,		sys_tuxcall,			"tuxcall"		},
[185] = { 3,	0,		sys_security,			"security"		},
[186] = { 0,	0,		sys_gettid,			"gettid"		},
[187] = { 3,	TD,		sys_readahead,			"readahead"		},
[188] = { 5,	TF,		sys_setxattr,			"setxattr"		},
[189] = { 5,	TF,		sys_setxattr,			"lsetxattr"		},
[190] = { 5,	TD,		sys_fsetxattr,			"fsetxattr"		},
[191] = { 4,	TF,		sys_getxattr,			"getxattr"		},
[192] = { 4,	TF,		sys_getxattr,			"lgetxattr"		},
[193] = { 4,	TD,		sys_fgetxattr,			"fgetxattr"		},
[194] = { 3,	TF,		sys_listxattr,			"listxattr"		},
[195] = { 3,	TF,		sys_listxattr,			"llistxattr"		},
[196] = { 3,	TD,		sys_flistxattr,			"flistxattr"		},
[197] = { 2,	TF,		sys_removexattr,		"removexattr"		},
[198] = { 2,	TF,		sys_removexattr,		"lremovexattr"		},
[199] = { 2,	TD,		sys_fremovexattr,		"fremovexattr"		},
[200] = { 2,	TS,		sys_kill,			"tkill"			},
[201] = { 1,	0,		sys_time,			"time"			},
[202] = { 6,	0,		sys_futex,			"futex"			},
[203] = { 3,	0,		sys_sched_setaffinity,		"sched_setaffinity"	},
[204] = { 3,	0,		sys_sched_getaffinity,		"sched_getaffinity"	},
[205] = { 1,	0,		sys_set_thread_area,		"set_thread_area"	},
[206] = { 2,	0,		sys_io_setup,			"io_setup"		},
[207] = { 1,	0,		sys_io_destroy,			"io_destroy"		},
[208] = { 5,	0,		sys_io_getevents,		"io_getevents"		},
[209] = { 3,	0,		sys_io_submit,			"io_submit"		},
[210] = { 3,	0,		sys_io_cancel,			"io_cancel"		},
[211] = { 1,	0,		sys_get_thread_area,		"get_thread_area"	},
[212] = { 3,	0,		sys_lookup_dcookie,		"lookup_dcookie"	},
[213] = { 1,	TD,		sys_epoll_create,		"epoll_create"		},
[214] = { 4,	0,		printargs,			"epoll_ctl_old"		},
[215] = { 4,	0,		printargs,			"epoll_wait_old"	},
[216] = { 5,	TM|SI,		sys_remap_file_pages,		"remap_file_pages"	},
[217] = { 3,	TD,		sys_getdents64,			"getdents64"		},
[218] = { 1,	0,		sys_set_tid_address,		"set_tid_address"	},
[219] = { 0,	0,		sys_restart_syscall,		"restart_syscall"	},
[220] = { 4,	TI,		sys_semtimedop,			"semtimedop"		},
[221] = { 4,	TD,		sys_fadvise64,			"fadvise64"		},
[222] = { 3,	0,		sys_timer_create,		"timer_create"		},
[223] = { 4,	0,		sys_timer_settime,		"timer_settime"		},
[224] = { 2,	0,		sys_timer_gettime,		"timer_gettime"		},
[225] = { 1,	0,		sys_timer_getoverrun,		"timer_getoverrun"	},
[226] = { 1,	0,		sys_timer_delete,		"timer_delete"		},
[227] = { 2,	0,		sys_clock_settime,		"clock_settime"		},
[228] = { 2,	0,		sys_clock_gettime,		"clock_gettime"		},
[229] = { 2,	0,		sys_clock_getres,		"clock_getres"		},
[230] = { 4,	0,		sys_clock_nanosleep,		"clock_nanosleep"	},
[231] = { 1,	TP|SE,		sys_exit,			"exit_group"		},
[232] = { 4,	TD,		sys_epoll_wait,			"epoll_wait"		},
[233] = { 4,	TD,		sys_epoll_ctl,			"epoll_ctl"		},
[234] = { 3,	TS,		sys_tgkill,			"tgkill"		},
[235] = { 2,	TF,		sys_utimes,			"utimes"		},
[236] = { 5,	0,		sys_vserver,			"vserver"		},
[237] = { 6,	TM,		sys_mbind,			"mbind"			},
[238] = { 3,	TM,		sys_set_mempolicy,		"set_mempolicy"		},
[239] = { 5,	TM,		sys_get_mempolicy,		"get_mempolicy"		},
[240] = { 4,	0,		sys_mq_open,			"mq_open"		},
[241] = { 1,	0,		sys_mq_unlink,			"mq_unlink"		},
[242] = { 5,	0,		sys_mq_timedsend,		"mq_timedsend"		},
[243] = { 5,	0,		sys_mq_timedreceive,		"mq_timedreceive"	},
[244] = { 2,	0,		sys_mq_notify,			"mq_notify"		},
[245] = { 3,	0,		sys_mq_getsetattr,		"mq_getsetattr"		},
[246] = { 4,	0,		sys_kexec_load,			"kexec_load"		},
[247] = { 5,	TP,		sys_waitid,			"waitid"		},
[248] = { 5,	0,		sys_add_key,			"add_key"		},
[249] = { 4,	0,		sys_request_key,		"request_key"		},
[250] = { 5,	0,		sys_keyctl,			"keyctl"		},
[251] = { 3,	0,		sys_ioprio_set,			"ioprio_set"		},
[252] = { 2,	0,		sys_ioprio_get,			"ioprio_get"		},
[253] = { 0,	TD,		sys_inotify_init,		"inotify_init"		},
[254] = { 3,	TD,		sys_inotify_add_watch,		"inotify_add_watch"	},
[255] = { 2,	TD,		sys_inotify_rm_watch,		"inotify_rm_watch"	},
[256] = { 4,	TM,		sys_migrate_pages,		"migrate_pages"		},
[257] = { 4,	TD|TF,		sys_openat,			"openat"		},
[258] = { 3,	TD|TF,		sys_mkdirat,			"mkdirat"		},
[259] = { 4,	TD|TF,		sys_mknodat,			"mknodat"		},
[260] = { 5,	TD|TF,		sys_fchownat,			"fchownat"		},
[261] = { 3,	TD|TF,		sys_futimesat,			"futimesat"		},
[262] = { 4,	TD|TF,		sys_newfstatat,			"newfstatat"		},
[263] = { 3,	TD|TF,		sys_unlinkat,			"unlinkat"		},
[264] = { 4,	TD|TF,		sys_renameat,			"renameat"		},
[265] = { 5,	TD|TF,		sys_linkat,			"linkat"		},
[266] = { 3,	TD|TF,		sys_symlinkat,			"symlinkat"		},
[267] = { 4,	TD|TF,		sys_readlinkat,			"readlinkat"		},
[268] = { 3,	TD|TF,		sys_fchmodat,			"fchmodat"		},
[269] = { 3,	TD|TF,		sys_faccessat,			"faccessat"		},
[270] = { 6,	TD,		sys_pselect6,			"pselect6"		},
[271] = { 5,	TD,		sys_ppoll,			"ppoll"			},
[272] = { 1,	TP,		sys_unshare,			"unshare"		},
[273] = { 2,	0,		sys_set_robust_list,		"set_robust_list"	},
[274] = { 3,	0,		sys_get_robust_list,		"get_robust_list"	},
[275] = { 6,	TD,		sys_splice,			"splice"		},
[276] = { 4,	TD,		sys_tee,			"tee"			},
[277] = { 4,	TD,		sys_sync_file_range,		"sync_file_range"	},
[278] = { 4,	TD,		sys_vmsplice,			"vmsplice"		},
[279] = { 6,	TM,		sys_move_pages,			"move_pages"		},
[280] = { 4,	TD|TF,		sys_utimensat,			"utimensat"		},
[281] = { 6,	TD,		sys_epoll_pwait,		"epoll_pwait"		},
[282] = { 3,	TD|TS,		sys_signalfd,			"signalfd"		},
[283] = { 2,	TD,		sys_timerfd_create,		"timerfd_create"	},
[284] = { 1,	TD,		sys_eventfd,			"eventfd"		},
[285] = { 4,	TD,		sys_fallocate,			"fallocate"		},
[286] = { 4,	TD,		sys_timerfd_settime,		"timerfd_settime"	},
[287] = { 2,	TD,		sys_timerfd_gettime,		"timerfd_gettime"	},
[288] = { 4,	TN,		sys_accept4,			"accept4"		},
[289] = { 4,	TD|TS,		sys_signalfd4,			"signalfd4"		},
[290] = { 2,	TD,		sys_eventfd2,			"eventfd2"		},
[291] = { 1,	TD,		sys_epoll_create1,		"epoll_create1"		},
[292] = { 3,	TD,		sys_dup3,			"dup3"			},
[293] = { 2,	TD,		sys_pipe2,			"pipe2"			},
[294] = { 1,	TD,		sys_inotify_init1,		"inotify_init1"		},
[295] = { 4,	TD,		sys_preadv,			"preadv"		},
[296] = { 4,	TD,		sys_pwritev,			"pwritev"		},
[297] = { 4,	TP|TS,		sys_rt_tgsigqueueinfo,		"rt_tgsigqueueinfo"	},
[298] = { 5,	TD,		sys_perf_event_open,		"perf_event_open"	},
[299] = { 5,	TN,		sys_recvmmsg,			"recvmmsg"		},
[300] = { 2,	TD,		sys_fanotify_init,		"fanotify_init"		},
[301] = { 5,	TD|TF,		sys_fanotify_mark,		"fanotify_mark"		},
[302] = { 4,	0,		sys_prlimit64,			"prlimit64"		},
[303] = { 5,	TD|TF,		sys_name_to_handle_at,		"name_to_handle_at"	},
[304] = { 3,	TD,		sys_open_by_handle_at,		"open_by_handle_at"	},
[305] = { 2,	0,		sys_clock_adjtime,		"clock_adjtime"		},
[306] = { 1,	TD,		sys_syncfs,			"syncfs"		},
[307] = { 4,	TN,		sys_sendmmsg,			"sendmmsg"		},
[308] = { 2,	TD,		sys_setns,			"setns"			},
[309] = { 3,	0,		sys_getcpu,			"getcpu"		},
[310] = { 6,	0,		sys_process_vm_readv,		"process_vm_readv"	},
[311] = { 6,	0,		sys_process_vm_writev,		"process_vm_writev"	},
[312] = { 5,	0,		sys_kcmp,			"kcmp"			},
[313] = { 3,	TD,		sys_finit_module,		"finit_module"		},
[314] = { 3,	0,		sys_sched_setattr,		"sched_setattr"		},
[315] = { 4,	0,		sys_sched_getattr,		"sched_getattr"		},
[316] = { 5,	TD|TF,		sys_renameat2,			"renameat2"		},
[317] = { 3,	0,		sys_seccomp,			"seccomp",		},
[318] = { 3,	0,		sys_getrandom,			"getrandom",		},
[319] = { 2,	TD,		sys_memfd_create,		"memfd_create",		},
[320] = { 5,	TD,		sys_kexec_file_load,		"kexec_file_load",	},
[321] = { 3,	TD,		sys_bpf,			"bpf",			},
[322] = { 5,	TD|TF|TP|SE|SI,	sys_execveat,			"execveat",		},
