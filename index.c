/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:58:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:01:43 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	index_replace(t_list *lst, int n, int to)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->value == n)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		tmp->index = to;
}

int	min_nbr(t_list *lst)
{
	t_list		*tmp;
	long int	min;

	min = LONG_MAX;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	add_index(t_list *lst)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = lst_size(lst);
	while (i < len)
	{
		min = min_nbr(lst);
		index_replace(lst, min, i);
		i++;
	}
}
