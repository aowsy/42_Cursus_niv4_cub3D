# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 16:56:01 by mdelforg          #+#    #+#              #
#    Updated: 2022/06/21 18:15:05 by mdelforg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = srcs/main.c \
	   srcs/init.c \
	   srcs/raycast.c \
	   srcs/keyhook.c \
	   srcs/texturing.c \
	   srcs/so_long/so_long.c \
	   srcs/so_long/background.c \
	   srcs/so_long/error.c \
	   srcs/so_long/map_check.c \
	   srcs/so_long/map_check_elem.c \
	   srcs/so_long/map_init.c \
	   srcs/so_long/move.c \
	   srcs/so_long/gnl/get_next_line.c \
	   srcs/so_long/gnl/get_next_line_sl.c \
	   srcs/so_long/gnl/get_next_line_utils.c \
	   srcs/so_long/libft/ft_bzero.c \
	   srcs/so_long/libft/ft_calloc.c \
	   srcs/so_long/libft/ft_memcpy.c \
	   srcs/so_long/libft/ft_memset.c \
	   srcs/so_long/libft/ft_strchr.c \
	   srcs/so_long/libft/ft_strdup.c \
	   srcs/so_long/libft/ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

LINKS = -lmlx -framework OpenGL -framework AppKit

$(NAME):	$(OBJS)
				$(CC) $(OBJS) $(LINKS) -o $(NAME)

all:		$(NAME)

exe:		all clean

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		exe clean fclean re
