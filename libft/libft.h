/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alineayumi <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:11:28 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/26 16:17:44 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
** ------------------------ PART 1 - LIBC FUNCTIONS ---------------------------
**
** --- MEMORY FUNCTIONS ---
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
	int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
	size_t n);
void				*ft_memmove(void *dst, const void *src, size_t count);
void				*ft_memset(void *b, int c, size_t len);
/*
** --- STRING EXAMINATION FUNCTIONS ---
*/
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
/*
** --- STRING MANIPULATION FUNCTIONS ---
*/
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
	size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
	size_t dstsize);
size_t				ft_strlcpy(char *restrict dst, const char *restrict src,
	size_t dstsize);
/*
** --- CHARACTER CLASSIFICATION FUNCTIONS ---
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
/*
** --- CHARACTER CONVERSION FUNCTIONS ---
*/
int					ft_tolower(int c);
int					ft_toupper(int c);
/*
** --- NUMERIC CONVERSION FUNCTIONS ---
*/
int					ft_atoi(const char *str);
/*
** ------------------------ PART 2 - ADDITIONAL FUNCTIONS ---------------------
**
** --- MEMORY FUNCTIONS ---
*/
void				*ft_memalloc(size_t size);
void				*ft_memcpy_rev(void *restrict dst,
	const void *restrict src, size_t n);
void				ft_memdel(void **ap);
/*
** --- NUMERIC CONVERSION FUNCTIONS ---
*/
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_atoi_base(const char *str, int base);
int					ft_numdig(int n, int base);
/*
** --- STRING MANIPULATION FUNCTIONS ---
*/
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
void				ft_strdel(char **str);
void				ft_strclr(char *str);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/*
** --- STRING EXAMINATION FUNCTIONS ---
*/
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_countword(char const *s, char c);
/*
** --- WRITE FUNCTIONS ---
*/
void				ft_putendl(char *s);
void				ft_putendl_fd(char *s, int fd);
int					ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char *s);
int					ft_putstr_fd(char *s, int fd);
/*
** --------------------- BONUS PART -------------------------------------------
**
** --- STRUCT ---
*/
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/*
** --- FUNCTIONS ---
*/
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);
#endif
