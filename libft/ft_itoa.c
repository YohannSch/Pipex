/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:01:49 by yohann          #+#    #+#             */
/*   Updated: 2025/06/17 21:15:45 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	fill_digits(char *ret, long lnb, int len)
{
	while (lnb > 0)
	{
		ret[--len] = (lnb % 10) + '0';
		lnb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	lnb;
	int		len;
	int		sign;

	lnb = n;
	sign = 0;
	if (lnb < 0)
	{
		sign = 1;
		lnb = -lnb;
	}
	len = digit_count(n) + sign;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (sign)
		ret[0] = '-';
	fill_digits(ret, lnb, len);
	return (ret);
}
