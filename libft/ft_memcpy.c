/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:09:03 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:03:37 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				x;
	unsigned char		*dst1;
	unsigned char		*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	x = 0;
	while (x < n)
	{
		dst1[x] = src1[x];
		x++;
	}
	return (dst1);
}
