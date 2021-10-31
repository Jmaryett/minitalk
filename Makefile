NAME_CL = client

HEADER = server.h \
		client.h

NAME_SV = server

#LIBA_PF = libftprintf.a

#LIBA_PF_C = ./printf/*.c

#LIBA_PF_H = ./printf/ft_printf.h

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

${NAME_CL}: ${OBJS_CL} ${HEADER} ${LIBA} ${LIBA_PF}
		${CC} ${NAME_CL} ${OBJS_CL} ${LIBA} ${LIBA_PF}

${NAME_SV}: ${OBJS_SV} ${HEADER} ${LIBA} ${LIBA_PF}
		${CC} ${NAME_SV} ${OBJS_SV} ${LIBA} ${LIBA_PF}

${LIBA}: ${LIBA_C} ${LIBA_H}
		cd ./libft; \
		make; \
		mv ${LIBA} ../; \
		make clean; \
		cd ..

#${LIBA_PF}: ${LIBA_PF_C} ${LIBA_PF_H}
#			cd ./printf; \
			make; \
			mv ${LIBA_PF} ../; \
			make clean; \
			cd ..

clean:
	${RM} ${OBJS_CL} ${OBJS_SV}

fclean: clean
		${RM} ${NAME_CL} ${NAME_SV} ${LIBA} ${LIBA_PF}

re:	fclean all

.PHONY: all re clean fclean 