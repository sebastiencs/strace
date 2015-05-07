/*
** my_str_to_wordtab.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 05:32:41 2015 chapui_s
** Last update Tue Apr 28 05:38:53 2015 chapui_s
*/

#include "strace.h"

static int	get_nb_word(char *s, char sep)
{
  int		nb;
  int		is_char;

  nb = 0;
  while (s && *s)
  {
    is_char = 0;
    while (*s && *s == sep)
      s += 1;
    while (*s && *s != sep && ((is_char = 1)))
      s += 1;
    while (*s && *s == sep)
      s += 1;
    if (is_char == 1)
      nb += 1;
  }
  return (nb);
}

static char	*get_this_word(char *s, char sep)
{
  char		*new;
  char		*end;
  int		size;
  int		i;

  end = s;
  while (*end && *end != sep)
    end += 1;
  size = end - s;
  if ((new = (char *)malloc(size + 1)) == (char *)0)
    return ((char *)0);
  new[size] = 0;
  i = 0;
  while (i < size)
    new[i++] = *s++;
  new[i] = 0;
  return (new);
}

static int	get_words(char **tab, char *s, char sep)
{
  int		i;

  i = 0;
  while (s && *s)
  {
    while (*s && *s == sep)
      s += 1;
    if ((tab[i++] = get_this_word(s, sep)) == (char *)0)
      return (-1);
    while (*s && *s != sep)
      s += 1;
    while (*s && *s == sep)
      s += 1;
  }
  return (0);
}

char		**my_str_to_wordtab(char *s, char sep)
{
  char		**tab;
  int		nb_word;

  if (!s)
    return ((char **)0);
  nb_word = get_nb_word(s, sep);
  if ((tab = (char **)malloc(sizeof(char *) * (nb_word + 1))) == (char **)0
      || get_words(tab, s, sep) == -1)
  {
    derror("malloc");
    return ((char **)0);
  }
  tab[nb_word] = (char *)0;
  return (tab);
}

void		free_wordtab(char ***wordtab)
{
  char		**tab;
  size_t	i;

  i = 0;
  tab = *wordtab;
  while (tab[i])
  {
    free(tab[i]);
    i += 1;
  }
  free(tab[i]);
  free(tab);
  *wordtab = (char **)0;
}
