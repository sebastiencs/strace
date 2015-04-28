/*
** puts.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 05:05:28 2015 chapui_s
** Last update Tue Apr 28 05:07:07 2015 chapui_s
*/

#include "strace.h"

int		derror(char *msg)
{
  perror(msg);
  return (-1);
}

int		derrorn(char *msg)
{
  fprintf(stderr, "%s\n", msg);
  return (-1);
}
