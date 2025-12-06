/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:34:47 by yohann          #+#    #+#             */
/*   Updated: 2025/12/03 00:07:10 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsearch(t_list *head, t_list *searching)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (head == NULL)
		return (0);
	tmp = head;
	while (tmp != searching)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
