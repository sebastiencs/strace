/*
** syscall.c for strace  in /home/broggi_t/projet/strace
** 
** Made by broggi_t
** Login   <broggi_t@epitech.eu>
** 
** Started on  Sun May 17 03:14:13 2015 broggi_t
** Last update Sun May 17 03:14:13 2015 broggi_t
*/

#include "strace.h"
#include "types.h"
#include "types32.h"
#include "syscalls.h"
#include "syscalls32.h"

t_print_func	g_print_func[] =
{
  { "mmap", print_mmap },
  { "mmap2", print_mmap2 },
  { "access", print_access },
  { "open", print_open },
  { "read", print_read },
  { "mprotect", print_mprotect },
  { (char *)0, (void *)0 }
};

int		is_syscall_defined(unsigned int const num)
{
  size_t	i;

  i = 0;
  while (i < g_size_tab)
  {
    if (g_archi32 && g_syscalls32[i].num == num)
      return (i);
    else if (!g_archi32 && g_syscalls[i].num == num)
      return (i);
    i += 1;
  }
  return (-1);
}

static int	is_functions_associated(char const *const name)
{
  size_t	i;

  i = 0;
  while (g_print_func[i].name && strcmp(name, g_print_func[i].name))
    i += 1;
  return (g_print_func[i].name ? (signed)i : -1);
}

void		disp_syscall(pid_t pid,
			     struct user_regs_struct *regs,
			     unsigned num,
			     size_t return_value)
{
  int		sys;
  int		fct;
  t_syscalls	*ptr;

  ptr = (g_archi32) ? (g_syscalls32) : (g_syscalls);
  if ((sys = is_syscall_defined(num)) >= 0)
  {
    if ((fct = is_functions_associated(ptr[sys].name)) != -1)
      g_print_func[fct].fct(pid, regs, return_value);
    else
      print_generic(pid, regs, return_value, num);
  }
}
