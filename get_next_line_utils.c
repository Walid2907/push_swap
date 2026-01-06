/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:04:45 by wkerdad           #+#    #+#             */
/*   Updated: 2026/01/04 21:00:24 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include"header.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen((s + start));
	if (len > new_len)
		sub_str = malloc(new_len + 1);
	else
		sub_str = malloc(len + 1);
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*s;

	if (str == NULL)
		return (NULL);
	s = (unsigned char *)str;
	if (c == '\0')
		return ((char *)(s + ft_strlen(str)));
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
