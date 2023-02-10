# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:24:14 by bda-silv          #+#    #+#              #
#*   Updated: 2023/02/10 19:43:19 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

PROJ      := fractol
NAMES     := ${PROJ}

# **************************************************************************** #
#                          Config and Folders
# **************************************************************************** #

SRC_ROOT  := src/
INC_ROOT  := inc/
LIB_ROOT  := lib/
OBJ_ROOT  := obj/
BIN_ROOT  := ./

VERBOSE   := 1

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.

# **************************************************************************** #
#                          Compiler and Flags
# **************************************************************************** #

CC        := cc
CLIB      := ar -rc

CFLAGS    := -Wall -Wextra -Werror
DFLAGS    := -g
OFLAGS    := -O3
FSANITIZE := -fsanitize=address

# **************************************************************************** #
#                           Content Folders
# **************************************************************************** #

SRC_DIRS_LIST := ${SRC_ROOT}
SRC_DIRS_LIST := $(foreach dl,${SRC_DIRS_LIST},$(subst :,:${SRC_ROOT},${dl}))

SRC_DIRS = $(subst :,${SPACE},${SRC_DIRS_LIST})
OBJ_DIRS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRC_DIRS})

INC_DIRS = ${INC_ROOT}

# **************************************************************************** #
#                                Files
# **************************************************************************** #

SRCS_LIST = $(foreach dl,${SRC_DIRS_LIST},$(subst ${SPACE},:,$(strip $(foreach\
	dir,$(subst :,${SPACE},${dl}),$(wildcard ${dir}*.c)))))
OBJS_LIST = $(subst ${SRC_ROOT},${OBJ_ROOT},$(subst .c,.o,${SRCS_LIST}))

SRCS = $(foreach dir,${SRC_DIRS},$(wildcard ${dir}*.c))
OBJS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRCS:.c=.o})

INCS := ${addprefix -I,${INC_DIRS}}
INCS += -I${LIB_ROOT}libft

# **************************************************************************** #
#                               VPATHS
# **************************************************************************** #

vpath %.o ${OBJ_ROOT}
vpath %.h ${INC_ROOT}
vpath %.c ${SRC_DIRS}

# **************************************************************************** #
#                             OS Check
# **************************************************************************** #

detected_OS := $(shell uname)

ifeq ($(detected_OS), Linux)
	MLX = mlx_linux
	MLX_FLAGS = -lbsd -L${LIB_ROOT}${MLX} -lmlx -lXext -lX11 -lm
	CFLAGS += -DOS=1
else ifeq ($(detected_OS), Darwin)
	MLX = mlx_darwin
	MLX_FLAGS = -I${LIB_ROOT}${MLX} -L${LIB_ROOT}${MLX} -lm -lmlx -framework \
				OpenGL -framework AppKit
	CFLAGS += -DOS=2
endif

# **************************************************************************** #
#                          Command Line Parser
# **************************************************************************** #

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

# **************************************************************************** #
#                         Mandatory Targets
# **************************************************************************** #

.PHONY: all
all: ${NAMES}

${PROJ}: ${OBJS}
	${AT} ${MAKE} -C ${LIB_ROOT}libft ${BLOCK}
	${AT} ${MAKE} -C ${LIB_ROOT}${MLX} ${BLOCK}
	${AT} ${CC} ${CFLAGS} ${OFLAGS} ${INCS}  ${OBJS} ${MLX_FLAGS} \
		${LIB_ROOT}libft/libft.a -o $@ ${BLOCK}
	${AT}echo "${_OK}$(grn)${@F}$(rst)" ${BLOCK}

# **************************************************************************** #
#                         Clean Targets
# **************************************************************************** #
.PHONY: clean
clean:
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}find ${OBJ_ROOT} -type f -delete ${BLOCK}
	${AT} ${MAKE} fclean -C ${LIB_ROOT}libft ${BLOCK}
	${AT} ${MAKE} clean -C ${LIB_ROOT}${MLX} ${BLOCK}
	${AT} rm -f libmlx.dylib ${BLOCK}
	${AT}echo "$(_KO)$(red)${OBJ_ROOT}$(rst)" ${BLOCK}

.PHONY: fclean
fclean: clean
	${AT}rm -f ${NAMES} ${BLOCK}
	${AT}echo "$(_KO)$(red)${NAMES}$(rst)" ${BLOCK}

.PHONY: re
re: fclean all

# **************************************************************************** #
#         Debug,  Run, Leaks, Ready,  gitIgnore, Boilerplate and Help
# **************************************************************************** #

debug: CFLAGS += ${DFLAGS} ${FSANITIZE}
debug:
	@echo "$(pnk)"
	lldb $(RUN_ARGS)


run : all
	@echo "$(grn)$(ok)	Running			$(RUN_ARGS)$(rst)\n"
	./$(RUN_ARGS); echo "$(rst)"

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


# **************************************************************************** #
#                           Norminette
# **************************************************************************** #

.PHONY: norm
norm:
	${AT} echo "$(pnk)\c"; \
	norminette ${SRCS} ${INC_ROOT} | grep "Error" || \
	echo "$(grn)$(ok)	Norminette		OK!" ${BLOCK}

# **************************************************************************** #
#                        Target Templates
# **************************************************************************** #

define make_obj
${1} : ${2}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT} $${CC} $${OFLAGS} $${CFLAGS} $${INCS} -I$${LIB_ROOT}$${MLX} -c $$< -o $$@ $${BLOCK}
endef

# **************************************************************************** #
#                        Target Generator
# **************************************************************************** #

$(foreach src,${SRCS},$(eval\
$(call make_obj,$(subst ${SRC_ROOT},${OBJ_ROOT},${src:.c=.o}),${src})))

# **************************************************************************** #
#                          Verbose Check
# **************************************************************************** #

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLOCK := >/dev/null
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

# **************************************************************************** #
#                           Visuals and Messages
# **************************************************************************** #

ok:=✓
ko:=✗
ck:=・
ls:=*
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

_OK := $(grn)$(ok)	Compiled		$(rst)
_CK := $(ora)$(ck)	Creating		$(rst)
_KO := $(red)$(ko)	Removing		$(rst)

# **************************************************************************** #
