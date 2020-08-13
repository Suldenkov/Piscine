/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:23:58 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 12:53:01 by mfiddles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	free_all(void)
{
	int i;

	i = 0;
	if (g_matrix != NULL)
	{
		while (i < g_rows)
			free(g_matrix[i++]);
		free(g_matrix);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (write_map() == 0)
			write(1, "map error\n", 10);
		free_all();
		return (0);
	}
	check_argv(argc, argv);
	return (0);
}
