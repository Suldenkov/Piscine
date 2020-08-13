/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:17:30 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 21:09:00 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int		check_f_struct(char *cp_f_c, int i, int start_row)
{
	i = 0;
	if (*cp_f_c == '\n')
		return (0);
	while (cp_f_c[i] != '\0')
	{
		if (cp_f_c[i] != '\n' &&
				check_file_params(cp_f_c[i]) == 0)
			return (0);
		if (ft_str_is_printable(cp_f_c[i]) == 0 &&
			cp_f_c[i] != '\n')
			return (0);
		if (cp_f_c[i] == '\n')
		{
			if (start_row == 0)
				g_columns = i;
			start_row = 1;
			if (g_columns != i)
				return (0);
			cp_f_c += i + 1;
			i = -1;
		}
		i++;
	}
	return (1);
}

int		check_space(char *file_content, int i)
{
	while (file_content[i] != '\n' && file_content[i] != '\0')
	{
		if (ft_str_is_printable(file_content[i]) == 1)
			return (0);
		i++;
	}
	return (i);
}

int		check_file_params(char ch)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 2)
	{
		if (ch == g_correct_symb[i])
			flag = 1;
		i++;
	}
	return (flag);
}

int		return_file_columns(char *file_content)
{
	int		i;
	int		start_row;
	char	*cp_f_c;

	i = 0;
	start_row = 0;
	g_columns = 0;
	cp_f_c = file_content;
	while (cp_f_c[i] != '\n')
		i++;
	cp_f_c += i + 1;
	i = 0;
	if (cp_f_c[i] == '\0')
		return (0);
	if (check_f_struct(cp_f_c, i, start_row) == 0)
		return (0);
	return (1);
}

int		check_file_strs_len(char *file_content)
{
	int		i;
	int		rows;
	char	*cp_f_c;

	i = 0;
	rows = 0;
	cp_f_c = file_content;
	while (cp_f_c[i] != '\n' &&
			cp_f_c[i] != '\0')
		i++;
	if (cp_f_c[i] == '\0')
		return (0);
	while (cp_f_c[i] != '\0')
	{
		if (cp_f_c[i] == '\n')
			rows++;
		i++;
	}
	if (cp_f_c[i] == '\0')
		rows--;
	if (g_rows != rows)
		return (0);
	return (1);
}
