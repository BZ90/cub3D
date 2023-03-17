/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:36:15 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/29 13:23:13 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	h;
	size_t	i;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h])
	{
		i = 0;
		while (haystack[h + i] == needle[i] && (h + i) < n && haystack[h + i])
			++i;
		if (needle[i] == '\0')
			return ((char *)haystack + h);
		++h;
	}
	return (NULL);
}
