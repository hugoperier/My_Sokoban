/*

** getstr.c for getstr in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Mon Dec 12 10:55:49 2016 Hugo Perier
** Last update Mon Jan 30 13:44:43 2017 Hugo Perier
*/

#include "my.h"

int	my_len(char *str, int pos)
{
  int   nb;
  int	i;
  int	result;

  result = 0;
  i = 0;
  nb = 0;
  while (nb < pos)
    {
      if (str[i] == '\n')
	nb++;
      i++;
    }
  while (str[i] != '\n' && str[i] != '\0')
    {
      i++;
      result++;
    }
  return (result);
}

int     my_nblen(char *str)
{
  int   i;
  int   y;

  y = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	y = y + 1;
      i = i + 1;
    }
  return (y);
}

void    my_cpy(char **fichier, char *str)
{
  int   i;
  int   y;
  int   e;

  i = 0;
  y = 0;
  e = 0;
  while (str[i] != '\0')
    {
      fichier[y][e] = str[i];
      if (str[i] == '\n')
	{
	  fichier[y][e + 1] = '\0';
	  y = y + 1;
	  e = -1;
	}
      e = e + 1;
      i = i + 1;
    }
  fichier[y+1][0] = '\0';
}

void	my_aff_tab(char **str)
{
  int	y;

  y = 0;
  while (str[y][0] != '\0')
    {
      my_string(str[y]);
      y = y + 1;
    }
}

void    my_malloc(char ***fichier, char *str)
{
  int   i;
  int   nblen;

  nblen = my_nblen(str);
  i = 0;
  *fichier = malloc(sizeof(char *) * nblen + 4);
  while (i < nblen + 1)
    {
      (*fichier)[i] = malloc(sizeof(char) * my_len(str, i) + 1);
      i = i + 1;
    }
  (*fichier)[i] = malloc(sizeof(char) * 2);
}
