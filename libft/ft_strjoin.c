/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:03:20 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 10:35:17 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	len;
	char	*to_ret;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	x = 0;
	if ((to_ret = (char *)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	ft_strcpy(to_ret, s1);
	ft_strcat(to_ret, s2);
	return (to_ret);
}
