/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:46:26 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/04 20:49:29 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rr(t_list **stack)
{
	t_list	*tmp;
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_list **stack1)
{
	ft_rr(stack1);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack2)
{
	ft_rr(stack2);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack1, t_list **stack2)
{
	ft_rr(stack1);
	ft_rr(stack2);
	write(1, "rrr\n", 4);
}
