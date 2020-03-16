##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CORE_MAIN					=	./src/main.cpp

CORE_NAME					=	arcade

CORE_SRC					=	./src/Core.cpp

CC							=	g++

CFLAGS						=	-Wall -Wextra -ldl

OBJ							=	$(SRC:.cpp=.o)
OBJ_MAIN					=	$(CORE_MAIN:.cpp=.o)

$(NAME):	$(OBJ) $(OBJ_MAIN)
			$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS)

all:		core

core:
			$(CC) -o $(CORE_NAME) $(CORE_SRC) $(CORE_MAIN) $(CFLAGS) -g

debug:
			$(CC) -o $(NAME) $(SRC) $(MAIN_FILE) $(CFLAGS) -g

clean:
			rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)

fclean:
			rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re debug
