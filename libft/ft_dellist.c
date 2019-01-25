/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dellist.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 10:47:31 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 10:48:02 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

static void		ft_freelist(t_list *list)
{
	free(list->content);
	list->content = NULL;
	free(list);
	list = NULL;
}

t_list			*ft_dellist(t_list *start, t_list *list)
{
	t_list	*tmp;

	tmp = start;
	if (list == start)
	{
		start = list->next;
		ft_freelist(list);
		return (start);
	}
	else if (list->next == NULL)
	{
		while (start->next != list)
			start = start->next;
		start->next = NULL;
		ft_freelist(list);
	}
	else if (list->next != NULL)
	{
		while (start->next != list)
			start = start->next;
		start->next = start->next->next;
		ft_freelist(list);
		list->next = NULL;
	}
	return (tmp);
}
