/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:36:42 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/09 13:36:44 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		++i;
	ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = (*f)(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
