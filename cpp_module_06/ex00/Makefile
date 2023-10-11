NAME = Converter

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCDIR = ./src/

SRC = main.cpp ScalarConverter.cpp
OBJ = $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@ make clean

%.o:	%.cpp	
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@ rm -f $(OBJ)

fclean:	clean
	@ rm -f $(NAME)

re: fclean all

run: 
	@ ./$(NAME)