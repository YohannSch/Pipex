/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:34:47 by yohann          #+#    #+#             */
/*   Updated: 2025/12/03 00:07:04 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd(t_list *new, t_list *head)
{
	if (new == NULL)
	{
		return ;
	}
	if (head->next == NULL)
	{
		new->next = head;
		new->prev = head;
		head->next = new;
		head->prev = new;
	}
	else
	{
		new->prev = head->prev;
		head->prev = new;
		new->prev->next = new;
		new->next = head;
	}
}
