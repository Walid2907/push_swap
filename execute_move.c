/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:40:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:09:42 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_rotate_both(t_list **stack_a, t_list **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	do_reverse_rotate_both(t_list **stack_a, t_list **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	do_rotate_a(t_list **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(stack_a);
			(*cost)++;
		}
	}
}

void	do_rotate_b(t_list **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(stack_b);
			(*cost)++;
		}
	}
}

void	execute_move(t_list **stack_a, t_list **stack_b, int cost_a,
		int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		do_reverse_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}
