/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:12 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/09 13:56:13 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		un = (unsigned int)(n * -1);
	}
	else
		un = (unsigned int)n;
	if (un >= 10)
		ft_putnbr_fd(un / 10, fd);
	c = (un % 10) + '0';
	write(fd, &c, 1);
}
