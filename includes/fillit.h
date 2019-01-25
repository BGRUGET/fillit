/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:14:16 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 10:59:13 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_point
{
	int				x;
	int				y;
	int				count;
	int				count_dieze;
	int				max;
	int				k;
	int				nb_dieze;
	int				nb;
	char			***tmp;
	int				size;
	int				i;
	int				j;
	char			let;
	int				ind;
	char			***tab;
	int				fd;
	char			*line;
	t_coord			coord;
}					t_point;

typedef struct		s_tetri
{
	int				x;
	int				y;
}					t_tetri;

typedef	struct		s_norme
{
	int				i;
	char			let;
}					t_norme;

typedef	struct		s_struc
{
	int				i;
	char			let;
}					t_struc;

int					ft_read(char **av, int fd, char *line);
int					ft_fillit_place(char *tab[5], t_point coord);
char				***recup_piece(char **av, int fd, char *line);
int					ft_count_dieze(char *tab[5], t_point coord);
int					ft_istoomuch(char **av);
t_point				new_point(int x, int y);
int					ft_racine_carre(int nb);
char				**ft_create_map(char **av, int fd, char *line);
t_coord				**coord_point(char **av, t_point lt);
t_coord				new_coord(int x, int y);
int					top_left_y(char **tetri, int x, int y);
t_coord				*top_left(char **av, int fd, char *line);
int					top_left_x(char **tetri, int x, int y);
t_coord				top_left_inter(char **tetri);
int					ft_nb_tetri(char **av, int fd, char *line);
char				**ft_create_2dtab(int width, int height, int c);
void				ft_print_2dtab(char **tab, int len);
int					ft_tabllen(char **tab);
int					backtracking_algo(int map_size, t_coord **tetri, char **map,
					t_point t);
void				main2(char **argv, t_point lt, char **map);
char				**place_tetri(t_coord *tetri, t_tetri ptn,
					char **map, char carac);
void				ft_free_all(char **map, t_coord **tetri, t_point lt);
void				free_tetri(t_coord **tetri, t_point lt);
void				free_map(char **map, t_point lt);
void				ft_malloc(t_point *co);
void				malloc_rec(t_coord **rec, t_point point);
void				ft_free_tab(char ***tab, t_point point);
void				norme_coord(t_point point, t_point lt, t_coord **rec,
					t_coord *tp);
void				ft_free(char ***tab, t_point point);
void				ft_free_hikoudri(t_point lt);
int					ft_free_pars(t_point pt, char *line, char *tab[5]);
int					ft_fillit_tetri(char *tab[5], char **av);
int					ft_fillit_error(char *tab[5]);
void				ft_index(char *tab[5], t_point pt, char *line);
int					free_line(t_point pt, char *line);

#endif
