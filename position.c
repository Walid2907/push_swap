/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:40:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:17:39 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_tg_u(t_list **tmp_a, int *target_index, int *index_b,
		int *target_pos)
{
	while (*tmp_a)
	{
		if ((*tmp_a)->index > *index_b && (*tmp_a)->index < *target_index)
		{
			*target_index = (*tmp_a)->index;
			*target_pos = (*tmp_a)->pos;
		}
		*tmp_a = (*tmp_a)->next;
	}
}

int	get_target(t_list **stack_a, int index_b, int target_index, int target_pos)
{
	t_list	*tmp_a;

	tmp_a = *stack_a;
	get_tg_u(&tmp_a, &target_index, &index_b, &target_pos);
	if (target_index != INT_MAX)
		return (target_pos);
	target_index = INT_MAX;
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		target_pos;

	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return ;
	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(stack_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
