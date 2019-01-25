/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:14:52 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 11:32:39 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	len_dst;
	size_t	len_src;

	x = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size - 1 < len_dst)
		return (len_src + size);
	while (len_dst + x < size - 1)
	{
		dst[len_dst + x] = src[x];
		x++;
	}
	dst[len_dst + x] = '\0';
	return (len_dst + len_src);
}
