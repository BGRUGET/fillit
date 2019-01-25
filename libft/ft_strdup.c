/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:17:19 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:06:30 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*tab;
	int		len;

	x = 0;
	len = ft_strlen(s1);
	if ((tab = (char *)malloc(sizeof(*tab) * (len + 1))) == NULL)
		return (NULL);
	while (x < len)
	{
		tab[x] = s1[x];
		x++;
	}
	tab[x] = '\0';
	return (tab);
}
