# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 13:49:23 by ymirna            #+#    #+#              #
#    Updated: 2022/09/17 20:23:05 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

PATH_M		=	mandatory/

PATH_H		=	headers/

SRC_M		=	aleatory.c basic_ft_1.c basic_ft_2.c basic_ft_3.c basic_ft_4.c basic_ft_5.c basic_ft_6.c create_here_doc.c \
				env_1.c env_2.c env_3.c env_fake.c error_command.c exec.c exit_1.c exit_2.c expend_words.c file_ft_1.c forking.c \
				free_1.c free_2.c free_3.c free_4.c free_5.c get_ft_1.c get_ft_2.c init_1.c init_env.c init_token.c limiter.c main.c \
				multy_fork.c open_fd.c organize_arg.c parcer.c pipex.c quotes.c split_arg_1.c split_arg_2.c str_env_1.c str_env_2.c \
				word_modif.c built_0.c built_1.c built_2.c built_3.c built_4.c built_5.c 

HEADER		=	min.h

SRC_M_P		=	$(addprefix $(PATH_M), $(SRC_M))

HEADER_P	=	$(addprefix $(PATH_H), $(HEADER))

OBJS_M		=	$(SRC_M_P:%.c=%.o)

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra

.PHONY:		all re clean fclean

%.o : %.c	$(HEADER_P)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS_M) Makefile
			$(CC) $(FLAGS) $(OBJS_M) -lreadline -o $(NAME)			

clean:		
			rm -f $(OBJS_M)

fclean:		clean
			rm -f $(NAME)

re:			fclean all