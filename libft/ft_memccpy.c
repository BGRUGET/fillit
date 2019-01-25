/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:53:23 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 16:31:39 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
		if (((unsigned char *)src)[x] == (unsigned char)c)
			return ((unsigned char *)dst + x + 1);
		x++;
	}
	return (NULL);
}
