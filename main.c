/*
** main.c for main in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Mon Dec 12 10:51:27 2016 Hugo Perier
** Last update Mon Dec 19 16:47:27 2016 Hugo Perier
*/

#include "my.h"

void    my_get_file(char *path, char **fichier)
{
  int   size;
  int   fd;
  char  *str;

  size = 5000;
  str = malloc(sizeof(char) * size + 1);
  fd = open(path, 0);
  read(fd, str, size);
  my_malloc(&fichier, str);
  my_cpy(fichier, str);
  game_begin(fichier, path);
}

int	main(int ac, char **av)
{
  char	**file;

  if (ac > 1)
    {
      if (av[1][0] == '-' && av[1][1] == 'h')
	tireth();
      else
	my_get_file(av[1], file);
    }
  return (84);
}

int		game_begin(char **map, char *cpy)
{
  t_caisse	 *caisse;
  int	i;

  caisse = malloc(sizeof(t_caisse) * nbcaisse(map));
  caisse[0].nb = nbcaisse(map);
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  getcaisse(caisse, map);
  i = aff_map(map, caisse, cpy);
  if (i == 22)
    my_get_file(cpy, map);
  endwin();
  exit(i);
}

int	aff_map(char **map, t_caisse *caisse, char *cpy)
{
  int	key;
  t_player	pos;

  pos = locate_player(map, pos);
  while (1)
    {
      if (checkend(caisse, map) == 0)
	return (0);
      aff(map, caisse, pos);
      key = getch();
      if (key == KEY_UP)
	pos = refresh_map(1, map, pos, caisse);
      else if (key == KEY_DOWN)
	pos = refresh_map(2, map, pos, caisse);
      else if (key == KEY_LEFT)
	pos = refresh_map(3, map, pos, caisse);
      else if (key == KEY_RIGHT)
	pos = refresh_map(4, map, pos, caisse);
      else if (key == 32)
	return (22);
    }
}

t_player	refresh_map(int i, char **map, t_player pos, t_caisse *caisse)
{
  test(i, pos, map);
  if (i == 1 && map[pos.y - 1][pos.x] != '#')
    pos = movecaisseh(map, pos, caisse);
  else if (i == 2 && map[pos.y + 1][pos.x] != '#')
    pos = movecaisseb(map, pos, caisse);
  else if (i == 4 && map[pos.y][pos.x + 1] != '#')
    pos = movecaissed(map, pos, caisse);
  else if (i == 3 && map[pos.y][pos.x - 1] != '#')
    pos = movecaisseg(map, pos, caisse);
  return (pos);
}
