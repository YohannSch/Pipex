/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:15:58 by yohann          #+#    #+#             */
/*   Updated: 2025/06/17 21:15:33 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i] != 0)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
