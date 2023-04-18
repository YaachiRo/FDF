NAME 	= fdf

SRCS =	main.c					\
		read_fdf.c 				\
		gnl/get_next_line.c 		\
		gnl/get_next_line_utils.c 	\
		tools/ft_strncmp.c 			\
		tools/ft_atoi.c 			\
		tools/ft_split.c 			\
		tools/ft_strlcpy.c 			\
		tools/ft_strnstr.c 			\
		tools/ft_strlen.c 			\

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all : ${NAME}

${NAME}: ${OBJS}
			${CC}  ${OBJS} -o  ${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean all re