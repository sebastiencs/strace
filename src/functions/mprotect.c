/*
** mprotect.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 08:44:53 2015 chapui_s
** Last update Tue May  5 16:34:43 2015 chapui_s
*/

#include "strace.h"

static int	print_prot(int prot)
{
  int		nb;
  int		wt;

  wt = 0;
  if (!prot)
    wt += printf("PROT_NONE");
  else
  {
    nb = 0;
    if (prot & PROT_READ && ++nb)
      wt += printf("PROT_READ");
    if (prot & PROT_WRITE && ++nb)
      wt += printf((nb) ? ("|PROT_WRITE") : ("PROT_WRITE"));
    if (prot & PROT_EXEC && ++nb)
      wt += printf((nb) ? ("|PROT_EXEC") : ("PROT_EXEC"));
  }
  return (wt);
}

void		print_mprotect(pid_t pid,
			       struct user_regs_struct *regs,
			       size_t return_value)
{
  int		nb;

  nb = 0;
  nb += printf("mprotect(");
  nb += print_void_ptr(pid, get_param(regs, 0));
  nb += printf(", ");
  nb += print_size_t(pid, get_param(regs, 1));
  nb += printf(", ");
  nb += print_prot(get_param(regs, 2));
  nb += printf(")");
  print_space(nb);
  printf("= ");
  print_int(pid, return_value);
  printf("\n");
}
