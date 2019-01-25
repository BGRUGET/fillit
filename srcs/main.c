/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 11:55:23 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 10:51:51 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int			main(int argc, char **argv)
{
	char	**map;
	t_point lt;

	lt.fd = 0;
	lt.line = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit souce_file");
		return (0);
	}
	if (ft_read(argv, lt.fd, lt.line) == 1)
		return (write(1, "error\n", 6));
	if (argc == 2)
	{
		map = ft_create_map(argv, lt.fd, lt.line);
		main2(argv, lt, map);
	}
	return (0);
}

void		free_map(char **map, t_point lt)
{
	lt.i = 0;
	while (map[lt.i])
		free(map[lt.i++]);
	free(map);
}

void		free_tetri(t_coord **tetri, t_point lt)
{
	lt.i = 0;
	while (tetri[lt.i])
		free(tetri[lt.i++]);
	free(tetri);
}

void		main2(char **av, t_point lt, char **map)
{
	t_tetri ptn;
	t_coord **tetri;

	lt.let = 'A';
	lt.j = 0;
	tetri = NULL;
	lt.nb = ft_nb_tetri(av, lt.fd, lt.line);
	lt.size = ft_tabllen(map);
	lt.tab = recup_piece(av, lt.fd, lt.line);
	tetri = coord_point(av, lt);
	ft_memset(&ptn, 0, sizeof(t_tetri));
	while (!(backtracking_algo(lt.size, tetri, map, lt)))
	{
		lt.size++;
		free_map(map, lt);
		map = ft_create_2dtab(lt.size, lt.size, '.');
	}
	ft_print_2dtab(map, ft_tabllen(map));
	ft_free_all(map, tetri, lt);
	return ;
}
