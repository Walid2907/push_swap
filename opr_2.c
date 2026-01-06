/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:15:55 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:02:36 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_r(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (lst_size(*stack) < 2)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_list **stack1)
{
	ft_r(stack1);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack2)
{
	ft_r(stack2);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack1, t_list **stack2)
{
	ft_r(stack1);
	ft_r(stack2);
	write(1, "rr\n", 3);
}
