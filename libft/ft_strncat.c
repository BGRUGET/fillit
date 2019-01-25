/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:01:02 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:23:47 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (s1[x])
		x++;
	while (s2[y] && y < n)
	{
		s1[x + y] = s2[y];
		y++;
	}
	s1[x + y] = '\0';
	return (s1);
}
