NAME = vector

MAIN = ./main.cpp

SRC = $(MAIN)

INC = ./vector.hpp ../utils/reverse_iterator.hpp  ./random_access_iterator.hpp ./enable_if.hpp is_integral.hpp

DBUG = -fsanitize=address -g

FLAG = -Wall -Wextra -Werror -std=c++98 #$(DBUG)

CPP = c++ $(FLAG)

all: $(NAME)

$(NAME): $(INC) $(SRC)
	@ $(CPP) $(SRC) -o $(NAME)

clean:
	@echo -n
	@rm -f ./a.out

fclean: clean
	@rm -f $(NAME)

re: all fclean

.PHONY: all clean fclean re
