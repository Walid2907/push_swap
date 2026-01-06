/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:22:46 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:02:48 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pa(t_list **stack1, t_list **stack2)
{
	t_list	*push_b;

	if (!*stack2)
		return ;
	push_b = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = push_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack1, t_list **stack2)
{
	t_list	*push_a;

	if (!*stack1)
		return ;
	push_a = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = push_a;
	write(1, "pb\n", 3);
}
