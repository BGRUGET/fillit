/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_word.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 14:24:57 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 14:36:29 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_count_word(char *str)
{
	int	x;
	int	count_word;

	x = 0;
	count_word = 0;
	if (ft_isspace(str[0]) == 0 && str[0])
		count_word++;
	while (str[x])
	{
		if (ft_isspace(str[x]) == 1 && ft_isspace(str[x + 1]) == 0 &&
			str[x + 1])
			count_word++;
		x++;
	}
	return (count_word);
}
