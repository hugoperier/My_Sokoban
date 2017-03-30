/*
** my.h for my in /home/hugo/Projet/sysUnix/PSU_2016_my_sokoban
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Mon Dec 12 11:12:37 2016 Hugo Perier
** Last update Wed Dec 21 14:41:16 2016 Hugo Perier
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <fcntl.h>

typedef struct s_player
{
  int	x;
  int	y;
}t_player;

typedef struct s_caisse
{
  int	x;
  int	nb;
  int	y;
}t_caisse;

int	my_len(char *str, int pos);
int	my_nblen(char *str);
void	my_cpy(char **fichier, char *str);
void	my_get_file(char *path, char **fichier);
void	my_malloc(char ***fichier, char *str);
void	my_put_nbr(int nb);
int	getmaxl(char **str);
int	getmaxh(char **str);
void	my_string(char *str);
int	game_begin(char **map, char *cpy);
int	aff_map(char **map, t_caisse *caisse, char *cpy);
t_player	locate_player(char **file, t_player pos);
void	my_printf(char *str, ...);
void	bad_aff();
void	good_aff(char **map, t_player pos, t_caisse *caisse);
t_player	refresh_map(int i, char **map, t_player pos, t_caisse *caisse);
t_caisse	*getcaisse(t_caisse *caisse, char **map);
int	nbcaisse(char **map);
t_player movecaisseh(char **map, t_player pos, t_caisse *caisse);
t_player movecaisseb(char **map, t_player pos, t_caisse *caisse);
t_player movecaissed(char **map, t_player pos, t_caisse *caisse);
t_player movecaisseg(char **map, t_player pos, t_caisse *caisse);
int	checkcaisse(int nb, t_player pos, t_caisse *caisse, char **map);
int	checkcaisse2(int nb, t_player pos, t_caisse *caisse, char **map);
void	aff(char **map, t_caisse *caisse, t_player pos);
int	checkend(t_caisse *caisse, char **map);
int	checkblock(t_caisse *caisse, char **map, int i);
void	tireth();
void	quitsafe();
void	test(int arg, t_player pos, char **map);
void	testcaisse(int arg, t_caisse caisse, char **map);

#endif /* !MY_H_ */
