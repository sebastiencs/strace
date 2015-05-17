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

SRC		= src/arch.c			\
		  src/exit.c			\
		  src/get_params.c		\
		  src/my_str_to_wordtab.c	\
		  src/paths.c			\
		  src/puts.c			\
		  src/signal.c			\
		  src/strace.c			\
		  src/syscall.c			\
		  src/usage.c			\
		  src/print/print_char_ptr.c	\
		  src/print/print_int.c		\
		  src/print/print_off_t.c	\
		  src/print/print_size_t.c	\
		  src/print/print_ssize_t.c	\
		  src/print/print_void_ptr.c	\
		  src/functions/access.c	\
		  src/functions/mmap.c		\
		  src/functions/mprotect.c	\
		  src/functions/open.c		\
		  src/functions/print_generic.c \
		  src/functions/read.c

OBJ		= $(SRC:.c=.o)

INCLUDES	= ./includes

CC		= gcc

RM		= rm -f

override CFLAGS	+= -W -Wall -Wextra -I $(INCLUDES)

%.o:		%.c
		@$(CC) -c -o $@ $<  $(CFLAGS)
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< |  tr ' ' '.'

all:		$(NAME)

$(NAME):	$(OBJ)
		@printf "[\033[0;36mGenerating\033[0m] % 27s\n" "64bits_syscalls" | tr ' ' '.'
		@./get_syscalls.sh /usr/include/asm/unistd_64.h
		@printf "[\033[0;36mGenerating\033[0m] % 27s\n" "32bits_syscalls" | tr ' ' '.'
		@./get_syscalls.sh /usr/include/asm/unistd_32.h
		@printf "[\033[0;36mGenerating\033[0m] % 27s\n" "signal_names" | tr ' ' '.'
		@./get_signal_names.sh
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

clean:
		@$(RM) $(OBJ)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;35mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re:		fclean all

.PHONY:		all clean fclean re
