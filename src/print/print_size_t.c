/*
** print_size_t.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 01:04:52 2015 chapui_s
** Last update Tue May  5 16:24:13 2015 chapui_s
*/

#include "strace.h"

int		print_size_t(pid_t pid __attribute__ ((unused)),
			     size_t value)
{
  return (printf("%lu", value));
}
