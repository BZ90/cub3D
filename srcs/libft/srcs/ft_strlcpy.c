/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:37:07 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/21 11:35:27 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;

	j = 1;
	if (size == 0)
	{
		size = 1;
		j = 0;
	}
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (j)
		dst[i] = '\0';
	i = 0;
	while (src[i])
		++i;
	return (i);
}
