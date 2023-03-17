/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:33:40 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/09 15:33:42 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	uintlength(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char		*ret;
	int			len;

	len = uintlength(n);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (n >= 1)
	{
		ret[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
