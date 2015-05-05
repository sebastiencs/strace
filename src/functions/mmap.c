/*
** mmap.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 02:12:22 2015 chapui_s
** Last update Tue May  5 02:58:23 2015 chapui_s
*/

#include "strace.h"

static void	print_proto(int proto)
{
  int		nb;

  if (!proto)
    printf("PROT_NONE");
  else
  {
    nb = 0;
    if (proto & PROT_READ && ++nb)
      printf("PROT_READ");
    if (proto & PROT_WRITE && ++nb)
      printf((nb) ? ("|PROT_WRITE") : ("PROT_WRITE"));
    if (proto & PROT_EXEC && ++nb)
      printf((nb) ? ("|PROT_EXEC") : ("PROT_EXEC"));
  }
}

static void	print_flags(int flags)
{
  printf((flags & MAP_PRIVATE) ? ("MAP_PRIVATE") : ("MAP_SHARED"));
  if (flags & MAP_FIXED)
    printf("|MAP_FIXED");
  if (flags & MAP_32BIT)
    printf("|MAP_32BIT");
  if (flags & MAP_ANONYMOUS)
    printf("|MAP_ANONYMOUS");
  if (flags & MAP_DENYWRITE)
    printf("|MAP_DENYWRITE");
  if (flags & MAP_GROWSDOWN)
    printf("|MAP_GROWSDOWN");
  if (flags & MAP_HUGETLB)
    printf("|MAP_HUGETLB");
  if (flags & MAP_LOCKED)
    printf("|MAP_LOCKED");
  if (flags & MAP_NONBLOCK)
    printf("|MAP_NONBLOCK");
  if (flags & MAP_NORESERVE)
    printf("|MAP_NORESERVE");
  if (flags & MAP_POPULATE)
    printf("|MAP_POPULATE");
  if (flags & MAP_STACK)
    printf("|MAP_STACK");
}

void		print_mmap(pid_t pid,
			   struct user_regs_struct *regs,
			   size_t return_value)
{
  printf("mmap(");
  print_void_ptr(pid, regs->rdi);
  printf(", ");
  print_size_t(pid, regs->rsi);
  printf(", ");
  print_proto(regs->rdx);
  printf(", ");
  print_flags(regs->rcx);
  printf(", ");
  print_int(pid, regs->r8);
  printf(", ");
  print_off_t(pid, regs->r9);
  printf(") = ");
  print_void_ptr(pid, return_value);
  printf("\n");
}
