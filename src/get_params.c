/*
** get_params.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 07:52:40 2015 chapui_s
** Last update Tue May  5 07:59:08 2015 chapui_s
*/

#include "strace.h"

size_t				get_param(struct user_regs_struct *regs,
					  int nparam)
{
  t_arch_registers const	reg[] = {{regs->rbx, regs->rdi},
					 {regs->rcx, regs->rsi},
					 {regs->rdx, regs->rdx},
					 {regs->rsi, regs->rcx},
					 {regs->rdi, regs->r8},
					 {regs->rbp, regs->r9}};

  if (nparam < 0 || (unsigned)nparam >= sizeof(reg) / sizeof(*reg))
    return (-1);
  return (g_archi32 ? reg[nparam]._32 : reg[nparam]._64);
}
