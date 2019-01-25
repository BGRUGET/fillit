/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_piece.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 17:59:42 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 19:22:42 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int			ft_istoomuch(char **av)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		x++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (x);
}

char		***recup_piece(char **av, int fd, char *line)
{
	t_point	co;

	ft_memset(&co, 0, sizeof(t_point));
	fd = open(av[1], O_RDONLY);
	co.nb = ft_nb_tetri(av, fd, line);
	if ((co.tab = (char ***)malloc(sizeof(char **) * (co.nb + 1))) == NULL)
		return (NULL);
	co.tab[co.nb] = NULL;
	if ((co.tab[0] = (char **)malloc(sizeof(char *) * (4 + 1))) == NULL)
		return (NULL);
	co.tab[0][4] = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (co.x == 4)
		{
			co.k++;
			co.x = 0;
			ft_malloc(&co);
		}
		else
			co.tab[co.k][co.x++] = ft_strdup(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (co.tab);
}

void		ft_malloc(t_point *co)
{
	if (!(co->tab[co->k] = (char **)malloc(sizeof(char *) * (4 + 1))))
		return ;
	co->tab[co->k][4] = NULL;
}

void		ft_free_tab(char ***tab, t_point point)
{
	point.i = 0;
	while (tab[point.i])
	{
		free(tab[point.i][0]);
		free(tab[point.i][1]);
		free(tab[point.i][2]);
		free(tab[point.i][3]);
		free(tab[point.i]);
		point.i++;
	}
	free(tab);
}

void		norme_coord(t_point point, t_point lt, t_coord **rec, t_coord *tp)
{
	while (lt.tab[point.k][point.coord.x])
	{
		point.coord.y = 0;
		while (lt.tab[point.k][point.coord.x][point.coord.y])
		{
			if (lt.tab[point.k][point.coord.x][point.coord.y] == '#')
				rec[point.k][point.nb_dieze++] = new_coord(point.coord.x -
				tp[point.k].x, point.coord.y - tp[point.k].y);
			point.coord.y++;
		}
		point.coord.x++;
	}
}
