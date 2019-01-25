/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_next_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 12:00:52 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 15:09:14 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	return_value(char *tmp, int ret)
{
	if (!*tmp && ret == 0)
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

static int	create_line(char **line, char *tmp, char *tab[10240], int fd)
{
	int		x;
	int		len;
	char	*tmp_2;

	x = ft_strcharlen(tmp, '\n');
	if (!(*line = ft_strsub(tmp, 0, x)))
		return (-1);
	len = (ft_strlen(tmp) - x);
	tmp_2 = tab[fd];
	if (!(tab[fd] = ft_strsub(tmp, (x + 1), (len))))
		return (-1);
	ft_strdel(&tmp_2);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tab[10240];
	char			buf[BUFF_SIZE + 1];
	char			*to_free;
	char			*tmp;
	int				nb_char;

	tmp = NULL;
	to_free = NULL;
	if (fd < 0 || fd >= 10240 || !line || BUFF_SIZE < 1 ||
	read(fd, buf, 0) == -1 || (!tab[fd] && (!(tmp = ft_strnew(0)))))
		return (-1);
	if (tab[fd])
		tmp = ft_strdup(tab[fd]);
	while (!(ft_strchr(tmp, '\n')) && (nb_char = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb_char] = '\0';
		to_free = tmp;
		tmp = ft_strjoin(to_free, buf);
		ft_strdel(&to_free);
	}
	if (create_line(line, tmp, tab, fd) == -1)
		return (-1);
	return (return_value(tmp, nb_char));
}
