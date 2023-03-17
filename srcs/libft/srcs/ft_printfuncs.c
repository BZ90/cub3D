/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfuncs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:34:33 by bzawko            #+#    #+#             */
/*   Updated: 2022/05/24 10:34:34 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_printnbr(int n)
{
	int		ret;
	char	*s;

	s = ft_itoa(n);
	ret = write(1, s, ft_strlen(s));
	free(s);
	return (ret);
}

int	ft_printunsigned(unsigned int n)
{
	int		ret;
	char	*s;

	s = ft_uitoa(n);
	ret = write(1, s, ft_strlen(s));
	free(s);
	return (ret);
}
