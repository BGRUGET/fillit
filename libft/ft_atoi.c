/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 22:22:39 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 10:50:55 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int				x;
	long long int	sign;
	long long int	result;

	x = 0;
	sign = 1;
	result = 0;
	while (str[x] == '\t' || str[x] == '\n' || str[x] == '\r' ||
		str[x] == '\v' || str[x] == '\f' || str[x] == ' ')
		x++;
	if (str[x] == '+' && str[x + 1] != '-')
		x++;
	if (str[x] == '-')
	{
		sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		result = (result + str[x] - 48) * 10;
		x++;
	}
	return ((result * sign) / 10);
}
