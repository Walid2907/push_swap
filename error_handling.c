/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:24:33 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/04 20:32:09 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exit_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_free(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->value = 0;
		free(*lst);
		*lst = tmp;
	}
}

void	do_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*cheapest;
	int		cheapest_cost;
	int		current_cost;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	cheapest = NULL;
	cheapest_cost = INT_MAX;
	while (tmp)
	{
		current_cost = calculate_total_cost(tmp->cost_a, tmp->cost_b);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	if (cheapest)
		execute_move(stack_a, stack_b, cheapest->cost_a, cheapest->cost_b);
}
