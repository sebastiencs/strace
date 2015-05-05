/*
** strace.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 04:18:52 2015 chapui_s
** Last update Tue May  5 04:06:27 2015 chapui_s
*/

#include "strace.h"
#include "types.h"
#include "syscalls.h"

int	trace_pid(int argc __attribute__ ((unused)),
		  char **argv __attribute__ ((unused)))
{
  return (0);
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

int		is_syscall_defined(unsigned num)
{
  size_t	i;

  i = 0;
  while (i < g_size_tab)
  {
    if (g_syscalls[i].num == num)
      return (i);
    i += 1;
  }
  return (0);
}

t_print_func	g_print_func[] =
{
  { "mmap", print_mmap },
  { "access", print_access },
  { "open", print_open },
  { (char*)0, (void*)0 }
};

int		is_functions_associated(char *name)
{
  size_t	i;

  i = 0;
  while (g_print_func[i].name && strcmp(name, g_print_func[i].name))
  {
    i += 1;
  }
  if (g_print_func[i].name)
  {
    return (i);
  }
  else
  {
    return (-1);
  }
}

void		disp_syscall(pid_t pid,
			     struct user_regs_struct *regs,
			     unsigned num,
			     size_t return_value)
{
  int		sys;
  int		fct;

  if ((sys = is_syscall_defined(num)))
  {
    if ((fct = is_functions_associated(g_syscalls[sys].name)) != -1)
    {
      g_print_func[fct].fct(pid, regs, return_value);
    }
    else
    {
      print_generic(pid, regs, return_value, num);
    }
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
      disp_syscall(child, &regs, regs.rax, regs_return.rax);
    }
  }
  return (0);
}

int	trace_fork(int argc, char **argv, char **env)
{
  pid_t	child;

  if ((child = fork()) == -1)
  {
    return (derror("fork"));
  }
  else if (!child)
  {
    run_prog(argc, argv, env);
  }
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
