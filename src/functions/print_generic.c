/*
** print_generic.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 03:53:33 2015 chapui_s
** Last update Tue May  5 08:08:20 2015 chapui_s
*/

#include "strace.h"
#include "types.h"
#include "syscalls.h"
#include "types32.h"
#include "syscalls32.h"

t_func		g_functions_print[] =
{
  { INT, print_int },
  { X32INT, print_int },
  { SIZE_T, print_size_t },
  { X32SIZE_T, print_size_t },
  { OFF_T, print_off_t },
  { X32OFF_T, print_off_t },
  { VOID_P, print_void_ptr },
  { X32VOID_P, print_void_ptr },
  { CONST_VOID_P, print_void_ptr },
  { X32CONST_VOID_P, print_void_ptr },
  { PVOID, print_void_ptr },
  { X32PVOID, print_void_ptr },
  { PCHAR, print_char_ptr },
  { X32PCHAR, print_char_ptr },
  { CHAR_P, print_char_ptr },
  { X32CHAR_P, print_char_ptr },
  { CONST_CHAR_P, print_char_ptr },
  { X32CONST_CHAR_P, print_char_ptr },
  { CHAR_P_CONST, print_char_ptr },
  { X32CHAR_P_CONST, print_char_ptr },
  { UNSIGNED_CHAR_P, print_char_ptr },
  { X32UNSIGNED_CHAR_P, print_char_ptr },
  { -1, (void*)0 }
};

void		print_type(pid_t pid, unsigned num, char nparam, size_t value)
{
  int		*type;
  size_t	i;

  type = (g_archi32) ? (&g_syscalls32[num].param1) : (&g_syscalls[num].param1);
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
  t_syscalls	*ptr;

  ptr = (g_archi32) ? (g_syscalls32) : (g_syscalls);
  sys = is_syscall_defined(num);
  printf("%s(", ptr[sys].name);
  if (ptr[sys].nparams >= 1)
    print_type(pid, num, 0, get_param(regs, 0));
  if (ptr[sys].nparams >= 2)
    print_type(pid, num, 1, get_param(regs, 1));
  if (ptr[sys].nparams >= 3)
    print_type(pid, num, 2, get_param(regs, 2));
  if (ptr[sys].nparams >= 4)
    print_type(pid, num, 3, get_param(regs, 3));
  if (ptr[sys].nparams >= 5)
    print_type(pid, num, 4, get_param(regs, 4));
  if (ptr[sys].nparams >= 6)
    print_type(pid, num, 5, get_param(regs, 5));
  printf((return_value) ? (") = 0x%lx\n") : (") = %lx\n"), return_value);
}
