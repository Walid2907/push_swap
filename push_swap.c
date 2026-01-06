/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:40:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:20:02 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_all_to_b_except_3(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;
	int	chunk_size;

	size = lst_size(*stack_a);
	pushed = 0;
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 35;
	while (size - pushed > 3)
	{
		if ((*stack_a)->index <= pushed + chunk_size)
		{
			pb(stack_a, stack_b);
			pushed++;
			if (pushed > chunk_size / 2 && (*stack_b)->index < pushed
				- (chunk_size / 2))
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

void	shift_stack(t_list **stack_a)
{
	int		min_pos;
	t_list	*min_node;

	get_position(stack_a);
	min_node = find_min_lst(stack_a);
	if (!min_node)
		return ;
	min_pos = min_node->pos;
	if (min_pos > (int)lst_size(*stack_a) / 2)
	{
		while (min_pos < (int)lst_size(*stack_a))
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 2 && !ft_checksorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_small(stack_a, stack_b);
	else
	{
		push_all_to_b_except_3(stack_a, stack_b);
		sort_3(stack_a);
		while (*stack_b)
		{
			get_target_position(stack_a, stack_b);
			get_cost(stack_a, stack_b);
			do_cheapest_move(stack_a, stack_b);
		}
		if (!ft_checksorted(*stack_a))
			shift_stack(stack_a);
	}
}
