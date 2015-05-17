/*
** exit.c for  in /home/broggi_t/projet/strace/src
** 
** Made by broggi_t
** Login   <broggi_t@epitech.eu>
** 
** Started on  Sun May 17 01:56:53 2015 broggi_t
** Last update Sun May 17 01:56:53 2015 broggi_t
*/

#include "strace.h"

extern pid_t g_pid;
extern char const *const g_signames[];

void	trace_pid_handler(int const sig __attribute__ ((unused)))
{
  ptrace(PTRACE_DETACH, g_pid, 0, 0);
  ptrace(PTRACE_CONT, g_pid, 0, 0);
  exit(EXIT_FAILURE);
}

int	print_exit_status(int const status)
{
  if (status == -1)
    return (-1);
  if (WIFEXITED(status))
    printf("+++ exited with %d +++\n", WEXITSTATUS(status));
  else if (WIFSIGNALED(status))
    {
#ifdef WCOREDUMP
      if (WCOREDUMP(status))
	printf("+++ Killed by %s (core dumped) +++\n",
	       g_signames[WTERMSIG(status)]);
      else
#endif
	printf("+++ Killed by %s +++\n", g_signames[WTERMSIG(status)]);
    }
  else if (WIFSTOPPED(status))
    printf("+++ Killed by %s +++\n", g_signames[WSTOPSIG(status)]);
  return (0);
}
