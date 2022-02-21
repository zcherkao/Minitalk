# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 16:54:31 by zcherkao          #+#    #+#              #
#    Updated: 2022/01/13 15:16:08 by zcherkao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

NAME = Minitalk

NAMES = server

NAMEC = client

SRC = ft_printf.c \
	ft_printf_utils.c \
	ft_printf_utils2.c \

SRC_S = server.c

SRC_C = client.c

SRC_SB = server_bonus.c

SRC_CB = client_bonus.c

OBJ = ${SRC:.c=.o}

OBJS = 	${SRC_S:.c=.o}

OBJC = ${SRC_C:.c=.o}

OBJSB = ${SRC_SB:.c=.o}

OBJCB = ${SRC_CB:.c=.o}

%.o : %.c minitalk.h
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): ${OBJ} $(OBJS) ${OBJC}
		${CC} ${CFLAGS} ${SRC} $(SRC_S) -o $(NAMES)
		${CC} ${CFLAGS} ${SRC} $(SRC_C) -o $(NAMEC)
		
bonus : ${OBJ} $(OBJSB) ${OBJCB}
		${CC} ${CFLAGS} ${SRC} $(SRC_SB) -o $(NAMES)
		${CC} ${CFLAGS} ${SRC} $(SRC_CB) -o $(NAMEC)
			
clean: 
		$(RM) $(OBJ) $(OBJS) $(OBJC) ${OBJSB} ${OBJCB}

fclean: clean
		$(RM) $(NAME) $(NAMES) $(NAMEC)

re: fclean $(NAME)
	
.PHONY: all clean fclean re			
