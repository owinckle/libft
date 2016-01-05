/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:26:10 by owinckle          #+#    #+#             */
/*   Updated: 2016/01/05 17:28:53 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*ret;

	ret = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!ret)
		{
			ret = tmp;
			new = ret;
			ret->next = NULL;
		}
		else
		{
			ret->next = tmp;
			tmp->next = NUL;
			ret = ret->next;
		}
		lst = lst->next;
	}
	return (new);
}
