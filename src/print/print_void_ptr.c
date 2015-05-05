/*
** print_void_ptr.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 01:10:54 2015 chapui_s
** Last update Tue May  5 16:24:50 2015 chapui_s
*/

#include "strace.h"

int		print_void_ptr(pid_t pid __attribute__ ((unused)),
			       size_t value)
{
  if (value)
  {
    return (printf("%p", (void*)value));
  }
  else
  {
    return (printf("0"));
  }
}
