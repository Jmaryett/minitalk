LIBFT = -L libft -lft

LIBFT_C = ./libft/*.c

LIBFT_A = ./libft/libft.a

NAME = libftprintf.a
	
HEADER	= ft_printf.h \

SRCS	= ft_printf.c \
		add_func_c_s_p_percent.c \
		add_func_d_i.c \
		add_func_u_x_X.c \
		add_func_u_x_X_2.c \
		1_checking_symbols_for_flags.c \
		2_analyzing_flags.c \
		3_analyze_type.c \
		4_type_is_char.c \
		5_type_is_str.c \
		6_type_is_pointer.c \
		7_type_is_integer.c \
		8_type_is_u.c \
		9_type_is_x_X.c \
		10_type_is_percent.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

AR	= ar rc

CFLAGS 	= -Wall -Wextra -Werror

LIBA = libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

compile_libft: ${LIBFT_A}

${LIBFT_A}:
			cd ./libft; \
			make; \
			cp ${LIBA} ../; \
			make clean; \
			cd ..;
			mv ${LIBA} ${NAME}
	
${NAME}:	${LIBFT_A} ${OBJS} ${HEADER}
			${AR} ${NAME} ${OBJS}


clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIBFT_A}
		
test:	${LIBFT_A}
		${CC} -g main.c ${SRCS} ${LIBFT_A}
		${RM} ${OBJS} ${LIBFT_A} ${NAME}

norm:	
		norminette ${SRCS} ${HEADER}

re:		fclean all

.PHONY: re clean fclean all test compile_libft norm