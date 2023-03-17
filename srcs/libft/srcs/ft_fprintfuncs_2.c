/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintfuncs_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:53:08 by bzawko            #+#    #+#             */
/*   Updated: 2023/02/14 14:53:10 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptrlength(unsigned long int ptr)
{
	int	ret;

	ret = 0;
	while (ptr >= 1)
	{
		ptr /= 16;
		++ret;
	}
	return (ret);
}

int	ft_fprintptr(int fd, unsigned long int n)
{
	int		ptrlen;
	char	*str;
	int		ret;

	ret = write(fd, "0x", 2);
	if (n == 0)
		return ((ret += write(fd, "0", 1)));
	ptrlen = ft_ptrlength(n);
	str = malloc(ptrlen + 1);
	str[ptrlen] = '\0';
	while (--ptrlen >= 0)
	{
		str[ptrlen] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	ret += ft_fprintstr(fd, str);
	free(str);
	return (ret);
}

int	ft_fprinthex(int fd, unsigned int n, char format)
{
	int		hexlen;
	int		ret;
	char	*str;

	if (n == 0)
		return (write(fd, "0", 1));
	hexlen = ft_ptrlength((unsigned long)n);
	str = malloc(hexlen + 1);
	str[hexlen] = '\0';
	while (--hexlen >= 0)
	{
		if (format == 'x')
			str[hexlen] = "0123456789abcdef"[n % 16];
		else
			str[hexlen] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	ret = ft_fprintstr(fd, str);
	free(str);
	return (ret);
}
