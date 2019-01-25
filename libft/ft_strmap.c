/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:40:58 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 10:40:59 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		x;
	char	*to_ret;

	x = 0;
	if (!s || !f)
		return (NULL);
	if ((to_ret = (char *)ft_memalloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[x])
	{
		to_ret[x] = (*f)(s[x]);
		x++;
	}
	to_ret[x] = '\0';
	return (to_ret);
}
