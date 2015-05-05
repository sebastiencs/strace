/*
** print_char_ptr.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 01:16:18 2015 chapui_s
** Last update Tue May  5 05:42:05 2015 chapui_s
*/

#include "strace.h"

void		print_word(long text)
{
  write(1, &text, 1);
  if (((char*)&text)[1] != 0)
    write(1, &((char*)&text)[1], 1);
}

void		print_char_ptr(pid_t pid,
			       size_t value)
{
  char		*s;
  size_t	i;
  long		text;
  char		*txt;

  s = (char*)value;
  if (s)
  {
    txt = "abc";
    printf("\"");
    i = 0;
    while (i < 20 && my_strlen(txt) > 1)
    {
      text = ptrace(PTRACE_PEEKTEXT, pid, s, (void*)0);
      txt = (char*)&text;
      if (strlen(txt))
	print_word(text);
      s += 2;
      i += 1;
    }
    if (i == 20)
      printf("...");
    printf("\"");
  }
}
