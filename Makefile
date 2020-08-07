NAME = bsq

SRCS	= srcs/ft_utils.c srcs/ft_grid.c srcs/ft_parsing.c \
		srcs/ft_valid_line.c srcs/main.c

OBJS	= ${SRCS:.c=.o}
INCS	= includes
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -O3

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME} : ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

run :
	./${NAME}

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${NAME}


re : fclean all

.PHONY: all clean fclean re .c.o
