/*
** fonc3.c for fonc3 in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Tue Dec 13 17:27:39 2016 Hugo Perier
** Last update Sat Dec 17 11:23:25 2016 Hugo Perier
*/

#include "my.h"

int	checkcaisse2(int nb, t_player pos, t_caisse *caisse, char **map)
{
  int	i;

  i = 0;
  while (i <= caisse[0].nb)
    {
      if (nb == 3)
	{
	  if ((pos.x - 2 == caisse[i].x) && (pos.y == caisse[i].y))
	    return (0);
	}
      else if (nb == 4)
	{
	  if ((pos.x + 2 == caisse[i].x) && (pos.y == caisse[i].y))
	    return (0);
	}
      i++;
    }
  return (1);
}

void	aff(char **map, t_caisse *caisse, t_player pos)
{
  int	h;
  int	l;

  h = getmaxh(map);
  l = getmaxl(map);
  if (LINES > h && COLS > l)
    {
      clear();
      good_aff(map, pos, caisse);
    }
  else if (h > LINES || l > COLS)
    bad_aff();
}

int	checkend(t_caisse *caisse, char **map)
{
  int	i;

  i = 0;
  while (i < caisse[0].nb)
    {
      if (map[caisse[i].y][caisse[i].x] != 'O')
	return (1);
      i++;
    }
  return (0);
}

int	checkblock(t_caisse *c, char **map, int i)
{
  while (i < c[0].nb)
    {
      if (map[c[i].y - 1][c[i].x] == '#' && map[c[i].y][c[i].x] != 'O')
	{
	  if (map[c[i].y][c[i].x - 1] == '#')
	    return (1);
	}
      if (map[c[i].y - 1][c[i].x] == '#' && map[c[i].y][c[i].x] != 'O')
	{
	  if (map[c[i].y][c[i].x + 1] == '#')
	    return (1);
	}
      if (map[c[i].y + 1][c[i].x] == '#' && map[c[i].y][c[i].x] != 'O')
	{
	  if (map[c[i].y][c[i].x - 1] == '#')
	    return (1);
	}
      if (map[c[i].y + 1][c[i].x] == '#' && map[c[i].y][c[i].x] != 'O')
	{
	  if (map[c[i].y][c[i].x + 1] == '#')
	    return (1);
	}
      i++;
    }
  return (0);
}

void	tireth()
{
  my_string("USAGE\n");
  my_string("\t\t./my_sokoban map\n\n");
  my_string("DESCRIPTION\n");
  my_string("\t\tmap\tfile representing the warehouse");
  my_string(", containing '#' for walls,\n\t\t\t 'P' for the player");
  my_string(", 'X' for boxes and 'O' for storage locations.\n");
}
