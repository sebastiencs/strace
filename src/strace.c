/*
** strace.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 04:18:52 2015 chapui_s
** Last update Tue Apr 28 09:10:21 2015 chapui_s
*/

#include "strace.h"

extern t_syscalls syscalls[];

int	trace_pid(int argc __attribute__ ((unused)),
		  char **argv __attribute__ ((unused)))
{
  return (0);
}

size_t	my_strlen(char *s)
{
  return ((s) ? (strlen(s)) : (0));
}

char	*my_strcat(char *dest, char *src)
{
  return ((dest && src) ? (strcat(dest, src)) : (dest));
}

char		*concat_path_file(char *s1, char *s2)
{
  char		*str;
  size_t	size;

  size = my_strlen(s1) + my_strlen(s2);
  str = (char*)malloc(size + 2);
  if (str)
  {
    memset(str, 0, size + 2);
    my_strcat(str, s1);
    strcat(str, "/");
    my_strcat(str, s2);
  }
  return (str);
}

char		*get_path(char *file)
{
  size_t	i;
  char		**path_tab;
  char		*tmp;

  if (file[0] == '.' || file[0] == '/')
  {
    return (strdup(file));
  }
  else if ((path_tab = my_str_to_wordtab(getenv("PATH"), ':')))
  {
    i = 0;
    while (path_tab[i])
    {
      tmp = concat_path_file(path_tab[i], file);
      if (tmp && access(tmp, X_OK) != -1)
      {
	free_wordtab(&path_tab);
	return (tmp);
      }
      free(tmp);
      i += 1;
    }
    free_wordtab(&path_tab);
  }
  return ((char*)0);
}

int	run_prog(int argc __attribute__ ((unused)),
		 char **argv,
		 char **env)
{
  char	*path;

  if (ptrace(PTRACE_TRACEME, 0, 0, 0, 0) == -1)
  {
    return (derror("ptrace"));
  }
  if ((path = get_path(argv[1])))
  {
    if (execve(path, &argv[1], env) == -1)
      return (derror("execve"));
    free(path);
  }
  else
  {
    return (derrorn("No such file"));
  }
  return (0);
}

void		disp_syscall(struct user_regs_struct *regs,
			     unsigned num,
			     size_t return_value)
{
  if (num <= 322)
  {
    printf("%s(", syscalls[num].name);
    if (syscalls[num].nparams >= 1)
      printf((regs->rdi) ? ("0x%llx") : ("%llx"), regs->rdi);
    if (syscalls[num].nparams >= 2)
      printf((regs->rsi) ? (", 0x%llx") : (", %llx"), regs->rsi);
    if (syscalls[num].nparams >= 3)
      printf((regs->rdx) ? (", 0x%llx") : (", %llx"), regs->rdx);
    if (syscalls[num].nparams >= 4)
      printf((regs->rcx) ? (", 0x%llx") : (", %llx"), regs->rcx);
    if (syscalls[num].nparams >= 5)
      printf((regs->r8) ? (", 0x%llx") : (", %llx"), regs->r8);
    if (syscalls[num].nparams >= 6)
      printf((regs->r9) ? (", 0x%llx") : (", %llx"), regs->r9);
    printf((return_value) ? (") = 0x%lx\n") : (") = %lx\n"), return_value);
  }
}

int				run_trace_fork(pid_t child)
{
  struct user_regs_struct	regs;
  struct user_regs_struct	regs_return;
  unsigned short		instr;
  int				wait_status;
  int				sysc;

  wait(&wait_status);
  while (WIFSTOPPED(wait_status))
  {
    ptrace(PTRACE_GETREGS, child, 0, &regs);
    instr = ptrace(PTRACE_PEEKTEXT, child, regs.rip, 0);
    sysc = (instr == 0x050F) ? (1) : (0);
    if (ptrace(PTRACE_SINGLESTEP, child, 0, 0) == -1)
    {
      return (derror("ptrace"));
    }
    wait(&wait_status);
    ptrace(PTRACE_GETREGS, child, 0, &regs_return);
    if (sysc)
    {
      disp_syscall(&regs, regs.rax, regs_return.rax);
    }
  }
  return (0);
}

int	trace_fork(int argc, char **argv, char **env)
{
  pid_t	child;

  if ((child = fork()) == -1)
    return (derror("fork"));
  else if (!child)
    run_prog(argc, argv, env);
  else
  {
    run_trace_fork(child);
  }
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  setbuf(stdout, NULL);
  if (!(argc - 1))
    return (usage(argv[0]));
  else if (!strcmp(argv[1], "-p"))
    return (trace_pid(argc, argv));
  else
    return (trace_fork(argc, argv, env));
}
