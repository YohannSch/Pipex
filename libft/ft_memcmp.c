/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:54:10 by yohann          #+#    #+#             */
/*   Updated: 2025/06/17 21:15:42 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;

	i = 0;
	temp_s1 = (const unsigned char *) s1;
	temp_s2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (temp_s1[i] == temp_s2[i])
			i++;
		else
			return (temp_s1[i] - temp_s2[i]);
	}
	i--;
	return (temp_s1[i] - temp_s2[i]);
}
