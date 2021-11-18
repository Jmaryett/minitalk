NAME_CL = client

HEADER = minitalk.h

NAME_SV = server

#LIBA = libft.a

#LIBA_C = ./libft/*.c

#LIBA_H = ./libft/libft.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS_CL = client.c

SRCS_SV = server.c 

UTILS = utils.c

OBJS_CL = ${SRCS_CL:.c=.o}

OBJS_SV = ${SRCS_SV:.c=.o}

OBJS_UT = ${UTILS:.c=.o}

RM	= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME_CL} ${NAME_SV}

#${LIBA}: ${LIBA_C} ${LIBA_H}
#		cd ./libft; \
		make; \
		mv ${LIBA} ../; \
		make clean; \
		cd ..

${NAME_CL}: ${OBJS_CL} ${OBJS_UT} ${HEADER}
		${CC} ${CFLAGS} -o ${NAME_CL} ${OBJS_CL} ${OBJS_UT}

${NAME_SV}: ${OBJS_SV} ${OBJS_UT} ${HEADER}
		${CC} ${CFLAGS} -o ${NAME_SV} ${OBJS_SV} ${OBJS_UT}

clean:
	${RM} ${OBJS_CL} ${OBJS_SV}

fclean: clean
		${RM} ${NAME_CL} ${NAME_SV}

re:	fclean all

norm:
	norminette ${SRCS_CL} ${SRCS_SV} ${UTILS} ${HEADER}

.PHONY: all re clean fclean 