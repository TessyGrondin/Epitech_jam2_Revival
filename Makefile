##
## EPITECH PROJECT, 2023
## loadmap
## File description:
## Makefile
##

SRC = 	main.cpp\
		src/Animation.cpp\
		src/LayerMap.cpp\
		src/Map.cpp\
		src/Sprite.cpp\
		src/SpriteSheet.cpp\
		src/TextBox.cpp\
		src/GameState.cpp\
		src/Hole.cpp\
		src/End.cpp\
		src/Menu.cpp\
		src/Dialogue.cpp\

NAME = one-for-one

OBJ = $(SRC:.cpp=.o)

FLAGS = -W -Wall -Wextra -Werror -lsfml-graphics -lsfml-window \
	 -I include/ -lsfml-system -lsfml-audio -g -ggdb -g3 -lm

all:
	g++ -o $(NAME) $(SRC) $(FLAGS)

