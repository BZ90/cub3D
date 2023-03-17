/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintfuncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:34:33 by bzawko            #+#    #+#             */
/*   Updated: 2022/05/24 10:34:34 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fprintchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_fprintstr(int fd, char *str)
{
	if (str == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, str, ft_strlen(str)));
}

int	ft_fprintnbr(int fd, int n)
{
	int		ret;
	char	*s;

	s = ft_itoa(n);
	ret = write(fd, s, ft_strlen(s));
	free(s);
	return (ret);
}

int	ft_fprintunsigned(int fd, unsigned int n)
{
	int		ret;
	char	*s;

	s = ft_uitoa(n);
	ret = write(fd, s, ft_strlen(s));
	free(s);
	return (ret);
}
