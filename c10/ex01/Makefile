SRCS	=  ft_cat.c

SRC		= ft_cat.o

OBJS	= ${SRCS:.c=.o}

NAME	= ft_cat

GCC		= gcc

FLAG	= -Wall -Werror -Wextra

.c.o:		${GCC} ${FLAG} -c  $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${OBJS}
clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all clean fclean

