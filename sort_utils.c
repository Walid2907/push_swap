/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:58:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:03:51 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*find_min_lst(t_list **stack)
{
	t_list	*min;
	t_list	*tmp;

	if (!stack || !*stack)
		return (NULL);
	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < min->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_max_lst(t_list **stack)
{
	t_list	*max;
	t_list	*tmp;

	if (!stack || !*stack)
		return (NULL);
	max = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	check_sorting_a(t_list **stack1, int count)
{
	int		len;
	t_list	*tmp;

	len = lst_size(*stack1);
	if (len != count)
		return (0);
	tmp = *stack1;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	isrevsorted(t_list *stack_a)
{
	t_list	*tmp;

	if (!stack_a || !stack_a->next)
		return (0);
	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_lstlast(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
