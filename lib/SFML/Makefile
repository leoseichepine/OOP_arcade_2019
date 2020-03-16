##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME			=	lib_arcade_sfml.so

SRC				=	IGraphicSFML.cpp		\

CC				=	g++

CFLAGS			=	-fpic -Wall -Wextra -g

LDFLAGS			=	-shared

OBJ				=	$(SRC:.cpp=.o)

$(NAME)			: 	$(OBJ)
					$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

all				: 	$(NAME)

debug			:
					$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean			:
					rm -f $(OBJ)

fclean			:
					rm -f $(OBJ)
					rm -f $(NAME) $(NAME_TEST)

re				:	fclean all

.PHONY			:	all clean fclean re debug