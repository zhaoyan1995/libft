/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:46:58 by yanzhao           #+#    #+#             */
/*   Updated: 2025/05/04 17:54:16 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap2(t_list *lst, t_list *start,
			void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_node;
	void	*new_content;

	lst = lst->next;
	current = start;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			(*del)(new_content);
			ft_lstclear(&start, del);
			return (NULL);
		}
		current->next = new_node;
		current = current->next;
		lst = lst->next;
	}
	return (start);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_content = (*f)(lst->content);
	start = ft_lstnew(new_content);
	if (!start)
	{
		(*del)(new_content);
		return (NULL);
	}
	return (ft_lstmap2(lst, start, f, del));
}
