/*
** read.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 05:38:20 2015 chapui_s
** Last update Tue May  5 06:02:47 2015 chapui_s
*/

#include "strace.h"

static void	print_word(long word)
{
  char		*s;
  size_t	i;

  i = 0;
  s = (char*)&word;
  while (i < 2)
  {
    if (s[i] >= 0x20 && s[i] <= 0x7E)
      printf("%c", s[i]);
    else
      printf("\\%o", (unsigned int)s[i]);
    i += 1;
  }
}

static void	print_buf(pid_t pid, char *ptr, size_t len)
{
  size_t	i;
  long		text;

  i = 0;
  printf("\"");
  while (i < 16 && i < len)
  {
    text = ptrace(PTRACE_PEEKTEXT, pid, ptr, (void*)0);
    if (text >= 0)
    {
      print_word(text);
    }
    i += 1;
    ptr += 2;
  }
  printf("\"");
  if (i == 16)
  {
    printf("...");
  }
}

void		print_read(pid_t pid,
			   struct user_regs_struct *regs,
			   size_t return_value)
{
  printf("read(");
  print_int(pid, regs->rdi);
  printf(", ");
  print_buf(pid, (char*)regs->rsi, regs->rdx);
  printf(", ");
  print_size_t(pid, regs->rdx);
  printf(") = ");
  print_ssize_t(pid, return_value);
  printf("\n");
}
