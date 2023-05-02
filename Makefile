NAME 	= fdf

SRCS =	main.c						\
		matrex.c 					\
		read_fdf.c 					\
		draw_map.c 					\
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

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -rf

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : ${NAME}

${NAME}: ${OBJS}
			${CC} ${OBJS}  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean all re