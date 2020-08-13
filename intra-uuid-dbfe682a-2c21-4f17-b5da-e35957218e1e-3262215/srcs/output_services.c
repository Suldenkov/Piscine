/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_services.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:09:28 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/11 21:41:24 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	full_cell_init(t_point *max_values)
{
	int i;
	int j;

	i = max_values->x;
	while (i > max_values->x - max_values->size)
	{
		j = max_values->y;
		while (j > max_values->y - max_values->size)
		{
			g_matrix[i][j] = g_correct_symb[FULL];
			j--;
		}
		i--;
	}
}

int		**create_fst_row_col(void)
{
	int i;
	int j;
	int	**cp_matrix;

	i = 0;
	cp_matrix = (int**)malloc((unsigned long)g_rows * sizeof(int*));
	if (cp_matrix == NULL)
		return (NULL);
	while (i < g_rows)
	{
		cp_matrix[i] = (int*)malloc((unsigned long)g_columns * sizeof(int));
		if (cp_matrix[i] == NULL)
			return (NULL);
		cp_matrix[i][0] = g_matrix[i][0];
		i++;
	}
	j = 0;
	while (j < g_columns)
	{
		cp_matrix[0][j] = g_matrix[0][j];
		j++;
	}
	return (cp_matrix);
}

int		init_full_cell(t_point **max_values)
{
	*max_values = malloc(sizeof(t_point));
	if (max_values == NULL)
		return (-1);
	(*max_values)->x = 0;
	(*max_values)->y = 0;
	(*max_values)->size = 0;
	return (1);
}

int		create_full_cell(int **cp_matrix)
{
	int		i;
	int		j;
	t_point	*max_values;

	i = 0;
	if (init_full_cell(&max_values) == -1)
		return (-1);
	while (i < g_rows)
	{
		j = 0;
		while (j < g_columns)
		{
			if (max_values->size < cp_matrix[i][j])
			{
				max_values->x = i;
				max_values->y = j;
				max_values->size = cp_matrix[i][j];
			}
			j++;
		}
		i++;
	}
	full_cell_init(max_values);
	return (1);
}
