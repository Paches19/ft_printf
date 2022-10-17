# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpachec <adpachecstudent.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 10:47:50 by adpachec          #+#    #+#              #
#    Updated: 2022/10/17 14:55:46 by adpachec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

SRCM = ft_get_param.c ft_print_hex.c ft_print_int.c ft_print_mix.c \
ft_printf.c

SRCB = ft_get_form_param_bonus.c ft_print_hex_bonus.c ft_print_int_bonus.c \
ft_print_mix_bonus.c ft_printf_bonus.c ft_tools_bonus.c ft_print_ptr_bonus.c

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
INCLUDE_DIR = ./includes/
LIBFT_DIR = ./libft/

ifdef BONUS
INCLUDE = ft_printf_bonus.h
OBJ = $(SRCB:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(OBJ))
else
INCLUDE = ft_printf.h
OBJ = $(SRCM:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(OBJ))
endif

LIB = ar rcs
RM = rm -f

all: make-libft $(NAME)

ifdef BONUS
	$(RM) $(addprefix $(SRC_DIR),$(SRCM:.c=.o))
else
	$(RM) $(addprefix $(SRC_DIR),$(SRCB:.c=.o))
endif

$(NAME): $(SRC) $(addprefix $(INCLUDE_DIR),$(INCLUDE))
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(LIB) $(NAME) $(SRC)

bonus:
	$(MAKE) BONUS=1 all

%.o: %.c
		$(CC) $(FLAGS) -I $(INCLUDE_DIR) -c -o $@ $<

make-libft:
		make -C $(LIBFT_DIR)

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(RM) $(addprefix $(SRC_DIR),$(SRCM:.c=.o)) \
		$(addprefix $(SRC_DIR),$(SRCB:.c=.o))

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus