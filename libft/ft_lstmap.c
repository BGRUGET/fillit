/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 13:03:06 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 13:30:39 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;
	t_list	*start;

	if (!lst)
		return (NULL);
	temp = f(lst);
	new = ft_lstnew(temp->content, temp->content_size);
	if (new == NULL)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = f(lst);
		new->next = ft_lstnew(temp->content, temp->content_size);
		if (new->next == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
