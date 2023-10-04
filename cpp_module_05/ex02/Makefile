NAME = Bureaucrat

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCDIR = ./src/

SRCFILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJFILES = $(SRCFILES:.cpp=.o)
OBJ = $(addprefix $(SRCDIR), $(OBJFILES))

# silence the output 
.SILENT:

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	make clean
	echo "\033[30;43;1;3m Compilation done \033[0m"

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

run: 
	./$(NAME)
