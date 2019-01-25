/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_word_caract.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 15:17:13 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:02:39 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_count_word_caract(char const *s, char c)
{
	int		x;
	int		count_word;

	x = 0;
	count_word = 0;
	if (s[0] != c && s[0])
		count_word++;
	while (s[x])
	{
		if (s[x] == c && s[x + 1] != c && s[x + 1])
			count_word++;
		x++;
	}
	return (count_word);
}
