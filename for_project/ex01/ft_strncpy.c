/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:34:47 by wronnel           #+#    #+#             */
/*   Updated: 2020/07/25 21:38:44 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while (*src != '\0' && n != 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n != 0)
	{
		*(dest) = '\0';
		dest++;
		n--;
	}
	return (dest);
}
