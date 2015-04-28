/*
** strace.h for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 04:18:11 2015 chapui_s
** Last update Tue Apr 28 08:31:14 2015 chapui_s
*/

#ifndef STRACE_H_
# define STRACE_H_

# include <sys/ptrace.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/user.h>

typedef struct	s_syscalls
{
  unsigned	num;
  char		*name;
  unsigned	nparams;
}		t_syscalls;

int		usage(char *);
int		derror(char *);
int		derrorn(char *);
char		**my_str_to_wordtab(char *s, char sep);
void		free_wordtab(char ***wordtab);

#endif /* !STRACE_H_ */
