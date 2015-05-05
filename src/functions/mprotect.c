/*
** read.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 05:38:20 2015 chapui_s
** Last update Tue May  5 08:11:51 2015 chapui_s
*/

#include "strace.h"

static void	print_prot(int prot)
{
  int		nb;

  if (!prot)
    printf("PROT_NONE");
  else
  {
    nb = 0;
    if (prot & PROT_READ && ++nb)
      printf("PROT_READ");
    if (prot & PROT_WRITE && ++nb)
      printf((nb) ? ("|PROT_WRITE") : ("PROT_WRITE"));
    if (prot & PROT_EXEC && ++nb)
      printf((nb) ? ("|PROT_EXEC") : ("PROT_EXEC"));
  }
}

void		print_mprotect(pid_t pid,
			       struct user_regs_struct *regs,
			       size_t return_value)
{
  printf("mprotect(");
  print_void_ptr(pid, get_param(regs, 0));
  printf(", ");
  print_size_t(pid, get_param(regs, 1));
  printf(", ");
  print_prot(get_param(regs, 2));
  printf(") = ");
  print_int(pid, return_value);
  printf("\n");
}
