# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 20:19:13 by hkahsay           #+#    #+#              #
#    Updated: 2023/01/30 15:26:02 by hkahsay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = 	src/check_num.c \
		src/init.c \
		src/parsing.c \

		

OBJS			= ${SRCS:.c=.o}	

CC				= gcc

RM				= rm -f

CFLAGS			= -g -Wall -Werror -Wextra 



#Rules

all: 	${NAME}

.c.o:
		$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} 
clean:		
			${RM} ${OBJS}
			
fclean:		clean
			${RM} $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
			