/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:13:09 by yohann          #+#    #+#             */
/*   Updated: 2025/06/19 13:38:30 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alocation;

	alocation = (char *)malloc(sizeof(char) * (size * nmemb));
	if (!alocation)
		return (NULL);
	ft_bzero(alocation, size * nmemb);
	return (alocation);
}
