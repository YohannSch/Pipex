/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:32:42 by yohann          #+#    #+#             */
/*   Updated: 2025/06/17 21:15:35 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (!tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	nbw;
	int	in_word;

	i = 0;
	nbw = 0;
	in_word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			in_word = 1;
			nbw++;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (nbw);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		len;
	int		i;

	len = end - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	fill_split(const char *s, char c, char **res)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[j] = word_dup(s, start, i);
			if (!res[j] || res[j] == NULL)
			{
				free_tab(res);
				return ;
			}
			j++;
		}
	}
	res[j] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	fill_split(s, c, res);
	if (!res)
		return (NULL);
	return (res);
}
