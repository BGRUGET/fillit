/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:25:18 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:06:08 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	x;
	size_t	len;

	x = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (s[x])
	{
		if (s[x] == c)
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}
