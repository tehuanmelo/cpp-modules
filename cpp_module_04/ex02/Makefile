# executale name 
NAME = animal

# flags
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# directories
OBJDIR = ./obj/
SRCDIR = ./src/

# source files
SRCFILES = Animal.cpp WrongAnimal.cpp Dog.cpp Cat.cpp WrongCat.cpp main.cpp Brain.cpp
# object files
OBJFILES = $(SRCFILES:.cpp=.o)

# paths
SRC = $(addprefix $(SRCDIR), $(SRCFILES))
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

# silence the output 
.SILENT:

# all rule 
all:	$(OBJDIR) $(NAME)

# compile executable
$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	echo "\033[30;43;1;3mCompilation done successfully!\033[0m"

# compile objects
$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# clean rule
clean:
	rm -rf $(OBJDIR)

# fclean rule
fclean: clean
	rm -f $(NAME)

# make re rule 
re: fclean all
