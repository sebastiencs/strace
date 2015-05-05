/*
** open.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 03:08:51 2015 chapui_s
** Last update Tue May  5 08:13:32 2015 chapui_s
*/

#include "strace.h"

static void	print_flags2(int flags)
{
  if (flags & O_DSYNC)
    printf("|O_DSYNC");
  if (flags & O_EXCL)
    printf("|O_EXCL");
  if (flags & O_NOCTTY)
    printf("|O_NOCTTY");
  if (flags & O_NOFOLLOW)
    printf("|O_NOFOLLOW");
  if (flags & O_NONBLOCK)
    printf("|O_NONBLOCK");
  if (flags & O_SYNC)
    printf("|O_SYNC");
  if (flags & O_TRUNC)
    printf("|O_TRUNC");
}

static void	print_flags(int flags)
{
  if ((flags & O_RDONLY) == 0)
    printf("O_RDONLY");
  else if ((flags & O_WRONLY) == 1)
    printf("O_WRONLY");
  else if ((flags & O_RDWR) == 2)
    printf("O_RDWR");
  if (flags & O_APPEND)
    printf("|O_APPEND");
  if (flags & O_ASYNC)
    printf("|O_ASYNC");
  if (flags & O_CLOEXEC)
    printf("|O_CLOEXEC");
  if (flags & O_CREAT)
    printf("|O_CREAT");
  if (flags & O_DIRECTORY)
    printf("|O_DIRECTORY");
  print_flags2(flags);
}

static void	print_mode(int mode)
{
  int		n;

  n = 0;
  n = (mode & S_IRWXU) ? (700) : (n);
  n = (mode & S_IRUSR) ? (n + 400) : (n);
  n = (mode & S_IWUSR) ? (n + 200) : (n);
  n = (mode & S_IXUSR) ? (n + 100) : (n);
  n = (mode & S_IRWXG) ? (70) : (n);
  n = (mode & S_IRGRP) ? (n + 40) : (n);
  n = (mode & S_IWGRP) ? (n + 20) : (n);
  n = (mode & S_IXGRP) ? (n + 10) : (n);
  n = (mode & S_IRWXO) ? (7) : (n);
  n = (mode & S_IROTH) ? (n + 4) : (n);
  n = (mode & S_IWOTH) ? (n + 2) : (n);
  n = (mode & S_IXOTH) ? (n + 1) : (n);
  printf("%d", n);
}

void		print_open(pid_t pid,
			     struct user_regs_struct *regs,
			     size_t return_value)
{
  printf("open(");
  print_char_ptr(pid, get_param(regs, 0));
  printf(", ");
  print_flags(get_param(regs, 1));
  if (get_param(regs, 1) & O_CREAT)
  {
    printf(", ");
    print_mode(get_param(regs, 3));
  }
  printf(") = ");
  print_int(pid, return_value);
  printf("\n");
}
