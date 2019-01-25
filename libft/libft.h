/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:32:10 by themarch     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 10:12:22 by themarch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 100

int					get_next_line(const int fd, char **line);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_memdel(void **ap);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
int					ft_strdel(char **ptr_str);
void				ft_strclr(char *s);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_putestr(char *str);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_count_word(char *str);
unsigned int		ft_count_word_caract(char const *s, char c);
void				*ft_memrcpy(void *dst, const void *src, size_t n);
char				*ft_append_char(char *s1, char c);
int					*ft_range(int min, int max);
size_t				ft_strcharlen(char *str, char c);
char				*ft_strtrimfillit(char const *s, char c);
void				ft_putnbr2(int n, int nb);
char				*ft_fstrjoin(char **s1, char **s2, int free_s1, int
					free_s2);
void				ft_strmove(char *begin_str, char *new_begin);

typedef struct		s_list
{
	char			*tmp;
	int				fd;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, int content_size);
t_list				*ft_dellist(t_list *start, t_list *list);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);

#endif
