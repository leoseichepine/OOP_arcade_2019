##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME				=	lib_arcade_nibbler.so

SRC					=	Nibbler.cpp		\
						./../../src/Drawables.cpp

CC					=	g++

CXXFLAGS			=	-std=c++17 -I./../../include -fPIC -shared -ldl

OBJ					=	$(SRC:.cpp=.o)

all					: 	$(NAME)

$(NAME)				: 	$(OBJ)
						$(CC) $(OBJ) $(CXXFLAGS) -o $(NAME)

clean				:
						rm -f $(OBJ)

fclean				:
						rm -f $(OBJ)
						rm -f $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re debug