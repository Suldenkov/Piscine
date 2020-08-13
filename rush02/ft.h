/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:56:38 by wronnel           #+#    #+#             */
/*   Updated: 2020/08/06 18:13:11 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct		s_list
{
	struct s_list	*next;
	char			*value;
	char	*key;
}					t_list;

t_list				*ft_create_elem(void *data);

#endif
