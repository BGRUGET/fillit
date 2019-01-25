# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/10 21:48:50 by themarch     #+#   ##    ##    #+#        #
#    Updated: 2019/01/16 11:06:23 by begruget    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

OBJ_PATH= ./obj/
SRC_PATH=./

SRC_NAME =	srcs/ft_parsing.c \
			srcs/main.c \
			srcs/ft_recup_piece.c \
			srcs/ft_tools.c \
			srcs/ft_tools2.c \
			srcs/algo.c \
			srcs/ft_recup_piece2.c \
			srcs/ft_recup_piece3.c

OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

ifndef FLAGS
FLAGS= -Wall -Werror -Wextra
endif

all : $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@make -C libft/

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)srcs/

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
		@make -C libft/
		@gcc $(FLAGS) -o $(NAME) $(SRC_NAME) libft/libft.a
		@gcc $(FLAGS) -o $@ -c $<
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m FILLIT CREATED:\033[0m" $<

clean :
		@rm -rf $(OBJ_PATH)
		@make clean -C libft
		@rm -rf fillitdebug
		@echo "\033[0;32m [OK] \033[0m       \033[0;33m .o files deleted\033[0m"
 
fclean : clean
		@rm -rf $(NAME)
		@make fclean -C libft
		@rm -rf fillitdebug
		@rm -rf fillitdebug.dSYM
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m exec files deleted\033[0m"

re : fclean all

debug : $(NAME)
		@gcc -g -o fillitdebug srcs/*.c libft/libft.a
		@lldb ./fillitdebug test

delet :
		@rm -rf fillitdebug
		@rm -rf fillitdebug.dSYM
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m DEBUG DELETED\033[0m"

.PHONY: clean re all fclean
