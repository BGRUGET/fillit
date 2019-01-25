/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrimfillit.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 18:05:34 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 18:06:32 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimfillit(char const *s, char c)
{
	int		start;
	int		len;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] == c)
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while (s[len] == c)
		len--;
	len = len - start;
	return (ft_strsub(s, start, len + 1));
}
