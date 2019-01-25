/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:55:47 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:34:49 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		if (((unsigned char *)s1)[x] != ((unsigned char *)s2)[x])
			return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
		x++;
	}
	return (0);
}
