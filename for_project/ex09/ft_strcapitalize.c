/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:53:15 by wronnel           #+#    #+#             */
/*   Updated: 2020/07/25 20:58:33 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int flag;

	if ('a' <= *str && *str <= 'z')
		*str -= 32;
	str++;
	while (*str != '\0')
	{
		if ('a' <= *str && *str <= 'z')
			if ('0' > *(str - 1) || *(str - 1) > '9')
				if ('A' > *(str - 1) || *(str - 1) > 'Z')
					if ('a' > *(str - 1) || *(str - 1) > 'z')
					{
						*str -= 32;
						flag = 1;
					}
		str++;
	}
	return (str);
}
