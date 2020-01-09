# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:42:25 by nrechati          #+#    #+#              #
#    Updated: 2019/10/02 12:49:28 by nrechati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a

SRC_PATH = ./srcs/
OBJ_PATH = ./obj
# *************** SRC **************** #

SRC += $(SRC_PATH)ft_tolower.c
SRC += $(SRC_PATH)ft_toupper.c

SRC += $(SRC_PATH)ft_isalpha.c
SRC += $(SRC_PATH)ft_isdigit.c
SRC += $(SRC_PATH)ft_isalnum.c
SRC += $(SRC_PATH)ft_isascii.c
SRC += $(SRC_PATH)ft_isprint.c
SRC += $(SRC_PATH)ft_isspace.c

SRC += $(SRC_PATH)ft_bzero.c
SRC += $(SRC_PATH)ft_memalloc.c
SRC += $(SRC_PATH)ft_memdel.c
SRC += $(SRC_PATH)ft_memset.c
SRC += $(SRC_PATH)ft_memcpy.c
SRC += $(SRC_PATH)ft_memccpy.c
SRC += $(SRC_PATH)ft_memchr.c
SRC += $(SRC_PATH)ft_memcmp.c
SRC += $(SRC_PATH)ft_memmove.c

SRC += $(SRC_PATH)ft_strlen.c
SRC += $(SRC_PATH)ft_strdup.c
SRC += $(SRC_PATH)ft_strstr.c
SRC += $(SRC_PATH)ft_strnstr.c
SRC += $(SRC_PATH)ft_strcmp.c
SRC += $(SRC_PATH)ft_strncmp.c
SRC += $(SRC_PATH)ft_strcpy.c
SRC += $(SRC_PATH)ft_strncpy.c
SRC += $(SRC_PATH)ft_strcat.c
SRC += $(SRC_PATH)ft_strncat.c
SRC += $(SRC_PATH)ft_strlcat.c
SRC += $(SRC_PATH)ft_strchr.c
SRC += $(SRC_PATH)ft_strrchr.c
SRC += $(SRC_PATH)ft_strnrchr.c
SRC += $(SRC_PATH)ft_strjoin.c
SRC += $(SRC_PATH)ft_strclr.c
SRC += $(SRC_PATH)ft_strnew.c
SRC += $(SRC_PATH)ft_strdel.c
SRC += $(SRC_PATH)ft_striter.c
SRC += $(SRC_PATH)ft_striteri.c
SRC += $(SRC_PATH)ft_strmap.c
SRC += $(SRC_PATH)ft_strmapi.c
SRC += $(SRC_PATH)ft_strequ.c
SRC += $(SRC_PATH)ft_strnequ.c
SRC += $(SRC_PATH)ft_strsub.c
SRC += $(SRC_PATH)ft_strtrim.c
SRC += $(SRC_PATH)ft_strrev.c
SRC += $(SRC_PATH)ft_strclen.c
SRC += $(SRC_PATH)ft_strsplit.c
SRC += $(SRC_PATH)ft_strcspn.c
SRC += $(SRC_PATH)ft_strinsert.c
SRC += $(SRC_PATH)ft_strspn.c
SRC += $(SRC_PATH)ft_strupper.c

SRC += $(SRC_PATH)ft_putchar.c
SRC += $(SRC_PATH)ft_putchar_fd.c
SRC += $(SRC_PATH)ft_putstr.c
SRC += $(SRC_PATH)ft_putstr_fd.c
SRC += $(SRC_PATH)ft_putendl.c
SRC += $(SRC_PATH)ft_putendl_fd.c
SRC += $(SRC_PATH)ft_putnbr.c
SRC += $(SRC_PATH)ft_putnbr_fd.c
SRC += $(SRC_PATH)ft_putnbr_base.c

SRC += $(SRC_PATH)ft_lstnew.c
SRC += $(SRC_PATH)ft_lstdelone.c
SRC += $(SRC_PATH)ft_lstdel.c
SRC += $(SRC_PATH)ft_lstadd.c
SRC += $(SRC_PATH)ft_lstiter.c
SRC += $(SRC_PATH)ft_lstmap.c
SRC += $(SRC_PATH)ft_lstaddend.c
SRC += $(SRC_PATH)ft_lstsize.c
SRC += $(SRC_PATH)ft_lstrev.c
SRC += $(SRC_PATH)ft_lstat.c
SRC += $(SRC_PATH)ft_lstlen.c

SRC += $(SRC_PATH)ft_atoi.c
SRC += $(SRC_PATH)ft_itoa.c
SRC += $(SRC_PATH)ft_ullitoa.c
SRC += $(SRC_PATH)ft_llitoa.c
SRC += $(SRC_PATH)ft_atoll_base.c
SRC += $(SRC_PATH)ft_atoull_base.c
SRC += $(SRC_PATH)ft_swap.c
SRC += $(SRC_PATH)ft_convert_base.c
SRC += $(SRC_PATH)get_next_line.c
SRC += $(SRC_PATH)ft_abs.c
SRC += $(SRC_PATH)ft_ringbuffer.c

SRC += $(SRC_PATH)ft_int_2d.c
SRC += $(SRC_PATH)ft_free_int_2d.c
SRC += $(SRC_PATH)ft_free_2d.c

# ************** Printf *************** #

SRC += $(SRC_PATH)ft_printf.c
SRC += $(SRC_PATH)format.c
SRC += $(SRC_PATH)extract.c
SRC += $(SRC_PATH)type.c
SRC += $(SRC_PATH)widthprec.c
SRC += $(SRC_PATH)output.c
SRC += $(SRC_PATH)char.c
SRC += $(SRC_PATH)digit.c
SRC += $(SRC_PATH)u_int.c
SRC += $(SRC_PATH)binary.c
SRC += $(SRC_PATH)octal.c
SRC += $(SRC_PATH)hexadecimal.c
SRC += $(SRC_PATH)doubles.c
SRC += $(SRC_PATH)string.c
SRC += $(SRC_PATH)pointer.c

# *************** OBJ **************** #

OBJ = $(patsubst $(SRC_PATH)%.c, %.o, $(SRC))

# *************** GCC **************** #

FLAG = -Wall -Wextra -Werror -I .

GCSUCCES = @echo "\033[33;32m===> Libft Compilation\tSUCCESS"
CLSUCCES = @echo "\033[33;31m===> Libft Cleanup\tSUCCESS"
FCLSUCCES = @echo "\033[33;31m===> Libft Full Cleanup\tSUCCESS"

# *************** MAKE *************** #

all: $(NAME)

$(NAME): $(SRC)
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(FLAG) $(SRC)
	@ar rcs $(NAME) $(OBJ)
	@mv $(OBJ) $(OBJ_PATH)
	$(GCSUCCES)

clean:
	@rm -rf $(OBJ_PATH)
	$(CLSUCCES)

fclean: clean
	@rm -rf $(NAME)
	$(FCLSUCCES)

re: fclean all

.PHONY : all clean fclean re
