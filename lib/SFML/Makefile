##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME				=	lib_arcade_sfml.so

SRC					=	IGraphicSFML.cpp		\
						./../../src/Drawables.cpp

CC					=	g++

CXXFLAGS			=	-std=c++17 -I./../../include -fPIC -shared -ldl

SFML_FLAGS			=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJ					=	$(SRC:.cpp=.o)

all					: 	$(NAME)

$(NAME)				: 	$(OBJ)
						$(CC) $(OBJ) $(CXXFLAGS) $(SFML_FLAGS) -o $(NAME)
						mv $(NAME) ../

clean				:
						rm -f $(OBJ)

fclean				:
						rm -f $(OBJ)
						rm -f $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re debug