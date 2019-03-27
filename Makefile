# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 17:06:21 by nrechati          #+#    #+#              #
#    Updated: 2019/03/27 15:54:36 by nrechati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HashMap

LDFLAGS = -L Libft -lft
LIB_DIR = -I includes -I Libft
SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
AUX_DEPS = Libft/libft.h includes/hashmap.h
LIB_AUX_DEPS = Libft/libft.a

# *************** SRC **************** #

VPATH = ./srcs

SRC += main.c
SRC += ft_hash_str.c
SRC += ft_hmap_getdata.c
SRC += ft_hmap_init.c
SRC += ft_hmap_insert.c
SRC += ft_hmap_print.c
SRC += ft_hmap_remove.c
SRC += ft_hmap_resize.c
SRC += ft_hmap_free_content.c

# *************** OBJ **************** #

OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# *************** GCC **************** #

CFLAGS = -Wall -Wextra -Werror $(LIB_DIR)
FSANITIZE = -fsanitize=address

GCSUCCES = @echo "\033[33;32m===> HashMap Compil\tSUCCESS"
CLSUCCES = @echo "\033[33;31m===> HashMap Cleanup\tSUCCESS"
FCLSUCCES = @echo "\033[33;31m===> HashMap FCleanup\tSUCCESS"

# *************** MAKE *************** #

all: $(NAME)

$(NAME): $(OBJ) $(LIB_AUX_DEPS)
	@gcc $(OBJ) -o $(NAME) $(LDFLAGS)
	$(GCSUCCES)

Libft/libft.a: Libft Libft/srcs
	@make -C Libft

$(OBJ_PATH)%.o: %.c Makefile $(AUX_DEPS)
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(CFLAGS) -o $@ -c $<

sanitize :
	@gcc $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS) $(FSANITIZE)

debug :
	@gcc -g $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf HashMap.dSYM
	@make -C Libft fclean
	$(CLSUCCES)

fclean: clean
	@rm -rf $(NAME)
	$(FCLSUCCES)

re: fclean all

.PHONY : all clean fclean re
