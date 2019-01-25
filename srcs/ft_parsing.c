/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:13:48 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 10:31:16 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		ft_fillit_error(char *tab[5])
{
	t_point		coord;

	coord.x = 0;
	coord.y = 0;
	while (tab[coord.x])
	{
		coord.y = 0;
		while (tab[coord.x][coord.y])
		{
			if (!(tab[coord.x][coord.y] == '.' || tab[coord.x][coord.y] == '#'))
				return (1);
			coord.y++;
		}
		if (coord.y != 4)
			return (1);
		coord.x++;
	}
	return (0);
}

int		ft_fillit_tetri(char *tab[5], char **av)
{
	t_point	coord;
	int		count;
	int		maxx;
	int		count_dieze;

	coord = new_point(0, 0);
	maxx = ft_istoomuch(av);
	count = ft_fillit_place(tab, coord);
	count_dieze = ft_count_dieze(tab, coord);
	if (!(count == 6 || count == 8) || count_dieze == 1 || maxx > 129)
		return (1);
	return (0);
}

int		ft_count_dieze(char *tab[5], t_point coord)
{
	int		count_dieze;
	int		i;

	count_dieze = 0;
	while (tab[coord.x])
	{
		coord.y = 0;
		while (tab[coord.x][coord.y])
		{
			if (tab[coord.x][coord.y] == '#')
				count_dieze++;
			if (count_dieze > 4)
				return (1);
			coord.y++;
		}
		coord.x++;
	}
	i = 0;
	while (tab[i])
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	ft_strdel(tab);
	return (0);
}

int		ft_fillit_place(char *tab[5], t_point coord)
{
	int		count;

	count = 0;
	while (tab[coord.x])
	{
		coord.y = 0;
		while (tab[coord.x][coord.y])
		{
			if (tab[coord.x][coord.y] == '#')
			{
				if (((coord.y + 1 < 4)) && (tab[coord.x][coord.y + 1]) == '#')
					count++;
				if (((coord.y - 1 >= 0)) && (tab[coord.x][coord.y - 1]) == '#')
					count++;
				if (((coord.x + 1 < 4)) && (tab[coord.x + 1][coord.y]) == '#')
					count++;
				if (((coord.x - 1 >= 0)) && (tab[coord.x - 1][coord.y]) == '#')
					count++;
			}
			coord.y++;
		}
		coord.x++;
	}
	return (count);
}

int		ft_read(char **av, int fd, char *line)
{
	char	*tab[5];
	t_point pt;

	ft_memset(&pt, 0, sizeof(t_point));
	fd = open(av[1], O_RDONLY);
	tab[4] = NULL;
	pt.nb = ft_nb_tetri(av, fd, line);
	while (get_next_line(fd, &line) == 1)
	{
		if (free_line(pt, line))
			return (1);
		ft_index(tab, pt, line);
		if (pt.ind % 5 == 3)
		{
			if (ft_fillit_error(tab) || ft_fillit_tetri(tab, av) == 1)
				return (ft_free_pars(pt, line, tab));
		}
		ft_strdel(&line);
		pt.ind++;
	}
	ft_strdel(&line);
	return ((pt.ind % 5 != 4) ? ft_free_pars(pt, line, tab) : 0);
}
