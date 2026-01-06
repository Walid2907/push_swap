/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:40:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:00:58 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = lst_size(tmp_a);
	size_b = lst_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

int	abs_value(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	int	total;
	int	abs_a;
	int	abs_b;

	abs_a = abs_value(cost_a);
	abs_b = abs_value(cost_b);
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			total = abs_a;
		else
			total = abs_b;
	}
	else
		total = abs_a + abs_b;
	return (total);
}
