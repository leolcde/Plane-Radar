##
## EPITECH PROJECT, 2024
## mkfile
## File description:
## mkfile
##

.SILENT:

CC	=	gcc

SRC	=	$(wildcard src/*.c)

SRC2 =  include/my.h    \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	 rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
