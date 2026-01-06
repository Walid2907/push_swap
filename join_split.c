/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:43:36 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 17:57:24 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*new_str;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	len = ft_strlen(str);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		*(new_str + i) = *(str);
		str++;
		i++;
	}
	*(new_str + i) = '\0';
	return ((char *)new_str);
}

void	join_split_uti(int argc, char **argv, char **arg_join)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(*arg_join, " ");
		free(*arg_join);
		if (!temp)
			exit_error();
		*arg_join = temp;
		temp = ft_strjoin(*arg_join, argv[i]);
		free(*arg_join);
		if (!temp)
			exit_error();
		*arg_join = temp;
		i++;
	}
}

char	**join_split(int argc, char **argv)
{
	char	**arg_tab;
	char	*arg_join;

	arg_join = ft_strdup("");
	if (!arg_join)
		exit_error();
	join_split_uti(argc, argv, &arg_join);
	arg_tab = ft_split(arg_join);
	if (arg_tab == NULL)
	{
		free(arg_join);
		exit_error();
	}
	free(arg_join);
	return (arg_tab);
}
