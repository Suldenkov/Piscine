/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:38:28 by wronnel           #+#    #+#             */
/*   Updated: 2020/07/26 10:15:53 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int len;
	
	len = 0;
	while (*src != '\0' && size - 1 != 0)
	{
		dest[len] = src[len];
		len++;
		size--;
	}
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dest[len] = '\0';
	return (len);
}

int main()
{
   const char *str = "образец строки";
   char  buf[10] = "sadfasdaf";

   sz = ft_strlcpy(buf, str, 9);    

   return 0;
}
	
