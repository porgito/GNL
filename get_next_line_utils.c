/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:21:55 by jlaurent          #+#    #+#             */
/*   Updated: 2021/12/13 11:22:33 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == t)
			return ((char *)s + i);
		else
			i++;
	}
	if (t == 0)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		m;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	m = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(m + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;

	i = 0;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		new[0] = '\0';
		return (new);
	}
	while (i < len)
	{
		new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
