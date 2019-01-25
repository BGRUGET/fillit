/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:13:27 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 18:14:03 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	*tab;
	int	x;

	x = 0;
	if (min >= max)
		return (NULL);
	if ((tab = (int*)malloc(sizeof(*tab) * (max - min))) == NULL)
		return (NULL);
	while (min < max)
		tab[x++] = min++;
	return (tab);
}
