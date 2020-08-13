/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:07:42 by wronnel           #+#    #+#             */
/*   Updated: 2020/08/02 21:46:04 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int test(char *str)
{
	int count;

	count = 0;
	write(1,str,1);
	write(1,"\n",1);
	char mas[5] = {'1','2','3','4',' '};
	while (mas[count] != '\0')
	{
		if (mas[count] == *str)
			return (1);
		count++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char inp_data[16];
	int count;
	int j;

	j = 0;
	count = 0;
	if (argc != 2)
		return (1);
	while (argv[1][count] != '\0')
	{	
		if (test(&argv[1][count]) == 1)
		{
			if (argv[1][count] != ' ')
			{
				inp_data[j] = argv[1][count];
				j++;
			}
		}
		else
			return (1);
		count++;
	}
	if (j != 16)
	{
		write(1,"d",1);
		return (1);
	}
}



	
