/*
** print_int.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 01:03:27 2015 chapui_s
** Last update Tue May  5 01:29:55 2015 chapui_s
*/

#include "strace.h"

void		print_int(pid_t pid __attribute__ ((unused)),
			  size_t value)
{
  printf("%d", (int)value);
}
