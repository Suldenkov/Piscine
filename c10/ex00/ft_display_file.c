/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 10:41:03 by wronnel           #+#    #+#             */
/*   Updated: 2020/08/04 21:12:36 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	show_buf(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	str[29001];
	int		count;

	fd = open(argv[1], O_RDONLY);
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else if (argc < 2)
		write(1, "File name missing.\n", 19);
	else if (fd < 0)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	else
	{
		while ((count = read(fd, &str, 29000)) > 0)
		{
			str[count] = 0;
			write(1, &str, count);
		}
		if (count == -1)
		{
			write(1, "Cannot read file.\n",18);
		   return (0);
		}	   
	}
	return (1);
}
