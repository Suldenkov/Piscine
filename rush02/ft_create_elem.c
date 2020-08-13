/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:31:47 by wronnel           #+#    #+#             */
/*   Updated: 2020/08/06 18:11:16 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

t_list	*ft_create_elem(char *key, char *value)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->key = key;
	elem->value = value;
	elem->next = NULL;
	return (elem);
}
