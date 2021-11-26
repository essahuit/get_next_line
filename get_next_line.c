/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:27:26 by kessalih          #+#    #+#             */
/*   Updated: 2021/11/20 01:26:32 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	len = ft_strlen(s1);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_line(char **stext)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	if (!*stext || !*stext[0])
	{
		free(*stext);
		*stext = NULL;
		return (NULL);
	}
	while ((*stext)[i] != '\n' && (*stext)[i])
		i++;
	if ((*stext)[i] == '\n')
	{
		line = ft_substr(*stext, 0, i + 1);
		temp = ft_strdup((*stext) + i + 1);
		free(*stext);
		*stext = temp;
		return (line);
	}
	line = ft_strdup(*stext);
	free(*stext);
	*stext = NULL;
	return (line);
}

void	ft_read(int fd, char *text, char **stext, ssize_t nb)
{
	char	*temp;

	while (nb > 0)
	{
		if (!*stext)
			*stext = ft_strdup("");
		temp = ft_strjoin(*stext, text);
		free(*stext);
		*stext = temp;
		if (ft_strchr(text, '\n'))
			break ;
		nb = read(fd, text, BUFFER_SIZE);
		text[nb] = '\0';
	}
	free(text);
}

char	*get_next_line(int fd)
{
	char		*text;
	static char	*stext;
	char		*line;
	ssize_t		nb;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	text = malloc(BUFFER_SIZE + 1);
	if (!text)
		return (NULL);
	nb = read(fd, text, BUFFER_SIZE);
	if (nb == -1)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	text[nb] = '\0';
	ft_read(fd, text, &stext, nb);
	line = ft_line(&stext);
	return (line);
}
