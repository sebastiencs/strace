/*
** print_generic.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 03:53:33 2015 chapui_s
** Last update Tue May  5 03:59:51 2015 chapui_s
*/

#include "strace.h"
#include "types.h"
#include "syscalls.h"

t_func		g_functions_print[] =
{
  { INT, print_int },
  { SIZE_T, print_size_t },
  { OFF_T, print_off_t },
  { VOID_P, print_void_ptr },
  { VOID_P, print_void_ptr },
  { CONST_VOID_P, print_void_ptr },
  { PVOID, print_void_ptr },
  { PCHAR, print_char_ptr },
  { CHAR_P, print_char_ptr },
  { CONST_CHAR_P, print_char_ptr },
  { CHAR_P_CONST, print_char_ptr },
  { UNSIGNED_CHAR_P, print_char_ptr },
  { -1, (void*)0 }
};

void		print_type(pid_t pid, unsigned num, char nparam, size_t value)
{
  char		*type;
  size_t	i;

  type = &g_syscalls[num].param1;
  if (nparam > 0)
    printf(", ");
  if (nparam < 6)
  {
    i = 0;
    type += nparam;
    while (g_functions_print[i].type != -1 && g_functions_print[i].type != type[0])
      i += 1;
    if (g_functions_print[i].type != -1)
      g_functions_print[i].fct(pid, value);
    else
      printf("0x%lx", (size_t)value);
  }
}

void		print_generic(pid_t pid,
			      struct user_regs_struct *regs,
			      size_t return_value,
			      int num)
{
  int		sys;

  sys = is_syscall_defined(num);
  printf("%s(", g_syscalls[sys].name);
  if (g_syscalls[sys].nparams >= 1)
    print_type(pid, num, 0, regs->rdi);
  if (g_syscalls[sys].nparams >= 2)
    print_type(pid, num, 1, regs->rsi);
  if (g_syscalls[sys].nparams >= 3)
    print_type(pid, num, 2, regs->rdx);
  if (g_syscalls[sys].nparams >= 4)
    print_type(pid, num, 3, regs->rcx);
  if (g_syscalls[sys].nparams >= 5)
    print_type(pid, num, 4, regs->r8);
  if (g_syscalls[sys].nparams >= 6)
    print_type(pid, num, 5, regs->r9);
  printf((return_value) ? (") = 0x%lx\n") : (") = %lx\n"), return_value);
}
