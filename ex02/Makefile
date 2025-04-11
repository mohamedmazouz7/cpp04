NAME = Abstract
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror  -std=c++98

SOURCE = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp main.cpp 
HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

all: $(NAME)
$(NAME): $(SOURCE)  $(HEADER)
	$(CPP) $(CPPFLAGS) $(SOURCE) -o $(NAME)
clean:

fclean: clean
	rm -rf $(NAME)
re: fclean all
