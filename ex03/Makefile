NAME = Interface
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror  -std=c++98

SOURCE = AMateria.cpp Cure.cpp Ice.cpp Character.cpp  MateriaSource.cpp main.cpp
HEADER = AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

all: $(NAME)
$(NAME): $(SOURCE)  $(HEADER)
	$(CPP) $(CPPFLAGS) $(SOURCE) -o $(NAME)
clean:

fclean: clean
	rm -rf $(NAME)
re: fclean all
