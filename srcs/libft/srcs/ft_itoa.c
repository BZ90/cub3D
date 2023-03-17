/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:33:40 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/09 15:33:42 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblength(int n)
{
	int			len;
	long int	n2;

	n2 = n;
	len = 0;
	if (n2 == 0)
		return (1);
	if (n2 < 0)
	{
		++len;
		n2 *= -1;
	}
	while (n2 >= 1)
	{
		++len;
		n2 /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ret;
	long int	n2;
	int			len;

	n2 = n;
	len = nblength(n);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (n2 == 0)
		ret[0] = '0';
	if (n2 < 0)
	{
		n2 *= -1;
		ret[0] = '-';
	}
	while (n2 >= 1)
	{
		ret[--len] = (n2 % 10) + '0';
		n2 /= 10;
	}
	return (ret);
}
