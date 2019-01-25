/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 18:26:01 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:39:39 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
