/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:27:30 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/03 16:56:36 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*sub(char *str, int i)
{
	int		len;
	int		j;
	char	*sub_str;

	len = 0;
	j = 0;
	while (str[i + len] != ' ' && str[i + len] != '\0')
		len++;
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (j < len)
		sub_str[j++] = str[i++];
	sub_str[j] = '\0';
	return (sub_str);
}

char	**fill(char **tab, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] != ' ')
		{
			tab[i] = sub(str, j);
			if (!tab[i])
			{
				free_split(tab);
				return (NULL);
			}
			i++;
			while (str[j] != ' ' && str[j] != '\0')
				j++;
		}
		else
			j++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char *str)
{
	int		i;
	int		counter;
	char	**tab;

	i = 0;
	counter = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			counter++;
		i++;
	}
	tab = malloc(sizeof(char *) * (counter + 1));
	if (!tab)
		return (NULL);
	if (!fill(tab, str))
		return (NULL);
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		join_len;
	int		i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	join_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(join_len + 1);
	if (str == NULL)
		return (NULL);
	while (i < join_len && *s1 != '\0')
		str[i++] = *(s1++);
	while (i < join_len && *s2 != '\0')
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}
