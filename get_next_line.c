/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:40:30 by porg              #+#    #+#             */
/*   Updated: 2021/12/12 22:17:44 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	getline(char **line, char **str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = str;
	while(str[i] != '\n' && str[i] != '\0')
		i++;
	if (strchr(*str, '\n'))
	{
		*line = ft_substr(*str, 0 , i + 1);
		*str = ft_strdup(*str + i + 1);
	}
	else
	{
		*line = ft_strdup(temp);
		*str = NULL;
	}
	freeline(temp);
	return (*line);
}

int	bufcpy(int fd, char **buf, char **str, char line)
{
	int		i;
	char	*temp;

	i = 1;
	while (!ft_strchr(*str, '\n') && i)
	{
		i = read(fd, *buf, BUFFER_SIZE);
		buf[i] = '\0';
		*str = ft_strjoin(*str, *buf);
	}
	freeline(*buf);
	getline(line, str);
	return (i);
}

void	freeline(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str = NULL;
	char		*line;

	if (fd < 0  || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	if (!str)
		str = ft_strdup("");
	if (bufcpy(fd, &buf, &str, &line) == 0 && *line == '\0')
	{
		freeline(line);
		return (NULL);
	}
	return (line);
}
