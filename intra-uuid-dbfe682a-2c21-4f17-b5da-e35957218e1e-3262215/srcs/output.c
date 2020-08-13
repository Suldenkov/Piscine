/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:25:37 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 19:14:57 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int		min_value(int a, int b, int c)
{
	int m_v;

	m_v = a;
	if (m_v > b)
		m_v = b;
	if (m_v > c)
		m_v = c;
	return (m_v);
}

void	output_matrix(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_rows)
	{
		j = 0;
		while (j < g_columns)
		{
			if (g_matrix[i][j] == 1)
				write(1, &g_correct_symb[EMPTY], 1);
			else if (g_matrix[i][j] == 0)
				write(1, &g_correct_symb[OBSTRACTLE], 1);
			else
				write(1, &g_correct_symb[FULL], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	find_max_square(int **cp_matrix)
{
	int	i;
	int	j;

	i = 1;
	while (i < g_rows)
	{
		j = 1;
		while (j < g_columns)
		{
			if (g_matrix[i][j] == 1)
				cp_matrix[i][j] = 1 + min_value(cp_matrix[i][j - 1],
												cp_matrix[i - 1][j],
												cp_matrix[i - 1][j - 1]);
			else
				cp_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		find_square(void)
{
	int **cp_matrix;

	cp_matrix = create_fst_row_col();
	if (cp_matrix == NULL)
		return (-1);
	find_max_square(cp_matrix);
	if (create_full_cell(cp_matrix) == -1)
		return (-1);
	output_matrix();
	return (1);
}
