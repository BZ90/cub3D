/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:21:19 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/21 11:21:22 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;

	if (!*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		prev = current;
		current = current->next;
		(*del)(prev->content);
		free(prev);
	}
	*lst = NULL;
}
