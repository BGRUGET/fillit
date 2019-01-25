/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 14:47:47 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 15:57:16 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(int n, int nb)
{
	ft_putchar('[');
	ft_putchar(n + 48);
	ft_putchar(',');
	ft_putchar(nb + 48);
	ft_putchar(']');
	ft_putchar('\n');
}

void		ft_putnbr2(int n, int nb)
{
	if (n == -2147483648 || nb == -2147483648)
	{
		ft_putestr("-2147483648");
		ft_putestr("-2147483648");
	}
	if ((n >= 0 && n <= 9) && (nb >= 0 && nb <= 9))
		ft_print(n, nb);
	if ((n < 0) && nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if ((n >= 10) && nb >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
