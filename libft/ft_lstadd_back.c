/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmogi <dmogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:43:07 by dmogi             #+#    #+#             */
/*   Updated: 2021/04/16 13:44:23 by dmogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

	if (lst == NULL)
		return ;
	start = *lst;
	if (start == NULL)
		*lst = new;
	else
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new;
	}
}
