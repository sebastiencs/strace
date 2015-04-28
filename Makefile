##
## Makefile for epitech in /home/chapui_s/rendu/
##
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
##
## Started on  Tue Apr 28 04:19:54 2015 chapui_s
## Last update Tue Apr 28 07:34:41 2015 chapui_s
##

NAME		= strace

SRC		= src/strace.c			\
		  src/usage.c			\
		  src/puts.c			\
		  src/nums_syscalls.c		\
		  src/my_str_to_wordtab.c

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
