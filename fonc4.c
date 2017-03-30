/*
** fonc4.c for fonc4 in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Mon Dec 19 16:10:17 2016 Hugo Perier
** Last update Mon Dec 19 16:52:19 2016 Hugo Perier
*/

#include "my.h"

void	quitsafe()
{
  endwin();
  exit(84);
}

void	test(int arg, t_player pos, char **map)
{
  if (arg == 1)
    {
      if (pos.y - 1 < 0)
	quitsafe();
    }
  else if (arg == 2)
    {
      if (pos.y + 1 > getmaxh(map) - 1)
	quitsafe();
    }
  else if (arg == 3)
    {
      if (pos.x - 1 < 0)
	quitsafe();
    }
  else if (arg == 4)
    {
      if (pos.x + 1 > getmaxl(map) - 2)
	quitsafe();
    }
}

void	testcaisse(int arg, t_caisse caisse, char **map)
{
  if (arg == 1)
    {
      if (caisse.y - 1 < 0)
	quitsafe();
    }
  else if (arg == 2)
    {
      if (caisse.y + 1 > getmaxh(map) - 1)
	quitsafe();
    }
  else if (arg == 3)
    {
      if (caisse.x - 1 < 0)
	quitsafe();
    }
  else if (arg == 4)
    {
      if (caisse.x + 1 > getmaxl(map) - 2)
	quitsafe();
    }
}
