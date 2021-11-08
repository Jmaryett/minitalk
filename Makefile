NAME_CL = client

HEADER_SV = server.h
		
HEADER_CL = client.h

NAME_SV = server

LIBA = libft.a

LIBA_C = ./libft/*.c

LIBA_H = ./libft/libft.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS_CL = client.c

SRCS_SV = server.c 

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
		${CC} ${CFLAGS} -o ${NAME_CL} ${OBJS_CL} errors.c ${LIBA}

${NAME_SV}: ${OBJS_SV} ${HEADER_SV} ${LIBA}
		${CC} ${CFLAGS} -o ${NAME_SV} ${OBJS_SV} errors.c ${LIBA}

clean:
	${RM} ${OBJS_CL} ${OBJS_SV}

fclean: clean
		${RM} ${NAME_CL} ${NAME_SV} ${LIBA}

re:	fclean all

.PHONY: all re clean fclean 