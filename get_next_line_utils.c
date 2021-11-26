/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:57:08 by kessalih          #+#    #+#             */
/*   Updated: 2021/11/19 15:00:20 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (len == 0)
		return (slen);
	while (src[i] && i < len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (!dst && !len)
		return (slen);
	l = ft_strlen(dst);
	if (len < l + 1)
		return (l + len);
	while (src[i] && i < (len - l - 1))
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	return (l + slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		str = malloc(1);
	else if (len >= (slen - start))
		str = malloc(slen - start + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[i] && i < len && start + i < slen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	slen1;
	size_t	slen2;
	char	*s;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	s = malloc(slen1 + slen2 + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, slen1 + 1);
	ft_strlcat(s, s2, slen1 + slen2 + 1);
	return (s);
}
