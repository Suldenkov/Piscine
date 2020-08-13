/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiddles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:13:17 by mfiddles          #+#    #+#             */
/*   Updated: 2020/08/12 20:24:25 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SQUARE_H
# define FIND_SQUARE_H
# define SIZE 65540
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			size;
}				t_point;

typedef enum	e_correct_symb
{
	EMPTY = 0,
	OBSTRACTLE = 1,
	FULL = 2
}				t_e_c_s;

char			g_correct_symb[3];
void			free_all(void);
int				write_map(void);
int				check_argv(int size, char **file_name);
int				read_file_data(char *file_path);
int				ft_strcmp(char *str1, char *str2);
int				ft_str_is_printable(char ch);
int				ft_strlen(char *str);
int				ft_isspace(char ch);
int				ft_is_digit(char ch);
int				**g_matrix;
int				g_columns;
int				g_rows;
int				check_file_params(char ch);
int				check_space(char *file_content, int i);
int				check_file_params(char ch);
int				**create_fst_row_col(void);
int				create_full_cell(int **cp_matrix);
int				find_square(void);
int				check_first_str(char *file_content);
int				check_file_strs_len(char *file_content);
int				return_file_columns(char *file_content);
int				read_to_matrix(char *file_content);

#endif
