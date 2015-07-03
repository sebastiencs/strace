/*
** strace.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 04:18:52 2015 chapui_s
** Last update Sun May 10 22:59:35 2015 chapui_s
*/

#include "strace.h"
#include "types.h"
#include "types32.h"

int	run_prog(char **argv,
		 char **env,
		 char *path)
{
  if (g_archi32)
    printf("[ Process PID=%d runs in 32 bit mode. ]\n", getpid());
  if (ptrace(PTRACE_TRACEME, 0, 0, 0, 0) == -1)
    return (derror("ptrace"));
  if (execve(path, &argv[1], env) == -1)
    return (derror("execve"));
  return (0);
}

int				run_trace(pid_t const pid)
{
  struct user_regs_struct	regs;
  struct user_regs_struct	regs_return;
  unsigned short		instr;
  int				wait_status;
  int				sysc;

  waitpid(pid, &wait_status, 0);
  while (signal_continue(wait_status))
  {
    sysc = 0;
    ptrace(PTRACE_GETREGS, pid, 0, &regs);
    instr = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, 0);
    if ((g_archi32 == 1 && instr == 0x80CD)
	|| (!g_archi32 && instr == 0x050F))
      sysc = 1;
    if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
      return (derror("ptrace"));
    waitpid(pid, &wait_status, 0);
    ptrace(PTRACE_GETREGS, pid, 0, &regs_return);
    if (sysc)
      disp_syscall(pid, &regs, regs.rax, regs_return.rax);
    check_signal(wait_status);
  }
  return (wait_status);
}

int	trace_fork(char **argv, char **env)
{
  pid_t	child;
  char	*path;

  if ((path = get_path(argv[1])))
  {
    if (get_archi(path) == -1)
      return (-1);
    if ((child = fork()) == -1)
      return (derror("fork"));
    else if (!child)
      run_prog(argv, env, path);
    else
      print_exit_status(run_trace(child));
    free(path);
  }
  else
    return (derrorn("No such file"));
  return (0);
}

/*
** global used for signal handling (exiting cleanly on ^C)
*/
pid_t g_pid = 0;

int	trace_pid(char **argv)
{
  int	status;

  signal(SIGINT, trace_pid_handler);
  signal(SIGTERM, trace_pid_handler);
  signal(SIGQUIT, trace_pid_handler);
  g_pid = atoi(argv[2]);
  g_archi32 = 0;
  if (ptrace(PTRACE_ATTACH, g_pid, 0, 0) == -1)
    return (derror("ptrace"));
  ptrace(PTRACE_CONT, g_pid, 0, 0);
  if ((status = run_trace(g_pid)) == -1)
    return (-1);
  ptrace(PTRACE_DETACH, g_pid, 0, 0);
  return (print_exit_status(status));
}

int	main(int argc, char **argv, char **env)
{
  setbuf(stdout, (char *)0);
  if (!(argc - 1))
    return (usage(argv[0]));
  else if (!strcmp(argv[1], "-p")
	   && argv[2])
    return (trace_pid(argv));
  else
    return (trace_fork(argv, env));
}
