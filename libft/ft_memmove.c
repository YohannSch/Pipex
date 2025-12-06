/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:12:24 by yohann          #+#    #+#             */
/*   Updated: 2025/06/17 21:15:40 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmp_dest;
	const char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (char *) dest;
	tmp_src = (const char *) src;
	if (tmp_dest > tmp_src && tmp_src + n > tmp_dest)
		while (n-- > 0)
			tmp_dest[n] = tmp_src[n];
	else
	{
		i = 0;
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
