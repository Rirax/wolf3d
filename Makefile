# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/10 23:19:13 by rlechapt          #+#    #+#              #
#    Updated: 2015/11/01 18:23:15 by rlechapt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

SRC = main.c \
	  get_map.c \
	  construct_map.c \
	  control_0.c \
	  control_1.c \
	  draw.c \
	  raycasting.c \

OBJ = $(SRC:%.c=%.o)

FLAGS = -g -Wall -Wextra -Werror

LIBS = -L libft/ -lft\
	   -L mlx/ -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I libft/ \
		   -I mlx/ \
		   -I includes/ \
		   -I /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIBS)

%.o: %.c 
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
