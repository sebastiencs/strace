/*
** usage.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 04:46:15 2015 chapui_s
** Last update Tue Apr 28 04:54:39 2015 chapui_s
*/

#include "strace.h"

int		usage(char *prog)
{
  printf("usage:\t\t%s PROG [ARGS]\n   or\t\t%s -p PID\n", prog, prog);
  return (-1);
}
