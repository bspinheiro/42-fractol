# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:48:08 by bda-silv          #+#    #+#              #
#*   Updated: 2022/12/10 21:46:30 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. SPECS .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

NAME	=	libmlx.a

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. SETUP .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

SRC		+=	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m
SRC		+=	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_png.c mlx_mouse.m

OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)

CFLAGS	+=	-O2 -Wno-deprecated-declarations
CFLAGS	+=	-DSTRINGPUTX11 #add to  match string put with X11 in size and pos

AR		=	ar -rcs
RL		=	ranlib
RM		=	rm -rf

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. RULES .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

all: $(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RL) $(NAME)
	@echo "$(grn)$(ok)	Compiled		$@$(rst)"

clean :
	$(RM) $(OBJ) *~
	$(RM) mlx_app
	@echo "$(red)$(ko)	Removing		.o files$(rst)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(red)$(ko)	Removing		$(NAME)$(rst)"

re: fclean all

.PHONY : all clean fclean re

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. VERBOSE .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

ifdef VERBOSE
 MAKEFLAGS += --debug
endif

ifndef VERBOSE
 MAKEFLAGS += --silent
.SILENT:
endif

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. VISUALS .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.
ok:=✓
ko:=✗
ck:=・
s:=\033[0
red:=$s31m
grn:=$s32m
yel:=$s33m
blu:=$s34m
pnk:=$s35m
cya:=$s36m
wht:=$s37m
rst:=$s00m
ora:=$s38;2;255;153;0m
#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.
