/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbilim <rbilim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:34:39 by rbilim            #+#    #+#             */
/*   Updated: 2025/06/15 19:32:16 by rbilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_lst;

	while (*lst)
	{
		temp_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp_lst;
	}
	*lst = NULL;
}
