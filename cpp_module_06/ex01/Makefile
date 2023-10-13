# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 13:02:07 by tehuanmelo        #+#    #+#              #
#    Updated: 2023/10/12 13:36:36 by tehuanmelo       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialization

CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

SRCDIR = ./src/

SRC = main.cpp Serializer.cpp
OBJ = $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

all:	$(NAME)	
	
$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@ make clean

%.o:	%.cpp	
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@ rm -f $(OBJ)

fclean: clean	
	@ rm -f $(NAME)

re: fclean all

run:
	@ ./$(NAME)