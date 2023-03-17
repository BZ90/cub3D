/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:35:46 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/21 15:49:20 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*st_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	if (i < start)
		len = 0;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		ret[i] = s[start];
		++i;
		++start;
	}
	ret[i] = '\0';
	return (ret);
}

static int	st_inset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && st_inset(set, *s1))
		++s1;
	while (s1[i])
		++i;
	while (i && st_inset(set, s1[i]))
		--i;
	return (st_substr(s1, 0, i + 1));
}
