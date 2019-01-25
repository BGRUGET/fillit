/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 11:58:49 by theophilema  #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 18:18:41 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"
#include <stdio.h>

char	**place_tetri(t_coord *tetri, t_tetri ptn, char **map, char carac)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((ptn.x + tetri[i].x >= ft_tabllen(map)) ||
		(ptn.y + tetri[i].y >= (int)ft_strlen(map[0])))
			return (NULL);
		if (map[tetri[i].x + ptn.x][tetri[i].y + ptn.y] != '.')
			return (NULL);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map[tetri[i].x + ptn.x][tetri[i].y + ptn.y] = carac;
		i++;
	}
	return (map);
}

char	**remove_tetri(t_coord *tetri, t_tetri ptn, char **map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		(map[tetri[i].x + ptn.x][tetri[i].y + ptn.y] = '.');
		i++;
	}
	return (map);
}

int		backtracking_algo(int map_size, t_coord **tetri, char **map, t_point t)
{
	t_tetri ptn;
	t_point tet_;

	ft_memset(&ptn, 0, sizeof(t_tetri));
	if (tetri[t.j] == NULL)
		return (1);
	while (ptn.x < map_size)
	{
		ptn.y = -1;
		while (ptn.y++ < map_size)
		{
			if ((place_tetri(tetri[t.j], ptn, map, t.let)) != NULL)
			{
				tet_.let = t.let + 1;
				tet_.j = t.j + 1;
				if (backtracking_algo(map_size, tetri, map, tet_))
					return (1);
				remove_tetri(tetri[t.j], ptn, map);
				t.let = t.j + 'A';
			}
		}
		ptn.x++;
	}
	return (0);
}

char	**ft_create_map(char **av, int fd, char *line)
{
	char	**map;
	int		index;
	int		x;
	int		in;

	index = 0;
	x = ft_nb_tetri(av, fd, line);
	in = ft_racine_carre(x * 4);
	if ((map = (char **)malloc(sizeof(char **) * (in + 1))) == NULL)
		return (NULL);
	while (index < in)
	{
		if (!(map[index] = ft_strnew(in)))
			return (NULL);
		ft_memset(map[index], '.', in);
		index++;
	}
	map[index] = NULL;
	return (map);
}
