/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:21:55 by bzawko            #+#    #+#             */
/*   Updated: 2022/03/21 11:21:57 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clearlst(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;

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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*curret;

	if (!f || !del || !lst)
		return (NULL);
	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	curret = ret;
	while (lst->next)
	{
		curret->content = (*f)(lst->content);
		curret->next = malloc(sizeof(t_list));
		if (!curret->next)
		{
			clearlst(&ret, del);
			return (NULL);
		}
		lst = lst->next;
		curret = curret->next;
	}
	curret->content = (*f)(lst->content);
	curret->next = NULL;
	return (ret);
}
