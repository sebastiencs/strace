/*
** signal.c for strace  in /home/broggi_t/projet/strace
** 
** Made by broggi_t
** Login   <broggi_t@epitech.eu>
** 
** Started on  Sun May 17 02:36:50 2015 broggi_t
** Last update Sun May 17 02:36:50 2015 broggi_t
*/

#include "strace.h"
#include "signames.h"

INLINE int	signal_continue(int const status)
{
  return (WIFSTOPPED(status)
	  && (WSTOPSIG(status) == SIGTRAP
	      || WSTOPSIG(status) == SIGSTOP));
}

void	check_signal(int const status)
{
  if (WIFSTOPPED(status)
      && WSTOPSIG(status) != SIGTRAP)
    printf("--- %s ---\n", g_signames[WSTOPSIG(status)]);
}
