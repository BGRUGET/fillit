# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: themarch <themarch@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 22:33:19 by themarch     #+#   ##    ##    #+#        #
#    Updated: 2019/01/15 19:10:00 by themarch    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME= libft.a

SRC  =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strdup.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_putnbr.c \
		ft_putendl.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_memdel.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_strtrim.c \
		ft_lstnew.c \
		ft_putestr.c \
		ft_isupper.c \
		ft_islower.c \
		ft_isspace.c \
		ft_count_word.c\
		ft_count_word_caract.c \
		ft_memrcpy.c \
		ft_range.c \
		ft_get_next_line.c \
		ft_strcharlen.c \
		ft_putnbr2.c

SRCO =  $(SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall -c 

CC = gcc 

all : $(NAME) 

$(NAME): $(SRCO)
		@ar -rc $(NAME) $(SRCO)

%.o : %.c
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m Libft compiling:\033[0m" $<
		@gcc $(FLAGS) -o $@ -c $^
clean :
		@rm -rf $(SRCO)
		@echo "\033[0;32m [OK] \033[0m       \033[0;33m Libft file.o deleted\033[0m"
 
fclean : clean
		@rm -rf $(NAME)
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m Libft deleted\033[0m"
re : fclean all

.PHONY: clean re all fclean
