/*
** print_off_t.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 02:53:45 2015 chapui_s
** Last update Tue May  5 02:54:43 2015 chapui_s
*/

#include "strace.h"

void		print_off_t(pid_t pid __attribute__ ((unused)),
			    size_t value)
{
  if (value)
  {
    printf("0x%lx", value);
  }
  else
  {
    printf("0");
  }
}
