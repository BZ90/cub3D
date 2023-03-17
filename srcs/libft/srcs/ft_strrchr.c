/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:36:02 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/09 17:10:50 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		isfound;
	int		i;

	i = 0;
	isfound = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			isfound = 1;
		++i;
	}
	++i;
	if (c == 0)
		isfound = 1;
	if (isfound)
		while (--i >= 0)
			if (s[i] == (char)c)
				break ;
	if (s[i] == (char)c)
		ret = (char *)(s + i);
	if (isfound)
		return (ret);
	return (NULL);
}
