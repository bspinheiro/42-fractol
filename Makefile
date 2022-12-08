# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:48:08 by bda-silv          #+#    #+#              #
#*   Updated: 2022/11/21 19:26:08 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #
#
#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. SPECS .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

PROJ				=	push_swap

SRCS_DIR			=	./src/
OBJS_DIR			=	./obj/
INCS_DIR			=	./inc/
LIBS_DIR			=	./lib/

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. SETUP .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

LIBS_NAME			=	$(shell cd $(LIBS_DIR); ls -d */)
LIBS_PATH			=	$(addprefix $(LIBS_DIR), $(LIBS_NAME))
SRCS_NAME			=	$(shell ls $(SRCS_DIR) | grep -E ".+\.c")
SRCS				=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS				=	$(addprefix $(OBJS_DIR), $(SRCS_NAME:.c=.o))
LIBS				=	$(addsuffix $(LIBS_NAME:/=).a, $(LIBS_PATH))
SRC					=	$(SRCS_NAME:.c=)
NAME				=	$(SRC)

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g
CPPFLAGS			=	-g

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
ifndef FLDR
 FLDR = $(shell echo $(PWD) | rev | cut -d'/' -f1 | rev)
endif

#.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*. RULES .*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

all : $(OBJS_DIR) $(LIBS) $(NAME)

$(OBJS_DIR) :
	$(MD) $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@echo "$(ora)$(ck)	Creating		$@$(rst)"
	$(CC) $(CFLAGS) -I$(INCS_DIR) -o $@ -c $<

$(LIBS) :
	$(MAKE) -C $(LIBS_PATH)

$(NAME) : $(OBJS) $(LIBS)
	-$(CC) $(CFLAGS) $(LIBS) -o $@ $(addprefix $(OBJS_DIR), $@.o)
	@echo "$(grn)$(ok)	Compiled		$@$(rst)"

clean :
	$(MAKE) $@ -C $(LIBS_PATH)
	$(RM) $(OBJS_DIR)
	@echo "$(red)$(ko)	Removing		$(OBJS_DIR)$(rst)"

fclean :
	$(MAKE) $@ -C $(LIBS_PATH)
	$(RM) $(SRC) $(OBJS_DIR)
	@echo "$(red)$(ko)	Removing		$(SRC)$(rst)"

re : fclean all

norm :
	@echo "$(pnk)\c"; \
	norminette | grep "Error" || echo "$(grn)$(ok)	Norminette		OK!"

run : all
	@echo "$(grn)$(ok)	Running			$(RUN_ARGS)$(rst)\n"
	./$(RUN_ARGS); echo "$(rst)"

debug :
	@echo "$(pnk)"
	lldb $(RUN_ARGS)

leaks :
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes \
	$(addprefix ./, $(RUN_ARGS))

gig :
	if [ -f '.gitignore' ]; \
	then \
		echo "$(grn)$(ok)	.gitignore		OK!$(ora)$(rst)" ; \
	else \
		echo "$(ora)$(ck)	Creating		.gitignore$(ora)" ; \
		echo ".*" >> .gitignore ; \
		echo "*.o" >> .gitignore ; \
		echo "*.a" >> .gitignore ; \
		echo "*.out" >> .gitignore ; \
		echo "*.dSYM" >> .gitignore ; \
		echo ".DS_Store" >> .gitignore ; \
		echo "checker_Mac" >> .gitignore ; \
		echo "push_swap" >> .gitignore ; \
		cat -n .gitignore ; \
	fi

boilerplate: gig
	echo "$(ora)$(ck)	Creating		directory$(ora)" ; \
	$(MD) inc src lib
	echo "$(ora)$(ck)	Creating		libraries$(ora)" ; \
	cp -Rf ../.boilerplate/libs/ . 2>/dev/null
	touch ./src/$(FLDR).c && touch ./inc/$(FLDR).h
	echo "$(ora)$(ck)	Creating		gitmirror$(rst)" ; \
	git remote set-url --add origin git@github.com:bspinheiro/42-$(FLDR).git
	gh repo create 42-$(FLDR) --private --source=. --remote=github
	git add .
	git commit -m "$(FLDR): Boilerplate"
	git push origin master
	echo "$(grn)$(ok)	Boilerplate		DONE!$(rst)" ; \

ready:
	-mv main.c .main.c 2>/dev/null \
	&& echo "$(ora)$(ck)	Creating		.main.c" \
	|| echo "$(red)$(ko)	Skipping		.main.c"
	$(RM) *.o *.a *.out *.dSYM .DS_Store
	@echo "$(red)$(ko)	Removing		dSYMs$(rst)"
	-for f in *; do if [ $$f != 'Makefile' ]; then rm $$f 2>/dev/null; fi; done
	@echo "$(red)$(ko)	Removing		files$(rst)"
	$(MAKE) fclean gig norm

rainbow :
	@echo "$(red)R$(grn)A$(yel)I$(blu)N$(pnk)B$(cya)O$(wht)W$(rst)"

.PHONY : all clean fclean re norm gig run debug leaks ready rainbow boilerplate

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
