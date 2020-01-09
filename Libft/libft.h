/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:43:00 by nrechati          #+#    #+#             */
/*   Updated: 2019/10/02 12:49:29 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# define BUFF_SIZE 4096
# define MAX_FD 2049
# define BASE_MAX 66
# define FLAGS "-+0 #"
# define SIZE "hlLIjzt"
# define OTHER "csp%"
# define SIGNED "Ddi"
# define UNSIGNED "boOuUxX"
# define FLOAT "fF"
# define TYPE "cspdDiboOuUxXfF"
# define TEN "0123456789"
# define BINARY "01"
# define OCTAL "01234567"
# define HEXA "0123456789abcdef"

typedef struct s_format	t_format;
typedef void	(*t_convert)(t_format *);

typedef union			u_args {
	char				character;
	unsigned char		u_character;
	short				s_short;
	unsigned short		u_short;
	int					integer;
	long int			l_integer;
	long long int		ll_integer;
	intmax_t			intmax;
	ssize_t				ssizet;
	unsigned int		u_integer;
	unsigned long		ul_integer;
	unsigned long long	ull_integer;
	uintmax_t			u_intmax;
	size_t				sizet;
	ptrdiff_t			ptrdiff;
	double				s_double;
	long double			l_double;
	char				*string;
	void				*pointer;
}						t_args;

struct					s_format
{
	char				id;
	char				valid;
	char				type;
	char				flag_minus;
	char				flag_plus;
	char				flag_zero;
	char				flag_space;
	char				flag_hashtag;
	int					width;
	int					precision;
	unsigned int		diff;
	char				*size;
	char				*output;
	t_convert			convert;
	t_args				arg;
};

typedef struct			s_buffer
{
	char				buffer[BUFF_SIZE];
	unsigned int		index;
	unsigned int		room;
}						t_buffer;

typedef struct			s_file
{
	int					fd;
	int					status;
	char				*str;
}						t_file;

typedef struct			s_list
{
	void				*data;
	size_t				data_size;
	struct s_list		*next;
}						t_list;

int						ft_tolower(int c);
int						ft_toupper(int c);

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);

void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *mem, int c, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t len);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t len);
void					*ft_memchr(const void *str, int c, size_t len);
int						ft_memcmp(const void *s1, const void *s2, size_t len);
void					*ft_memmove(void *dst, const void *src, size_t len);

size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack,
										const char *needle, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
int						ft_strnrchr(const char *s, char c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_strclr(char *s);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strtrim(char const *s);
size_t					ft_strclen(const char *s, char c);
char					*ft_strrev(char *str);
void					ft_strupper(char *str);

void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr(char const *s);
int						ft_putstr_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr_base(int nbr, char *base);

t_list					*ft_lstnew(void const *data, size_t data_size);
void					ft_lstdelone(t_list **alst, void (*del)(void **));
void					*ft_lstdel(t_list **alst, void (*del)(void **));
void					ft_lstadd(t_list **alst, t_list *new);
int						ft_lstaddend(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char					**ft_strsplit(char const *s, char *charset);
t_list					*ft_lstat(t_list *alst, unsigned int n);
int						ft_lstsize(t_list *alst);
void					ft_lstrev(t_list **alst);
size_t					ft_lstlen(t_list *lst);

int						ft_atoi(const char *str);
char					*ft_itoa(int n);
void					ft_swap(int *a, int *b);
char					*ft_convert_base(char *nbr, char *base_from,
						char *base_to);
int						get_next_line(const int fd, char **line);
int						ft_abs(int nb);

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
int						ft_asprintf(char **dst, const char *format, ...);
int						ft_vdprintf(const char *format, va_list args, int fd);
int						ft_vasprintf(char **dst, const char *format,\
						va_list args);

t_list					*format_list(const char *format, va_list args);
void					format_delete(void **data);
int						doutput(const char *format, t_list *node, int fd);
int						soutput(char **dst, const char *fmt, t_list *node);

void					extract_flags(char **spec, t_format *format);
void					extract_size(char **spec, t_format *format);
void					extract_width(char **spec, t_format *format,\
						va_list args);
void					extract_precision(char **spec, t_format *format,\
						va_list args);
int						extract_type(char **spec, t_format *format,\
						va_list args);

void					type_signed_integer(t_format *format, va_list args);
void					type_unsigned_integer(t_format *format, va_list args);
void					type_float(t_format *format, va_list args);
void					type_other(t_format *format, va_list args);

char					*precision(t_format *format, char *tmp);
char					*width(t_format *format, char *tmp);
char					*prefix(t_format *format, char *tmp);
char					*sign(t_format *format, char *tmp, char flag);
char					*unsigned_convert(t_format *format);

void					pointer(t_format *format);
void					string(t_format *format);
void					digit(t_format *format);
void					character(t_format *format);
void					u_integer(t_format *format);
void					binary(t_format *format);
void					octal(t_format *format);
void					hexadecimal(t_format *format);
void					doubles(t_format *format);

char					*ft_itoa(int n);
char					*ft_llitoa(long long n);
char					*ft_ullitoa(unsigned long long int n);
long long				ft_atoll_base(char *str, char *base);
unsigned long long		ft_atoull_base(char *str, char *base);

char					*ft_strinsert(char **str, char c, size_t index);
size_t					ft_strspn(const char *s, const char *charset);
size_t					ft_strcspn(const char *s, const char *charset);
int						ft_ringbuffer(char *str, int fd);

int						**ft_int_2d(int it, int jt);
void					ft_free_int_2d(int **tab, int il);
void					ft_free_2d(char **tab);

#endif
