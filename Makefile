# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/03 17:52:00 by wkerdad           #+#    #+#              #
#    Updated: 2026/01/03 17:53:15 by wkerdad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc -Wall -Wextra -Werror
RM			= rm -f

SRCS		= main.c \
			  check.c \
			  cost.c \
			  error_handling.c \
			  execute_move.c \
			  ft_split.c \
			  index.c \
			  join_split.c \
			  list_utils.c \
			  opr_1.c \
			  opr_2.c \
			  opr_3.c \
			  opr_4.c \
			  position.c \
			  push_swap.c \
			  sort_small.c \
			  sort_utils.c

OBJS		= $(SRCS:.c=.o)

BONUS_NAME = checker

BONUS_SRCS = checker_bonus.c \
             checker_bonus_uti.c \
             check.c \
             error_handling.c \
             ft_split.c \
             join_split.c \
             list_utils.c \
             opr_1.c \
             opr_2.c \
             opr_3.c \
             opr_4.c \
             index.c \
             get_next_line.c \
             get_next_line_utils.c \
             cost.c \
             execute_move.c \
             sort_utils.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADER		= header.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus