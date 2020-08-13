/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:38:39 by wronnel           #+#    #+#             */
/*   Updated: 2020/08/04 21:17:50 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	show_eror(char *s_name, char *name)
{
	char	*str;
	int		count;

	count = 0;
	str = strerror(errno);
	while (*name != '\0')
	{
		write(2, name, 1);
		name++;
	}
	write(2, ": ", 2);
	while (*s_name != '\0')
	{
		write(2, s_name, 1);
		s_name++;
	}
	write(2, ": ", 2);
	while (str[count] != '\0')
	{
		write(2, &str[count], 1);
		count++;
	}
	write(1, "\n", 1);
}

int		w_file(char *argv, char *name)
{
	char	str[29001];
	int		fd;
	int		count;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		show_eror(argv, basename(name));
		return (-1);
	}
	while ((count = read(fd, &str, 29000)) > 0)
	{
		str[count] = 0;
		write(1, str, count);
	}
	if (count == -1)
	{
		show_eror(argv, basename(name));
		return (-1);
	}
	close(fd);
	return (0);
}

void	infinity(void)
{
	char simb;

	while (1)
	{
		read(0, &simb, 1);
		write(1, &simb, 1);
	}
}

int		main(int argc, char **argv)
{
	int		j;

	j = 1;
	if (argc < 2 || argv[1][0] == '-')
		infinity();
	else
	{
		while (j != argc)
		{
			if (argv[j][0] == '-')
				if (argv[j][1] == ' ' || argv[j][1] == '\0')
					infinity();
			w_file(argv[j], argv[0]);
			j++;
		}
	}
	return (0);
}
