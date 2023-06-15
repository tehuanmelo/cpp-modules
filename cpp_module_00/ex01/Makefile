NAME = phonebook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
OBJPATH = ./obj/
SRC = main.cpp Contact.cpp PhoneBook.cpp mainUtils.cpp
OBJ = $(addprefix $(OBJPATH), $(SRC:.cpp=.o))

.SILENT:

all:	$(OBJPATH) $(NAME)

$(OBJPATH):
	mkdir $(OBJPATH)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	echo "\033[30;43;1;3mCompilation done successfully!\033[0m"

$(OBJPATH)%.o:	%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re:		fclean all
