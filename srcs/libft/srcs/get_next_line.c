/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:07:25 by jtanner           #+#    #+#             */
/*   Updated: 2023/02/23 14:26:17 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

static char	*extract_newline(char *line)
{
	size_t	i;
	char	*remains;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	remains = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remains == '\0')
	{
		free(remains);
		remains = NULL;
	}
	line[i + 1] = '\0';
	return (remains);
}

static char	*find_newline(int fd, char *buf, char *backup)
{
	int		bytred;
	char	*temp;	

	bytred = 1;
	while (bytred != 0)
	{
		bytred = read(fd, buf, BUFFER_SIZE);
		if (bytred == -1)
			return (NULL);
		else if (bytred == 0)
			break ;
		buf[bytred] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strrchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE +1) * (sizeof (char *)));
	if (!buf)
		return (NULL);
	line = find_newline(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (line);
	backup = extract_newline(line);
	return (line);
}
