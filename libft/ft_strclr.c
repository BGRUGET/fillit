/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:14:19 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 16:22:59 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return ;
	while (s[x] && s != NULL)
	{
		s[x++] = '\0';
	}
}
