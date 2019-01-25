/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 19:37:07 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 09:55:44 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			get_bn(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

t_list		*check_fd(t_list **list, int fd)
{
	t_list *maill;

	maill = *list;
	if (maill)
	{
		while (maill)
		{
			if (fd == maill->fd)
				return (maill);
			maill = maill->next;
		}
	}
	if (!(maill = ft_lstnew("", fd)))
		return (NULL);
	ft_lstadd(list, maill);
	return (*list);
}

static int	create_line(char **line, t_list **slist)
{
	int		x;
	int		len;
	char	*to_free;

	x = get_bn((*slist)->tmp, '\n');
	len = (ft_strlen((*slist)->tmp) - x);
	if (!(*line = ft_strsub((*slist)->tmp, 0, x)))
		return (-1);
	to_free = (*slist)->tmp;
	if (!((*slist)->tmp)[0])
		return (0);
	if (!((*slist)->tmp = ft_strsub((*slist)->tmp, (x + 1), (len))))
		return (-1);
	ft_strdel(&to_free);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	char			buff[BUFF_SIZE + 1];
	int				nbchar;
	t_list			*maill;
	char			*to_free;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	maill = check_fd(&list, fd);
	while (!(ft_strchr(maill->tmp, '\n')) &&
	(nbchar = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbchar] = '\0';
		to_free = maill->tmp;
		maill->tmp = ft_strjoin(to_free, buff);
		ft_strdel(&to_free);
	}
	if (nbchar == -1)
		return (-1);
	return (create_line(line, &maill));
}
