/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:41:56 by wronnel           #+#    #+#             */
/*   Updated: 2020/08/08 15:28:11 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int count;
//	t_list *dict;
	char sumb[21];
	int fd;

	count = 0;
	if((fd = open("numbers.dict", O_RDONLY)) == -1)
	{
		write(1,"error\n",6);
		return (0);
	}
	while ((count = read(fd, &sumb, 20)) > 0)
	{
		sumb[count] = 0;
		write(1, sumb, count);
	}
}
