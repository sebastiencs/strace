/*
** strace.h for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 04:18:11 2015 chapui_s
** Last update Tue May  5 16:33:13 2015 chapui_s
*/

#ifndef STRACE_H_
# define STRACE_H_

# include <sys/ptrace.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/user.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <elf.h>

typedef struct	s_syscalls
{
  unsigned	num;
  char		*name;
  char		man_found;
  unsigned	nparams;
  int		type_return;
  int		param1;
  int		param2;
  int		param3;
  int		param4;
  int		param5;
  int		param6;
}		t_syscalls;

typedef struct	s_func
{
  int		type;
  int		(*fct)(pid_t pid, size_t value);
}		t_func;

typedef struct	s_print_func
{
  char		*name;
  void		(*fct)(pid_t pid, struct user_regs_struct *regs, size_t ret);
}		t_print_func;

typedef struct	s_arch_registers
{
  unsigned long	_32;
  unsigned long	_64;
}		t_arch_registers;

int		g_archi32;

int		usage(char *);
int		derror(char *);
int		derrorn(char *);
char		**my_str_to_wordtab(char *s, char sep);
void		free_wordtab(char ***wordtab);
int		is_syscall_defined(unsigned num);
size_t		my_strlen(char *s);
char		*get_path(char *file);
size_t		get_param(struct user_regs_struct *regs, int nparam);
void		print_space(int nb);

int		print_int(pid_t pid, size_t value);
int		print_size_t(pid_t pid, size_t value);
int		print_ssize_t(pid_t pid, size_t value);
int		print_off_t(pid_t pid, size_t value);
int		print_void_ptr(pid_t pid, size_t value);
int		print_char_ptr(pid_t pid, size_t value);

void		print_mmap(pid_t pid,
			   struct user_regs_struct *regs,
			   size_t ret);
void		print_mmap2(pid_t pid,
			    struct user_regs_struct *regs,
			    size_t ret);
void		print_access(pid_t pid,
			     struct user_regs_struct *regs,
			     size_t ret);
void		print_open(pid_t pid,
			   struct user_regs_struct *regs,
			   size_t ret);
void		print_read(pid_t pid,
			   struct user_regs_struct *regs,
			   size_t ret);
void		print_mprotect(pid_t pid,
			       struct user_regs_struct *regs,
			       size_t ret);
void		print_generic(pid_t pid,
			      struct user_regs_struct *regs,
			      size_t return_value,
			      int num);

void		trace_pid_handler(int const sig __attribute__ ((unused))) __attribute__ ((noreturn));
int		print_exit_status(int const status);

#endif /* !STRACE_H_ */
