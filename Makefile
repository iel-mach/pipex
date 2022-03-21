# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 05:36:48 by iel-mach          #+#    #+#              #
#    Updated: 2022/03/22 00:06:43 by iel-mach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror
SRCS = ./Mandatory/ft_split.c ./Mandatory/ft_strjoin.c ./Mandatory/ft_substr.c ./Mandatory/ft_utils.c ./Mandatory/main.c


all : $(NAME)

$(NAME) : $(SRCS)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)
	@echo "✅✅✅"

clean :
	@rm -f $(NAME)
	@echo "🗑️ 🗑️ 🗑️"

fclean : clean

re : fclean all