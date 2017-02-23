/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:26:07 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/18 12:49:25 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *nxtlst;

	lst = *alst;
	nxtlst = lst->next;
	del(lst->content, lst->content_size);
	free(lst);
	*alst = nxtlst;
}
