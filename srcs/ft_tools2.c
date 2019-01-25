/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 18:16:14 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 10:30:36 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		ft_tabllen(char **tab)
{
	int	x;

	x = 0;
	if (!tab)
		return (0);
	while (tab[x])
		x++;
	return (x);
}

char	**ft_create_2dtab(int width, int height, int c)
{
	char	**map;
	int		x;

	if (!(map = (char**)ft_memalloc(sizeof(char*) * (height + 1))))
		return (NULL);
	x = 0;
	while (x < height)
	{
		map[x] = ft_strnew(width);
		map[x] = (char*)ft_memset(map[x], c, width);
		x++;
	}
	map[x] = NULL;
	return (map);
}

void	ft_free_all(char **map, t_coord **tetri, t_point lt)
{
	free_map(map, lt);
	free_tetri(tetri, lt);
}

int		ft_free_pars(t_point pt, char *line, char *tab[5])
{
	while (tab[pt.i])
	{
		ft_strdel(&(tab[pt.i]));
		pt.i++;
	}
	ft_strdel(tab);
	ft_strdel(&line);
	return (1);
}

void	ft_index(char *tab[5], t_point pt, char *line)
{
	if (pt.ind % 5 == 4)
		pt.nb = pt.nb + 1;
	if (pt.ind % 5 != 4)
		tab[pt.ind % 5] = ft_strdup(line);
}
