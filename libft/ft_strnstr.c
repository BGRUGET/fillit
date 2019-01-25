/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:53:58 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 22:20:35 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (needle[y] == '\0')
		return ((char *)haystack);
	while (haystack[x])
	{
		while (haystack[x + y] == needle[y] && x + y < len)
		{
			y++;
			if (needle[y] == '\0')
				return ((char *)haystack + x);
		}
		y = 0;
		x++;
	}
	return (NULL);
}
