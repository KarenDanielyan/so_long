# Program and it's dependencies

NAME	=	so_long

INCLUDE	=	./include

BUILD	=	./build

DIR		=	./src

SUBDIRS	=	main parse

DEP		=	$(wildcard $(INCLUDE)/*.h) Makefile

SRC		=	$(foreach dir, $(SUBDIRS), $(wildcard $(DIR)/$(dir)/*.c))

OBJS =		$(foreach dir, $(SUBDIRS), $(patsubst $(DIR)/$(dir)/%.c, $(BUILD)/%.o, $(wildcard $(DIR)/$(dir)/*.c)))

# Compilation options

CC 		= 	cc

RM		=	rm -rf

CFLAGS	=	-g -fsanitize=address -Wall -Wextra -Werror

LFLAGS	=	-L./libft -lft -L./printf -lftprintf

IFLAGS	=	-I./include -I./libft -I./printf/include

MGOALS	=	$(filter-out bonus, $(MAKECMDGOALS))

# Colors

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m

# Recipies

all:		wait_msg libft printf $(NAME)

$(BUILD):
				@mkdir -p $(BUILD)

$(BUILD)/%.o:	$(DIR)/main/%.c $(DEP)
					@echo "${YELLOW}Compiling $<.${RESET}"
					@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BUILD)/%.o:	$(DIR)/parse/%.c $(DEP)
					@echo "${YELLOW}Compiling $<.${RESET}"
					@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME):	$(BUILD) $(OBJS)
				@echo "${GREEN}Building so_long.${RESET}"
				@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME) $(LFLAGS)
				@echo "${GREEN}Build Successfull.${RESET}"

libft:
				@$(MAKE) $(MGOALS) -C libft

printf:
				@$(MAKE) $(MGOALS) -C printf

wait_msg:
				@echo "${BLUE}Please wait for so_long to compile.${RESET}"

clean:		printf libft
				@echo "${YELLOW}Cleaning Build...${RESET}"
				@$(RM) $(BUILD)
				@echo "${GREEN}Done.${RESET}"

fclean:		printf libft
				@echo "${YELLOW}Cleaning Everyting...${RESET}"
				@$(RM) $(BUILD)
				@$(RM) $(NAME)
				@echo "${GREEN}Done.${RESET}"

re:			fclean all

.PHONY:		all clean fclean re libft printf
