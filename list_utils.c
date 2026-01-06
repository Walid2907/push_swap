/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:23:30 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:02:08 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_lstnew(int valeur)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->value = valeur;
	node->index = -1;
	node->flag = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst == NULL || new == NULL)
		return ;
	ptr = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

size_t	lst_size(t_list *stack)
{
	size_t	counter;

	counter = 0;
	while (stack)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	fill_stack(t_list **stack, char **split)
{
	int		i;
	long	value;
	t_list	*new;

	i = 0;
	while (split[i])
	{
		value = ft_atol(split[i]);
		new = ft_lstnew((int)value);
		if (!new)
		{
			free_stack(stack);
			free_split(split);
			exit_error();
		}
		ft_lstadd_back(stack, new);
		i++;
	}
}

int	ft_checksorted(t_list *stack_a)
{
	int	i;

	i = stack_a->value;
	while (stack_a)
	{
		if (i > stack_a->value)
			return (0);
		i = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}
