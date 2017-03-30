/*
** fonc2.c for fonc2 in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Tue Dec 13 10:40:44 2016 Hugo Perier
** Last update Tue Dec 13 11:33:27 2016 Hugo Perier
*/

#include "my.h"

t_caisse	*getcaisse(t_caisse *caisse, char **map)
{
  int	i;
  int	k;
  int	n;

  n = 0;
  i = 0;
  k = 0;
  while (map[k][0] != '\0')
    {
      if (map[k][i] == 'X')
	{
	  map[k][i] = ' ';
	  caisse[n].x = i;
	  caisse[n].y = k;
	  n++;
	}
      if (map[k][i] == '\0')
	{
	  i = -1;
	  k++;
	}
      i++;
    }
  return (caisse);
}

int	nbcaisse(char **map)
{
  int	i;
  int	k;
  int	nb;

  i = 0;
  k = 0;
  nb = 0;
  while (map[k][0] != '\0')
    {
      if (map[k][i] == 'X')
	nb++;
      if (map[k][i] == '\0')
	{
	  i = -1;
	  k++;
	}
      i++;
    }
  return (nb);
}
