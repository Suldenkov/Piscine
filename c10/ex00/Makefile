SRCS	=  ft_display_file.c

SRC		= ft_display_file.o

OBJS	= ${SRCS:.c=.o}

NAME	= ft_display_file

GCC		= gcc

FLAG	= -Wall -Werror -Wextra

.c.o:		${GCC} ${FLAG} -c  $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${SRC}

all:		${NAME}

clean:
			rm ${OBJS}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all clean fclean

