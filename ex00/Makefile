# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 13:25:55 by thlefebv          #+#    #+#              #
#    Updated: 2024/09/09 14:17:37 by thlefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= floatting

CC= c++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRC= main.cpp\
     Fixed.cpp

OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)