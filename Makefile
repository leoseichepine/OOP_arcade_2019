##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CORE_MAIN						=	./src/main.cpp

CORE_NAME						=	arcade

CORE_SRC						=	./src/Core.cpp			\
									./src/Drawables.cpp

CC								=	g++

CXXFLAGS						=	-std=c++17 -I./include/ -Wall -Wextra -ldl -g

OBJ								=	$(CORE_SRC:.cpp=.o)
OBJ_MAIN						=	$(CORE_MAIN:.cpp=.o)

$(NAME):	$(OBJ) $(OBJ_MAIN)
			$(CC)  -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CXXFLAGS)
all:		core

core:
			$(CC) -o $(CORE_NAME) $(CORE_SRC) $(CORE_MAIN) $(CXXFLAGS)

debug:
			$(CC) -o $(NAME) $(SRC) $(MAIN_FILE) $(CXXFLAGS)

clean:
			rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)

fclean:
			rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME) $(CORE_NAME)

re:			fclean all

.PHONY:		all clean fclean re debug
