# Program and it's dependencies

NAME	=	libparse.a

INCLUDE	=	./include

BIN		=	../bin

BUILD	=	./build

DIR		=	./src

FILES	=	parse.c extension_check.c invalid_char_check.c one_start_exit_check.c \
			wall_check.c rectangle_check.c valid_path_check.c

DEP		=	$(wildcard $(INCLUDE)/*.h) Makefile

SRC		=	$(patsubst %.c, $(DIR)/%.c, $(FILES))

OBJS	=	$(patsubst $(DIR)/%.c, $(BUILD)/%.o, $(SRC))

# Compilation options

AR		=	ar rcs

CC 		= 	cc

RM		=	rm -rf

CFLAGS	=	-g -fsanitize=address -Wall -Wextra -Werror -Wpedantic

LFLAGS	=	-L../libft -lft -L../printf -lftprintf

IFLAGS	=	-I./include -I../libft -I../printf/include -I../include

# Colors

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m


# Recipies
all:		$(NAME)

$(BUILD):
				@mkdir $(BUILD)

$(BUILD)/%.o:	$(DIR)/%.c $(DEP)
					@echo "${YELLOW}Compiling $<.${RESET}"
					@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME):	$(BUILD) $(OBJS)
				@echo "${GREEN}Archiving parse.${RESET}"
				@$(AR) $@ $(OBJS)
				@echo "${GREEN}Archive Successfull.${RESET}"

clean:
				@echo "${YELLOW}Cleaning Build...${RESET}"
				@$(RM) $(BUILD)
				@echo "${GREEN}Done.${RESET}"

fclean:
				@echo "${YELLOW}Cleaning Everyting...${RESET}"
				@$(RM) $(BUILD)
				@$(RM) $(NAME)
				@echo "${GREEN}Done.${RESET}"

re:			fclean all

.PHONY:		all clean fclean re
