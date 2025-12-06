/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohann <yohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:48:31 by yohann          #+#    #+#             */
/*   Updated: 2025/12/01 03:39:08 by yohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// write functions
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// malloc string functions
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				**ft_split(char const *s, char c);

// string functions
size_t				ft_strlen(char const *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strcpy(char *dest, const char *src);

// is char functions
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

// char modification functions
int					ft_toupper(int c);
int					ft_tolower(int c);

// mem functions
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

// memory allocation functions

void				*ft_calloc(size_t nmemb, size_t size);

// conversion function

int					ft_atoi(const char *nptr);
long long int		ft_atoll(const char *nptr);
char				*ft_itoa(int n);

// lst function

t_list				*ft_lstnew(int input);
int					ft_lstsearch(t_list *head, t_list *searching);
int					ft_lstsize(t_list *head);
void				ft_lstadd(t_list *new, t_list *head);

#endif