/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io_services.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:16:09 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 18:37:22 by mfiddles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

char	*read_file_to_str(int f_disc, int file_size, char *file_path)
{
	int		i;
	char	ch[1];
	char	*file_content;

	f_disc = open(file_path, O_RDONLY);
	if (f_disc == -1)
		return (NULL);
	i = 0;
	file_content = (char*)malloc((unsigned long)(file_size + 1));
	if (file_content == NULL)
		return (NULL);
	while (read(f_disc, ch, 1) > 0)
		file_content[i++] = ch[0];
	file_content[i] = '\0';
	close(f_disc);
	return (file_content);
}

int		find_file_size(int f_disc)
{
	char	buf[SIZE];
	int		file_size;
	long	true_bytes;

	file_size = 0;
	while ((true_bytes = read(f_disc, buf, SIZE)) > 0)
		file_size += true_bytes;
	close(f_disc);
	return (file_size);
}

int		*create_row(char *str)
{
	int		i;
	int		*row;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	row = (int*)malloc((unsigned long)i * sizeof(int));
	if (row == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == g_correct_symb[EMPTY])
			row[i] = 1;
		else if (str[i] == g_correct_symb[OBSTRACTLE])
			row[i] = 0;
		i++;
	}
	return (row);
}

int		read_to_matrix(char *file_content)
{
	int i;

	if (check_first_str(file_content) == 1 &&
		check_file_strs_len(file_content) == 1 &&
		return_file_columns(file_content) == 1)
	{
		if (g_rows == 0)
			return (0);
		i = 0;
		g_matrix = (int**)malloc((unsigned long)g_rows * sizeof(int*));
		if (g_matrix == NULL)
			return (-1);
		while (*file_content != '\n' && *file_content != '\0')
			file_content++;
		file_content++;
		while (i < g_rows)
		{
			g_matrix[i] = create_row(file_content);
			if (g_matrix[i++] == NULL)
				return (-1);
			file_content += g_columns + 1;
		}
		return (1);
	}
	return (0);
}

int		read_file_data(char *file_path)
{
	char	*file_content;
	int		file_size;
	int		f_disc;

	f_disc = open(file_path, O_RDONLY);
	if (f_disc == -1)
		return (0);
	file_size = find_file_size(f_disc);
	file_content = read_file_to_str(f_disc, file_size, file_path);
	if (file_content == NULL)
		return (-1);
	if (read_to_matrix(file_content) == 0)
		return (0);
	find_square();
	return (1);
}
