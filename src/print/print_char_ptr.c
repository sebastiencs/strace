/*
** print_char_ptr.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 01:16:18 2015 chapui_s
** Last update Tue May  5 16:22:10 2015 chapui_s
*/

#include "strace.h"

static int	print_word(long text)
{
  int		nb;

  nb = write(1, &text, 1);
  if (((char *)&text)[1] != 0)
    nb += write(1, &((char *)&text)[1], 1);
  return (nb);
}

int		print_char_ptr(pid_t pid,
			       size_t value)
{
  char		*s;
  size_t	i;
  long		text;
  char		*txt;
  int		nb;

  s = (char*)value;
  nb = 0;
  if (s)
  {
    txt = "abc";
    nb += printf("\"");
    i = 0;
    while (i < 20 && my_strlen(txt) > 1)
    {
      text = ptrace(PTRACE_PEEKTEXT, pid, s, (void *)0);
      txt = (char *)&text;
      if (strlen(txt))
	nb += print_word(text);
      s += 2;
      i += 1;
    }
    nb += printf((i == 20) ? ("\"...") : ("\""));
  }
  return (nb);
}
