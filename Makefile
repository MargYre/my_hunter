##-lcsfml-window -lcsfml-graphics -lcsfml-system
## EPITECH PROJECT, 2018
## MUL_my_hunter_2018
## File description:
## Makefile
##

CC		= 		gcc

RM 		=		rm -rf

SRC		=		src/main.c					\
				src/basic_tool.c			\
				src/h_option.c				\
				src/init_data.c				\
				src/set_thing_in_window.c	\
				src/display_sprite.c		\
				src/close_window.c

CFLAGS	=		-I./include

OBJ		=		$(SRC:.c=.o)

NAME	=		my_hunter

all: $(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean all
