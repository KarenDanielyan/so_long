# Program and it's dependencies

PLATFORM	=	$(shell uname -s)

NAME		=	so_long

INCLUDE		=	./include

BUILD		=	./build

DIR			=	./src

SUBDIRS		=	main parse map game

DEP			=	$(wildcard $(INCLUDE)/*.h) Makefile

SRC			=	$(foreach dir, $(SUBDIRS), $(wildcard $(DIR)/$(dir)/*.c))

OBJS		=	$(foreach dir, $(SUBDIRS), $(patsubst $(DIR)/$(dir)/%.c, $(BUILD)/%.o, $(wildcard $(DIR)/$(dir)/*.c)))

# Compilation options

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-g -Wall -Wextra -Werror #-fsanitize=address

ifeq ($(PLATFORM),Linux)
	INVOKE	=	libft printf mlx_linux
	LFLAGS	=	-L./libft -lft -L./printf -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
	IFLAGS	=	-I/usr/include -Imlx_linux -I./include -I./libft -I./printf/include
endif
ifeq ($(PLATFORM),Darwin)
	INVOKE	=	libft printf mlx_mac
	LFLAGS	=	-L./libft -lft -L./printf -lftprintf -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
	IFLAGS	=	-I./include -I./libft -I./printf/include -Imlx_mac
endif


MGOALS		=	$(filter-out bonus, $(MAKECMDGOALS))

# Colors

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m

# Recipies
all:		wait_msg $(INVOKE) $(NAME)

$(BUILD):
				@mkdir -p $(BUILD)

$(BUILD)/%.o:	$(DIR)/main/%.c $(DEP)
					@echo "${YELLOW}Compiling $<.${RESET}"
					@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BUILD)/%.o:	$(DIR)/parse/%.c $(DEP)
					@echo "${YELLOW}Compiling $<.${RESET}"
					@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BUILD)/%.o:	$(DIR)/map/%.c $(DEP)
					@echo "${YELLOW}Compiling $<.${RESET}"
					@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BUILD)/%.o:	$(DIR)/game/%.c $(DEP)
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

mlx_linux:
				@$(MAKE) $(MGOALS) -C mlx_linux

mlx_mac:
				@$(MAKE) $(MGOALS) -C mlx_mac

wait_msg:
				@echo "${BLUE}Please wait for so_long to compile.${RESET}"

clean:		$(INVOKE)
				@echo "${YELLOW}Cleaning Build...${RESET}"
				@$(RM) $(BUILD)
				@echo "${GREEN}Done.${RESET}"

fclean:		printf libft
				@echo "${YELLOW}Cleaning Everyting...${RESET}"
				@$(RM) $(BUILD)
				@$(RM) $(NAME)
				@echo "${GREEN}Done.${RESET}"

re:			fclean all

.PHONY:		mlx_linux mlx_mac wait_msg printf libft fclean clean all re
