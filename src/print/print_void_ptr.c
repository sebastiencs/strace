/*
** print_void_ptr.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 01:10:54 2015 chapui_s
** Last update Tue May  5 01:31:56 2015 chapui_s
*/

#include "strace.h"

void		print_void_ptr(pid_t pid __attribute__ ((unused)),
			       size_t value)
{
  if (value)
  {
    printf("%p", (void*)value);
  }
  else
  {
    printf("0");
  }
}
