/*
** movecaisse.c for movecaisse in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Tue Dec 13 13:51:19 2016 Hugo Perier
** Last update Mon Dec 19 16:54:24 2016 Hugo Perier
*/

#include "my.h"

t_player	movecaisseh(char **map, t_player pos, t_caisse *caisse)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (i <= caisse[0].nb)
    {
      if ((pos.y - 1 == caisse[i].y) && (pos.x == caisse[i].x))
	n = i;
      i++;
    }
  if ((pos.y - 1 == caisse[n].y) && (pos.x == caisse[n].x))
    {
      testcaisse(1, caisse[n], map);
      if ((map[pos.y-2][pos.x] != '#')&&(checkcaisse(1, pos, caisse, map)== 1))
	{
	  pos.y = pos.y - 1;
	  caisse[n].y = caisse[n].y - 1;
	}
    }
  else if (map[pos.y - 1][pos.x] != '#')
    pos.y = pos.y - 1;
  return (pos);
}

t_player	movecaisseb(char **map, t_player pos, t_caisse *caisse)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (i <= caisse[0].nb)
    {
      if ((pos.y + 1 == caisse[i].y) && (pos.x == caisse[i].x))
	n = i;
      i++;
    }
  if ((pos.y + 1 == caisse[n].y) && (pos.x == caisse[n].x))
    {
      testcaisse(2, caisse[n], map);
      if ((map[pos.y + 2][pos.x] != '#') &&
	  (checkcaisse(2, pos, caisse, map) == 1))
	{
	  pos.y = pos.y + 1;
	  caisse[n].y = caisse[n].y + 1;
	}
    }
  else if (map[pos.y + 1][pos.x] != '#')
    pos.y = pos.y + 1;
  return (pos);
}

t_player	movecaisseg(char **map, t_player pos, t_caisse *caisse)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (i <= caisse[0].nb)
    {
      if ((pos.y == caisse[i].y) && (pos.x - 1 == caisse[i].x))
	n = i;
      i++;
    }
  if ((pos.y == caisse[n].y) && (pos.x - 1 == caisse[n].x))
    {
      testcaisse(3, caisse[n], map);
      if ((map[pos.y][pos.x - 2] != '#') &&
	  (checkcaisse2(3, pos, caisse, map) == 1))
	{
	  pos.x = pos.x - 1;
	  caisse[n].x = caisse[n].x - 1;
	}
    }
  else if (map[pos.y][pos.x - 1] != '#')
    pos.x = pos.x - 1;
  return (pos);
}

t_player	movecaissed(char **map, t_player pos, t_caisse *caisse)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (i <= caisse[0].nb)
    {
      if ((pos.y == caisse[i].y) && (pos.x + 1 == caisse[i].x))
	n = i;
      i++;
    }
  if ((pos.y == caisse[n].y) && (pos.x + 1 == caisse[n].x))
    {
      testcaisse(4, caisse[n], map);
      if ((map[pos.y][pos.x + 2] != '#') &&
	  (checkcaisse2(4, pos, caisse, map) == 1))
	{
	  pos.x = pos.x + 1;
	  caisse[n].x = caisse[n].x + 1;
	}
    }
  else if (map[pos.y][pos.x + 1] != '#')
    pos.x = pos.x + 1;
  return (pos);
}

int	checkcaisse(int nb, t_player pos, t_caisse *caisse, char **map)
{
  int	i;

  i = 0;
  while (i <= caisse[0].nb)
    {
      if (nb == 1)
	{
	  if ((pos.y - 2 == caisse[i].y) && (pos.x == caisse[i].x))
	    return (0);
	}
      else if (nb == 2)
	{
	  if ((pos.y + 2 == caisse[i].y) && (pos.x == caisse[i].x))
	    return (0);
	}
      i++;
    }
  return (1);
}
