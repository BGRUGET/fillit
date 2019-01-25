/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 16:33:46 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 16:36:14 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	size_t				x;
	unsigned char		*dst1;
	unsigned char		*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	x = n;
	while (x > 0)
	{
		x--;
		dst1[x] = src1[x];
	}
	return (dst1);
}
