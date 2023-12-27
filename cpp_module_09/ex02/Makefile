NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = ./obj/
SRCDIR = ./src/

SRC = main.cpp PmergeMe.cpp
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
	# @ ./$(NAME) `jot -r 10 1 1000 | tr "\n" " "`
	@ ./$(NAME) `shuf -i 1-3000 -n 5000 | tr "\n" " "`