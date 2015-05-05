/*
** print_off_t.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 02:53:45 2015 chapui_s
** Last update Tue May  5 16:23:57 2015 chapui_s
*/

#include "strace.h"

int		print_off_t(pid_t pid __attribute__ ((unused)),
			    size_t value)
{
  if (value)
  {
    return (printf("0x%lx", value));
  }
  else
  {
    return (printf("0"));
  }
}
