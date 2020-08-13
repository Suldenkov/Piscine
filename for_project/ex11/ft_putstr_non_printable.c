/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:22:18 by wronnel           #+#    #+#             */
/*   Updated: 2020/07/25 20:27:18 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	math(int mod, char c)
{
	if (mod == 10)
		write(1, "a", 1);
	else if (mod == 11)
		write(1, "b", 1);
	else if (mod == 12)
		write(1, "c", 1);
	else if (mod == 13)
		write(1, "d", 1);
	else if (mod == 14)
		write(1, "e", 1);
	else if (mod == 15)
		write(1, "f", 1);
	else
	{
		c = mod + '0';
		write(1, &c, 1);
	}
}

void	func(char *str)
{
	int		number;
	int		div;
	int		mod;
	char	c;

	c = '\\';
	write(1, &c, 1);
	number = *str;
	div = number / 16;
	c = div + '0';
	mod = number % 16;
	write(1, &c, 1);
	math(mod, c);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			func(str);
		}
		else
			write(1, str, 1);
		str++;
	}
}
