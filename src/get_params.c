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

size_t		get_param(struct user_regs_struct *regs, int nparam)
{
  if (!nparam)
    return ((g_archi32) ? (regs->rbx) : (regs->rdi));
  if (nparam == 1)
    return ((g_archi32) ? (regs->rcx) : (regs->rsi));
  if (nparam == 2)
    return ((g_archi32) ? (regs->rdx) : (regs->rdx));
  if (nparam == 3)
    return ((g_archi32) ? (regs->rsi) : (regs->rcx));
  if (nparam == 4)
    return ((g_archi32) ? (regs->rdi) : (regs->r8));
  if (nparam == 5)
    return ((g_archi32) ? (regs->rbp) : (regs->r9));
  return (-1);
}
