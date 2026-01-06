/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_uti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:23:42 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/06 10:22:35 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	ft_error_checker(t_list **a, t_list **b, char **line)
{
	write(2, "ERROR\n", 6);
	free_stack(a);
	free_stack(b);
	free(line);
	exit(EXIT_FAILURE);
}

void	pb_silent(t_list **stack_a, t_list **stack_b)
{
	t_list	*push_a;

	if (!*stack_a)
		return ;
	push_a = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = push_a;
}

void	rr_silent(t_list **stack_a, t_list **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
}

void	rrr_silent(t_list **stack_a, t_list **stack_b)
{
	ft_rr(stack_a);
	ft_rr(stack_b);
}

// Check if command matches and execute
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
