
COMPILER = c++
FLAGS = --std=c++98 -Wall -Wextra -Werror 
NAME =	ft_containers

SRC =	main.cpp
		





all : $(NAME)

$(NAME): $(SRC)
		
		@$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all
