/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 15:46:52 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 18:41:06 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

t_point	new_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_coord	new_coord(int x, int y)
{
	t_coord coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

int		ft_racine_carre(int nb)
{
	int racine;
	int sqr;

	racine = 1;
	sqr = 0;
	while (racine <= nb / 2)
	{
		sqr = racine * racine;
		if (sqr == nb)
			return (racine);
		racine = racine + 1;
	}
	return (2);
}

int		ft_nb_tetri(char **av, int fd, char *line)
{
	int		x;

	x = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		x++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	x++;
	close(fd);
	return (x / 5);
}

void	ft_print_2dtab(char **tab, int len)
{
	int		x;

	x = 0;
	if (!tab)
		return ;
	while (x < len)
		ft_putendl(tab[x++]);
}
