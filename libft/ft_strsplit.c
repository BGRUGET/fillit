/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:39:26 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 09:48:28 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char			**ft_strlen_word(int ctr, int c, const char *s, char **str)
{
	int x;
	int start;
	int len;
	int k;

	x = 0;
	k = 0;
	while (ctr >= 0)
	{
		while (s[x] == c)
			x++;
		start = x;
		len = 0;
		while (s[x] != c && s[x] != '\0')
		{
			len++;
			x++;
		}
		if (!(str[k] = ft_strsub(s, start, len)))
			return (NULL);
		k++;
		ctr--;
	}
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	int		ctr;
	char	**str;

	if (!s | !c)
		return (NULL);
	ctr = ft_count_word_caract(s, c);
	if (!(str = malloc(sizeof(char *) * ctr + 1)))
		return (NULL);
	str[ctr] = (char *)'\0';
	ctr--;
	return (ft_strlen_word(ctr, c, s, str));
}
