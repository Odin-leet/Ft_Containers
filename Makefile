# ************************************************************************************************** #
#                                                                                                    #
#                                                         :::   ::::::::   ::::::::  :::::::::::     #
#    Makefile                                          :+:+:  :+:    :+: :+:    :+: :+:     :+:      #
#                                                       +:+         +:+        +:+        +:+        #
#    By: mamoussa <mamoussa@student.1337.ma>           +#+      +#++:      +#++:        +#+          #
#                                                     +#+         +#+        +#+      +#+            #
#    Created: Invalid date        by                 #+#  #+#    #+# #+#    #+#     #+#              #
#    Updated: 2022/08/30 11:29:47 by aali-mou         ###   ########.fr        #
#                                                                                                    #
# ************************************************************************************************** #

COMPILER = g++
FLAGS_DEBUG = --std=gnu++11 -fsanitize=address -g3 -Wall-Wextra-Werror
FLAGS = -g3

vector_tle:
	@$(COMPILER) $(FLAGS_DEBUG)	Vector_tests_tle.cpp -o vector.out 

vector:
	@$(COMPILER) $(FLAGS_DEBUG)	Vector_tests.cpp -o vector.out 

map:
	@$(COMPILER) $(FLAGS_DEBUG)	 Map_tests.cpp -o map.out -g3

stack:
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 

set:
	@$(COMPILER) $(FLAGS)	Set_tests.cpp -o set.out 
clean:
	rm -f vector.out map.out stack.out set.out
