/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:07:35 by bzawko            #+#    #+#             */
/*   Updated: 2022/05/24 14:10:24 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	var_print(va_list args, const char format)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret = ft_printchar(va_arg(args, int));
	else if (format == 's')
		ret = ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		ret = ft_printptr(va_arg(args, unsigned long int));
	else if (format == 'd' || format == 'i')
		ret = ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		ret = ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		ret = ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		ret = ft_printchar('%');
	return (ret);
}

static int	print_to_percent(const char *str)
{
	int	ret;

	ret = 0;
	while (str[ret] && str[ret] != '%')
		ret += write(1, &str[ret], 1);
	return (ret);
}

static int	is_valid_format(const char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd')
		return (1);
	else if (format == 'i' || format == 'u' || format == 'x' || format == 'X')
		return (1);
	else if (format == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;
	int		i;
	int		x;

	va_start(args, str);
	i = print_to_percent(str);
	ret = i;
	while (str[i])
	{
		ret += var_print(args, str[i + 1]);
		i += (is_valid_format(str[i + 1]) + 1);
		x = print_to_percent(&str[i]);
		i += x;
		ret += x;
	}
	va_end(args);
	return (ret);
}
