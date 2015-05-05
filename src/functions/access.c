/*
** access.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 02:58:09 2015 chapui_s
** Last update Tue May  5 05:38:33 2015 chapui_s
*/

#include "strace.h"

static void	print_mode(int mode)
{
  int		nb;

  if (mode == F_OK)
    printf("F_OK");
  else
  {
    nb = 0;
    if (mode & R_OK && ++nb)
      printf("R_OK");
    if (mode & W_OK && ++nb)
      printf("W_OK");
    if (mode & X_OK && ++nb)
      printf("X_OK");
  }
}

void		print_access(pid_t pid,
			     struct user_regs_struct *regs,
			     size_t return_value)
{
  printf("access(");
  print_char_ptr(pid, regs->rdi);
  printf(", ");
  print_mode(regs->rsi);
  printf(") = ");
  print_int(pid, return_value);
  printf("\n");
}
