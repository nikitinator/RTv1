# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snikitin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 17:36:11 by snikitin          #+#    #+#              #
#    Updated: 2018/12/11 14:23:33 by snikitin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rtv1        
SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/
FRM_DIR := ./frm/

SRC :=	main.c\
		init.c\
		init_drawer.c\
		vector.c\
		vector_rotate.c\
		ray_new.c\
		ray_trace.c\
		camera.c\
		trace_rays.c\
		update_window.c\
		catch_exit.c\
		figures/sphere.c\
		figures/plane.c\
		figures/cylinder.c\
		figures/cone.c\
		figures/first_hit_distance.c\
		parser/parser_init_scene.c\
		shade.c
				
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

INC =	$(INC_DIR)camera.h\
		$(INC_DIR)figures.h\
		$(INC_DIR)ray.h\
		$(INC_DIR)rtv1.h\
		$(INC_DIR)vec_3.h\
		$(INC_DIR)parser.h\
		$(INC_DIR)object.h\



LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=    $(LIB_DIR)libft/
LIBFT_INC :=    $(LIBFT_DIR)/
LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)

SDL = $(SDL_DIR)SDL2
SDL_DIR = $(FRM_DIR)SDL2.framework/
SDL_INC = $(SDL_DIR)Headers/
SDL_FLAGS = $(SDL) -rpath $(FRM_DIR)
#SDL_FLAGS = -framework SDL2 -F $(FRM_DIR)

CC_FLAGS := -Wall -Wextra -Werror -O3
LINK_FLAGS := $(LIBFT_FLAGS) $(SDL_FLAGS)
HEADER_FLAGS := -I $(LIBFT_INC) -I $(SDL_INC) -I $(INC_DIR)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(INC) Makefile
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)/*/%.c $(INC)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
.PHONY: all clean fclean re
