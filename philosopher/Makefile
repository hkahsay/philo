# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 20:19:13 by hkahsay           #+#    #+#              #
<<<<<<< HEAD:philosopher/Makefile
#    Updated: 2023/01/31 12:09:57 by hkahsay          ###   ########.fr        #
=======
#    Updated: 2023/01/31 18:47:09 by mac              ###   ########.fr        #
>>>>>>> 1dd5581d7c68b59bbd73292705e16065a6e76dc1:Makefile
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = 	src/check_num.c \
		src/init.c \
		src/parsing.c \
		src/main.c \

		

OBJS			= ${SRCS:.c=.o}	

CC				= gcc

RM				= rm -f

CFLAGS			= -g -Wall -Werror -Wextra -pthread



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
			