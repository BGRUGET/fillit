/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcharlen.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 11:55:26 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 11:38:54 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcharlen(char *str, char c)
{
	size_t x;

	x = 0;
	while (str[x] && str[x] != c)
		x++;
	return (x);
}
