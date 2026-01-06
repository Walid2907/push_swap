/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:22:23 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/06 10:21:52 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	ss_silent(t_list **stack_a, t_list **stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
}

void	pa_silent(t_list **stack_a, t_list **stack_b)
{
	t_list	*push_b;

	if (!*stack_b)
		return ;
	push_b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = push_b;
}

void	execute_command(t_list **a, t_list **b, char **line)
{
	if (ft_strcmp(*line, "sa\n") == 0)
		ft_s(a);
	else if (ft_strcmp(*line, "sb\n") == 0)
		ft_s(b);
	else if (ft_strcmp(*line, "ss\n") == 0)
		ss_silent(a, b);
	else if (ft_strcmp(*line, "pa\n") == 0)
		pa_silent(a, b);
	else if (ft_strcmp(*line, "pb\n") == 0)
		pb_silent(a, b);
	else if (ft_strcmp(*line, "ra\n") == 0)
		ft_r(a);
	else if (ft_strcmp(*line, "rb\n") == 0)
		ft_r(b);
	else if (ft_strcmp(*line, "rr\n") == 0)
		rr_silent(a, b);
	else if (ft_strcmp(*line, "rra\n") == 0)
		ft_rr(a);
	else if (ft_strcmp(*line, "rrb\n") == 0)
		ft_rr(b);
	else if (ft_strcmp(*line, "rrr\n") == 0)
		rrr_silent(a, b);
	else
		ft_error_checker(a, b, line);
	free(*line);
}

void	free_checker(t_list **a, t_list **b)
{
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;
	char	**split;

	if (argc < 2)
		return (0);
	b = NULL;
	split = join_split(argc, argv);
	check_input(split);
	a = NULL;
	fill_stack(&a, split);
	free_split(split);
	line = get_next_line(0);
	while (line)
	{
		execute_command(&a, &b, &line);
		line = get_next_line(0);
	}
	if (b == NULL && ft_checksorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_checker(&a, &b);
	return (0);
}
