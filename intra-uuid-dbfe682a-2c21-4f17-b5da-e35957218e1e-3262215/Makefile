SRCS		= srcs/check_first_str.c srcs/check_file_data.c srcs/check_input_data.c srcs/check_simple_data.c srcs/file_io_services.c srcs/main.c srcs/output.c srcs/output_services.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f
CC			= gcc

NAME		= BSQ

CFLAGS		= -Wall -Werror -Wextra -Wconversion -Iincludes/

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
