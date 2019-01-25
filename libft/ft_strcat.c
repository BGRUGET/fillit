/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:38:11 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:05:08 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	x = ft_strlen(s1);
	while (s2[y])
	{
		s1[x + y] = s2[y];
		y++;
	}
	s1[x + y] = '\0';
	return (s1);
}
