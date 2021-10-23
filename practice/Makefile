LIBA_PF = libftprintf.a

LIBA = libft.a

NAME = practice

CFLAGS = -Wall -Wextra -Werror

CC = gcc -g -o

SRCS = signals.c

OBJS = ${SRCS:.c=.o}

RM	= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		${CC} ${NAME} ${OBJS} ${LIBA} ${LIBA_PF}

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all re clean fclean 