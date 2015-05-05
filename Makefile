##
## Makefile for epitech in /home/chapui_s/rendu/
##
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
##
## Started on  Tue Apr 28 04:19:54 2015 chapui_s
## Last update Tue May  5 07:58:35 2015 chapui_s
##

NAME		= strace

SRC		= src/strace.c			\
		  src/usage.c			\
		  src/puts.c			\
		  src/get_params.c		\
		  src/nums_syscalls.c		\
		  src/nums_syscalls32.c		\
		  src/paths.c			\
		  src/print/print_int.c		\
		  src/print/print_size_t.c	\
		  src/print/print_ssize_t.c	\
		  src/print/print_off_t.c	\
		  src/print/print_void_ptr.c	\
		  src/print/print_char_ptr.c	\
		  src/functions/mmap.c		\
		  src/functions/access.c	\
		  src/functions/open.c		\
		  src/functions/read.c		\
		  src/functions/mprotect.c	\
		  src/functions/print_generic.c	\
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
