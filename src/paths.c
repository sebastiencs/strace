/*
** paths.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue May  5 04:03:07 2015 chapui_s
** Last update Tue May  5 04:04:54 2015 chapui_s
*/

#include "strace.h"

size_t	my_strlen(char *s)
{
  return ((s) ? (strlen(s)) : (0));
}

char	*my_strcat(char *dest, char *src)
{
  return ((dest && src) ? (strcat(dest, src)) : (dest));
}

char		*concat_path_file(char *s1, char *s2)
{
  char		*str;
  size_t	size;

  size = my_strlen(s1) + my_strlen(s2);
  str = (char *)malloc(size + 2);
  if (str)
  {
    memset(str, 0, size + 2);
    my_strcat(str, s1);
    strcat(str, "/");
    my_strcat(str, s2);
  }
  return (str);
}

char		*get_path(char *file)
{
  size_t	i;
  char		**path_tab;
  char		*tmp;

  if (file[0] == '.' || file[0] == '/')
  {
    return (strdup(file));
  }
  else if ((path_tab = my_str_to_wordtab(getenv("PATH"), ':')))
  {
    i = 0;
    while (path_tab[i])
    {
      tmp = concat_path_file(path_tab[i], file);
      if (tmp && access(tmp, X_OK) != -1)
      {
	free_wordtab(&path_tab);
	return (tmp);
      }
      free(tmp);
      i += 1;
    }
    free_wordtab(&path_tab);
  }
  return ((char *)0);
}
