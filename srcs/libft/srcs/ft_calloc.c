/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:34:28 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/21 15:14:45 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	size_t			i;
	unsigned char	*retcpy;

	i = (count * size);
	ret = malloc(i);
	if (!ret)
		return (NULL);
	retcpy = (unsigned char *)ret;
	while (i--)
	{
		*retcpy = '\0';
		++retcpy;
	}
	return (ret);
}
