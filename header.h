/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:22:25 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/06 10:23:16 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_push
{
	int				next;
	int				max;
	int				mid;
	int				flag;
	int				chunk_size;
}					t_push;

typedef struct w_stack
{
	int				value;
	int				index;
	int				flag;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct w_stack	*next;
}					t_list;

char				**ft_split(char *str);
void				exit_error(void);
void				free_split(char **str);
char				**join_split(int argc, char **argv);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
int					ft_strlen(const char *s);
void				check_input(char **tab);
long				ft_atol(const char *str);
void				fill_stack(t_list **stack, char **split);
void				free_stack(t_list **stack);
int					ft_checksorted(t_list *stack_a);
size_t				lst_size(t_list *stack);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ft_s(t_list **stack);
void				ss(t_list **stack_a, t_list **stack_b);
void				ft_r(t_list **stack);
void				ft_rr(t_list **stack);
void				ra(t_list **stack1);
void				rb(t_list **stack2);
void				rr(t_list **stack1, t_list **stack2);
void				pb(t_list **stack1, t_list **stack2);
void				pa(t_list **stack1, t_list **stack2);
void				rra(t_list **stack1);
void				rrb(t_list **stack2);
void				rrr(t_list **stack1, t_list **stack2);
void				add_index(t_list *lst);
t_list				*find_min_lst(t_list **stack);
t_list				*find_max_lst(t_list **stack);
int					check_sorting_a(t_list **stack1, int count);
int					isrevsorted(t_list *stack_a);
t_list				*ft_lstlast(t_list *stack);
void				get_position(t_list **stack);
void				get_target_position(t_list **stack_a, t_list **stack_b);
void				get_cost(t_list **stack_a, t_list **stack_b);
int					calculate_total_cost(int cost_a, int cost_b);
void				do_cheapest_move(t_list **stack_a, t_list **stack_b);
void				execute_move(t_list **stack_a, t_list **stack_b,
						int cost_a, int cost_b);
void				sort_3(t_list **stack_a);
void				sort_small(t_list **stack_a, t_list **stack_b);
void				push_swap(t_list **stack_a, t_list **stack_b);
void				ft_free(t_list **lst);
void	ft_error_checker(t_list **a, t_list **b, char **line);
void				pb_silent(t_list **stack_a, t_list **stack_b);
void				rr_silent(t_list **stack_a, t_list **stack_b);
void				rrr_silent(t_list **stack_a, t_list **stack_b);
int					ft_strcmp(const char *s1, const char *s2);

#endif
