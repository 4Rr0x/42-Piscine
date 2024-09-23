SRCS = srcs/ft_putchar.c srcs/ft_sawp.c srcs/ft_putstr.c srcs/strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = libft.a
LIBC = ar rc
LIBR = ranlib
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} .c $< .o ${<:.c=.o} -I ${INCS}

$NAME: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${CLEAN} ${NAME}

re: fclean all
