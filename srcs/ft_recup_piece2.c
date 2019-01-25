/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_piece2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 18:54:13 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 12:35:49 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		top_left_x(char **tetri, int x, int y)
{
	while (x < 4)
	{
		if (tetri[x][y] == '#')
			return (1);
		x++;
	}
	return (0);
}

int		top_left_y(char **tetri, int x, int y)
{
	while (y < 4)
	{
		if (tetri[x][y] == '#')
			return (1);
		y++;
	}
	return (0);
}

t_coord	top_left_inter(char **tetri)
{
	t_coord	point;

	ft_memset(&point, 0, sizeof(t_coord));
	while (point.x < 4)
	{
		point.y = 0;
		while (point.y < 4)
		{
			if (top_left_x(tetri, point.x, point.y) &&
					top_left_y(tetri, point.x, point.y))
				return (point);
			point.y++;
		}
		point.x++;
	}
	point = new_coord(0, 0);
	return (point);
}

t_coord	*top_left(char **av, int fd, char *line)
{
	t_point	point;
	t_coord	*recup;
	char	***tab;
	int		nb;

	recup = NULL;
	nb = ft_nb_tetri(av, fd, line);
	if ((recup = (t_coord *)malloc(sizeof(*recup) * (nb + 1))) == NULL)
		return (recup);
	tab = recup_piece(av, fd, line);
	point.k = 0;
	while (tab[point.k])
	{
		recup[point.k] = top_left_inter(tab[point.k]);
		point.k++;
	}
	ft_free(tab, point);
	return (recup);
}

void	ft_free(char ***tab, t_point point)
{
	point.i = 0;
	while (tab[point.i])
	{
		point.j = 0;
		while (tab[point.i][point.j])
		{
			free(tab[point.i][point.j]);
			point.j++;
		}
		free(tab[point.i]);
		point.i++;
	}
	free(tab);
}
