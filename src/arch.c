/*
** get_archi.c for strace in /home/broggi_t/projet/strace/src
** 
** Made by broggi_t
** Login   <broggi_t@epitech.eu>
** 
** Started on  Sun May 17 03:21:30 2015 broggi_t
** Last update Sun May 17 03:21:30 2015 broggi_t
*/

#include "strace.h"

int		get_archi(char const *const filename)
{
  int		fd;
  Elf32_Ehdr	header;

  g_archi32 = 0;
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, &header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
  {
    close(fd);
    return (-1);
  }
  if (header.e_machine == EM_386)
    g_archi32 = 1;
  else if (header.e_machine != EM_X86_64)
  {
    close(fd);
    return (derrorn("Unsupported format"));
  }
  close(fd);
  return (0);
}
