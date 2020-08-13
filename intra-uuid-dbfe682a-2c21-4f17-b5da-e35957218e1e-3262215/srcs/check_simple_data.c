/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:18:21 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 21:03:43 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int		ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != 0)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_str_is_printable(char ch)
{
	if (ch < ' ')
		return (0);
	return (1);
}

int		ft_is_digit(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return (1);
	return (0);
}
