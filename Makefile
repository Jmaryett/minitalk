NAME_CL = client

HEADER_SV = server.h
		
HEADER_CL = client.h

NAME_SV = server

LIBA = libft.a

LIBA_C = ./libft/*.c

LIBA_H = ./libft/libft.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc -g -o

SRCS_CL = client.c \
		errors.c

SRCS_SV = server.c \
		errors.c

OBJS_CL = ${SRCS_CL:.c=.o}

OBJS_SV = ${SRCS_SV:.c=.o}

RM	= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME_CL} ${NAME_SV}

${LIBA}: ${LIBA_C} ${LIBA_H}
		cd ./libft; \
		make; \
		mv ${LIBA} ../; \
		make clean; \
		cd ..

${NAME_CL}: ${OBJS_CL} ${HEADER_CL} ${LIBA}
		${CC} ${NAME_CL} ${OBJS_CL} ${LIBA}

${NAME_SV}: ${OBJS_SV} ${HEADER_SV} ${LIBA}
		${CC} ${NAME_SV} ${OBJS_SV} ${LIBA}

clean:
	${RM} ${OBJS_CL} ${OBJS_SV}

fclean: clean
		${RM} ${NAME_CL} ${NAME_SV} ${LIBA}

re:	fclean all

.PHONY: all re clean fclean 