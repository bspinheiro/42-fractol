# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:48:08 by bda-silv          #+#    #+#              #
#*   Updated: 2023/02/10 15:07:31 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #
#
#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. SPECS .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

PROJ				=	libft
EXEC				=	main

SRCS_DIR			=	./src/
OBJS_DIR			=	./obj/
INCS_DIR			=	./inc/
LIBS_DIR			=	..

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. SETUP .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

SRCS_NAME			=	$(shell ls $(SRCS_DIR) | grep -E ".+\.c")
SRCS				=	$(addprefix $(SRCDIR), $(SRCS_NAME))
OBJS				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
NAME				=	$(addsuffix .a, $(PROJ))


CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
CPPFLAGS			=	-g
CFILES				=	$(shell ls -a . | grep -E ".+\.c")
CEXEC				=	$(addsuffix .out, $(EXEC))

MD					=	mkdir -p
AR					=	ar rcs
RL					=	ranlib
RM					=	rm -rf

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. ROUTE .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif
ifeq (leaks,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif
ifeq (debug,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. RULES .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR) :
	$(MD) $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
#	@echo "$(ora)$(ck)	Creating		$@$(rst)"
	$(CC) $(CFLAGS) -I$(INCS_DIR) -o $@ -c $<

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RL) $(NAME)
	@echo "$(grn)$(ok)	Compiled		$@$(rst)"

clean :
	$(RM) $(OBJS_DIR)
	@echo "$(red)$(ko)	Removing		$(OBJS_DIR)$(rst)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(red)$(ko)	Removing		$(NAME)$(rst)"

re : fclean all

norm :
	@echo "$(pnk)"
	norminette | grep "Error" || echo "$(grn)$(ok)	Norminette		OK!"

comp : all
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CFILES) $(NAME) -o $(CEXEC)
	@echo "$(grn)$(ok)	Compiled		$(CEXEC)$(rst)"

run : comp
	@echo "$(grn)$(ok)	Running			$(CEXEC)$(rst)"
	./$(CEXEC) $(RUN_ARGS); echo "$(cya)\n"

debug : leaks
	@echo "$(pnk)"
	lldb $(CEXEC) $(RUN_ARGS)

leaks :
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes \
	$(addprefix ./, $(CEXEC)) $(RUN_ARGS)

gig :
	if [ -f '.gitignore' ]; \
	then \
		echo "$(grn)$(ok)	.gitignore		OK!$(ora)" ; \
	else \
		echo "$(ora)$(ck)	Creating		.gitignore$(ora)" ; \
		echo ".*" >> .gitignore ; \
		echo "*.o" >> .gitignore ; \
		echo "*.a" >> .gitignore ; \
		echo "*.out" >> .gitignore ; \
		echo "*.dSYM" >> .gitignore ; \
		echo ".DS_Store" >> .gitignore ; \
		cat -n .gitignore ; \
	fi

ready : norm gig
	test -f main.c && mv main.c .main.c \
	|| echo "$(ora)$(ck)	Skipping		main.c"
	$(RM) *.o *.a *.out *.dSYM .DS_Store
	$(MAKE) fclean
	@echo "$(grn)$(ok)	Delivery		DONE!"

rainbow :
	@echo "$(red)R$(grn)A$(yel)I$(blu)N$(pnk)B$(cya)O$(wht)W$(rst)"

.PHONY : all clean fclean re norm gig comp ready debug leaks rainbow run

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
