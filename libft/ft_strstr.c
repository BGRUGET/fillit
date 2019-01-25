/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:16:34 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:08:14 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (needle[y] == '\0')
		return ((char *)haystack);
	while (haystack[x])
	{
		while (haystack[x + y] == needle[y])
		{
			if (needle[y + 1] == '\0')
				return ((char *)haystack + x);
			y++;
		}
		y = 0;
		x++;
	}
	return (NULL);
}
