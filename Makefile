# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 05:36:48 by iel-mach          #+#    #+#              #
#    Updated: 2022/03/21 05:38:01 by iel-mach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror
SRCS = ft_split.c ft_strjoin.c ft_substr.c ft_utils.c main.c


all : $(NAME)

$(NAME) : $(SRCS)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)
	@echo "✅✅✅"

clean :
	@rm -f $(NAME)
	@echo "🗑️ 🗑️ 🗑️"

fclean : clean

re : fclean all