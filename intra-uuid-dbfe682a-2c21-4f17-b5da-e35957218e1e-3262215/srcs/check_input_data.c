/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:16:34 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 20:10:24 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int			write_map(void)
{
	int		i;
	int		buf_size;
	long	col;
	char	*buf_content;
	char	buf[SIZE];

	i = 0;
	g_columns = 0;
	buf_size = 0;
	while ((col = read(0, buf + buf_size, SIZE)))
		buf_size += col;
	buf_content = (char*)malloc((unsigned long)(buf_size + 1));
	while (i < buf_size)
	{
		buf_content[i] = buf[i];
		i++;
	}
	buf_content[i] = '\0';
	if (read_to_matrix(buf_content) == 0)
		return (0);
	find_square();
	return (1);
}

int			check_argv(int size, char **file_name)
{
	int count;
	int fd;

	fd = 0;
	count = 1;
	while (count != size)
	{
		fd = read_file_data(file_name[count]);
		if (fd == 0)
			write(1, "map error\n", 10);
		count++;
		if (size > 1 && count != size)
			write(1, "\n", 1);
	}
	return (0);
}
