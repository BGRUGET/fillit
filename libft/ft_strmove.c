/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 19:40:12 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 09:51:13 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strmove :
**
** Remove the fisrt part of the string from a new given start.
** Fill the end with '\0'.
*/

void	ft_strmove(char *begin_str, char *new_begin)
{
	size_t	new_len;

	new_len = ft_strlen(new_begin);
	ft_memmove(begin_str, new_begin, new_len);
	ft_bzero(begin_str + new_len, new_begin - begin_str);
}
