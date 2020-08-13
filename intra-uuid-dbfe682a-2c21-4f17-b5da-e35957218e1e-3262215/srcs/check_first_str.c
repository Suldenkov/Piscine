/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:25:42 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 19:26:33 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int		ft_atoi(char *str, int size)
{
	int number;
	int result;
	int count;

	number = 1;
	result = 0;
	count = 0;
	while (count != size)
	{
		if (ft_is_digit(str[count]) == 1)
			result = result * 10 + (str[count] - '0');
		else
			break ;
		count++;
	}
	return (result * number);
}

int		read_fst_row(int *start, int *finish, char *file_content)
{
	int is_symbol;
	int	i;

	is_symbol = 0;
	i = 0;
	while (file_content[i] != '\n' && file_content[i] != '\0')
	{
		if (ft_str_is_printable(file_content[i]) == 1)
		{
			if (is_symbol == 0)
				*start = i;
			is_symbol = 1;
			*finish = i;
		}
		i++;
	}
	return (i);
}

int		check_digit(int size, char *fst_row)
{
	int count;

	count = 0;
	while (count < size - 2)
	{
		if (ft_is_digit(fst_row[count]) == 0)
			return (0);
		count++;
	}
	return (1);
}

int		check_field_param(int size, char *fst_row)
{
	if (fst_row[size] == fst_row[size - 1] ||
		fst_row[size] == fst_row[size - 2])
		return (0);
	else if (fst_row[size - 1] == fst_row[size - 2])
		return (0);
	g_correct_symb[EMPTY] = fst_row[size - 2];
	g_correct_symb[OBSTRACTLE] = fst_row[size - 1];
	g_correct_symb[FULL] = fst_row[size];
	return (1);
}

int		check_first_str(char *file_content)
{
	int		size;
	int		i;
	int		start;
	int		finish;
	char	*fst_row;

	size = 0;
	i = read_fst_row(&start, &finish, file_content);
	if ((i = check_space(file_content, i)) == 0)
		return (0);
	size = finish - start;
	if (file_content[i] == '\0' || size < 3)
		return (0);
	i = 0;
	fst_row = (char*)malloc((unsigned long)(finish - start + 2));
	if (fst_row == NULL)
		return (-1);
	while (start <= finish)
		fst_row[i++] = file_content[start++];
	fst_row[i] = '\0';
	if (check_digit(size, fst_row) == 0 ||
		check_field_param(size, fst_row) == 0)
		return (0);
	g_rows = ft_atoi(fst_row, size - 2);
	return (1);
}
