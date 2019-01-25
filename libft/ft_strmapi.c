/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:40:47 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:57:02 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		to_ret[x] = (*f)(x, s[x]);
		x++;
	}
	to_ret[x] = '\0';
	return (to_ret);
}
