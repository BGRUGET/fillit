/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:16:27 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 12:37:25 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lstdel;
	t_list	*next_list;

	lstdel = *alst;
	while (lstdel)
	{
		next_list = lstdel->next;
		del(lstdel->content, lstdel->content_size);
		free(lstdel);
		lstdel = next_list;
	}
	*alst = NULL;
}
