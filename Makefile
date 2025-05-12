# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 18:06:52 by mgenoves          #+#    #+#              #
#    Updated: 2024/09/20 13:10:42 by mgenoves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
		checks/check_args.c checks/final_check.c \
		libft/ft_putstr_fd.c libft/ft_isdigit.c libft/ft_atoi.c \
		libft/ft_strlen.c libft/ft_split.c libft/ft_substr.c libft/ft_strcmp.c \
		libft/ft_strlcpy.c \
		utils/random.c utils/random_stack.c \
		algo/move_r.c algo/move_rr.c algo/move_s_p.c algo/sort.c \
		algo/mturk.c algo/mturk_a.c algo/mturk_b.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

git:
	git add .
	git commit -m "update"
	git push

test:
	clear
	make
	cp ./push_swap ./Push-Swap-Tester
	sh ./Push-Swap-Tester/push_swap_test_linux.sh 10 10

try:
	clear
	make
	ARG="88 3 2 5 99 4 1 77 9 8 7 55"; ./push_swap $$ARG

count:
	clear
	make
	ARG="88 3 2 5 99 4 1 77 9 8 7 55"; ./push_swap $$ARG | wc -l
	
check:
	make
	ARG="88 3 2 5 99 4 1 77 9 8 7 55"; ./push_swap $$ARG | ./checker_OS $$ARG

.PHONY: all clean fclean re
