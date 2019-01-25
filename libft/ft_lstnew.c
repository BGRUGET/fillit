/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 10:46:03 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 19:08:26 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, int content_size)
{
	t_list	*list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		list->tmp = NULL;
		list->fd = content_size;
	}
	else
	{
		list->tmp = ft_strdup(content);
		list->fd = content_size;
	}
	list->next = NULL;
	return (list);
}
