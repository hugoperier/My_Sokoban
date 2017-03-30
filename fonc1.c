/*
** fonc2.c for fonc2 in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Mon Dec 12 14:07:52 2016 Hugo Perier
** Last update Thu Dec 22 15:01:16 2016 Hugo Perier
*/

#include "my.h"

int	getmaxh(char **str)
{
  int	i;

  i = 0;
  while (str[i][0] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	getmaxl(char **str)
{
  int	i;
  int	y;
  int	maxsize;

  i = 0;
  y = 0;
  maxsize = 0;
  while (str[y][0] != '\0')
    {
      if (str[y][i] == '\0')
	{
	  if (i > maxsize)
	      maxsize = i;
	  i = -1;
	  y = y + 1;
	}
      i = i + 1;
    }
  return (maxsize);
}

void	bad_aff()
{
  clear();
  mvprintw(LINES / 2, (COLS / 2) - 7, "Please be fair");
  refresh();
}

void	good_aff(char **map, t_player pos, t_caisse *caisse)
{
  int	i;
  int	y;
  int	h;
  int	l;

  l = getmaxl(map);
  h = getmaxh(map);
  y = 0;
  i = 0;
  while (y <= h)
    {
      mvprintw((LINES/2) - (h / 2) + i, (COLS / 2) - (l / 2), map[y]);
      y = y + 1;
      i = i + 1;
    }
  mvprintw((LINES / 2) - (h / 2) + pos.y, (COLS /2 ) - (l / 2) + pos.x, "P");
  i = caisse[0].nb;
  while (i != 0)
    {
      i--;
      mvprintw((LINES/2)-(h/2)+caisse[i].y, (COLS/2)-(l/2) + caisse[i].x, "X");
    }
  refresh();
}

t_player	locate_player(char **map, t_player pos)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (map[k][0] != '\0')
    {
      if (map[k][i] == 'P')
	{
	  map[k][i] = ' ';
	  pos.x = i;
	  pos.y = k;
	}
      if (map[k][i] == '\0')
	{
	  i = -1;
	  k = k + 1;
	}
      i = i + 1;
    }
  return (pos);
}
