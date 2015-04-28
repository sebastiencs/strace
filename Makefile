##
## Makefile for epitech in /home/chapui_s/rendu/
##
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
##
## Started on  Tue Apr 28 04:19:54 2015 chapui_s
## Last update Tue Apr 28 04:20:05 2015 chapui_s
##

NAME		= strace

SRC		= src/strace.c

OBJ		= $(SRC:.c=.o)

INCLUDES	= ./includes

CC		= gcc

RM		= rm -f

override CFLAGS	+= -Wall -Wextra -I $(INCLUDES)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
