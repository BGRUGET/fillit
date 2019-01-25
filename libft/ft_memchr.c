/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:18:00 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:58:31 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;

	x = 0;
	while (x < n)
	{
		if (((unsigned char *)s)[x] == (unsigned char)c)
			return ((unsigned char *)s + x);
		x++;
	}
	return (NULL);
}
