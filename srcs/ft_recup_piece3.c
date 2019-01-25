/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_piece3.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 18:44:29 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 10:14:49 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

t_coord		**coord_point(char **av, t_point lt)
{
	t_point point;
	t_coord	**rec;
	t_coord *top_leftt;

	rec = NULL;
	ft_memset(&point, 0, sizeof(t_point));
	point.nb = ft_nb_tetri(av, lt.fd, lt.line);
	if ((rec = malloc(sizeof(*rec) * (point.nb + 1))) == NULL)
		return (NULL);
	rec[point.nb] = NULL;
	while (lt.tab[point.k])
	{
		point.coord.x = 0;
		point.nb_dieze = 0;
		top_leftt = top_left(av, lt.fd, lt.line);
		malloc_rec(rec, point);
		norme_coord(point, lt, rec, top_leftt);
		point.k++;
		free(top_leftt);
	}
	ft_free_hikoudri(lt);
	return (rec);
}

void		malloc_rec(t_coord **rec, t_point point)
{
	if ((rec[point.k] = (t_coord *)malloc(sizeof(*rec) * (4 + 1))) == NULL)
		return ;
}

void		ft_free_hikoudri(t_point lt)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (lt.tab[i])
	{
		y = 0;
		while (lt.tab[i][y])
			free(lt.tab[i][y++]);
		free(lt.tab[i]);
		i++;
	}
	free(lt.tab);
}

int			free_line(t_point pt, char *line)
{
	if (pt.ind % 5 == 4 && *line)
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}
