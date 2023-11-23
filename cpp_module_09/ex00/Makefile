NAME = btc

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = ./obj/
SRCDIR = ./src/

SRC = main.cpp BitcoinExchange.cpp
OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all:	$(OBJDIR) $(NAME) 

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp	
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@ rm -rf $(OBJDIR)

fclean:	clean
	@ rm -f $(NAME)

re: fclean all

run: 
	@ ./$(NAME) input.txt