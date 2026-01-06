/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:40:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:24:27 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_highest_index(t_list *stack)
{
	int	index;

	if (!stack)
		return (0);
	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_3(t_list **stack)
{
	int	highest;

	if (ft_checksorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_small_uti(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_node;
	int		min_index;

	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	min_node = find_min_lst(stack_a);
	if (!min_node)
		return ;
	get_position(stack_a);
	min_index = min_node->index;
	if (min_node->pos > (int)lst_size(*stack_a) / 2)
	{
		while ((*stack_a)->index != min_index)
			rra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != min_index)
			ra(stack_a);
	}
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		pushed;

	size = lst_size(*stack_a);
	pushed = 0;
	while (size > 6 && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
	sort_3(stack_a);
	sort_small_uti(stack_a, stack_b);
}
