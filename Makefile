##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that build the project
##

.SILENT:

CC	=	gcc

CFLAGS	=	-g -I includes/

SRC		=	src/my_radar.c \
			src/parsing/my_str_to_int.c \
			src/parsing/plane_parsing.c \
			src/parsing/tower_parsing.c \
			src/parsing/compute_node.c \
			src/parsing/script_parsing.c \
			src/sprite/airplane.c \
			src/sprite/tower.c \
			src/sprite/background.c \
			src/timer/init_timer.c \
			src/timer/display_timer.c \

OBJ		=	$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

NAME	=	my_radar

LIB	=	-L./lib -lmy
INCLUDE	=	-I./include

MAKE	=	make

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib
	$(CC) $(OBJ) $(LIB) $(INCLUDE) -o $(NAME) $(CFLAGS) $(CSFML)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C lib clean

fclean: clean
	rm -f $(NAME)
	rm -f coding-style-reports.log
	$(MAKE) -C lib fclean

re: fclean all
