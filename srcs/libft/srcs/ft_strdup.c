/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:28 by bzawko            #+#    #+#             */
/*   Updated: 2023/02/23 11:08:46 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		++len;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	while (len >= 0)
	{
		ret[len] = s[len];
		--len;
	}
	return (ret);
}
