/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:22:48 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:02:16 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	split = join_split(argc, argv);
	check_input(split);
	fill_stack(&stack_a, split);
	free_split(split);
	add_index(stack_a);
	if (ft_checksorted(stack_a) == 0)
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
