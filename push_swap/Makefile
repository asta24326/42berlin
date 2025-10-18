# Standard
NAME					= push_swap

# Directories
LIBFT					= ../libft/libft.a
UTILS_DIR				= utils

# Compiler and Flags
CC						= clang
CFLAGS					= -I. -g -Wall -Werror -Wextra
RM						= rm -f

# Utils Files
UTILS					= $(UTILS_DIR)/create_stack_a.c \
							$(UTILS_DIR)/custom_split.c \
							$(UTILS_DIR)/errors_handle.c \
							$(UTILS_DIR)/get.c \
							$(UTILS_DIR)/init_nodes_a.c \
							$(UTILS_DIR)/init_nodes_b.c \
							$(UTILS_DIR)/push.c \
							$(UTILS_DIR)/rev_rotate.c  \
							$(UTILS_DIR)/rotate_both.c \
							$(UTILS_DIR)/rotate.c \
							$(UTILS_DIR)/sort_stacks.c \
							$(UTILS_DIR)/sort_three.c \
							$(UTILS_DIR)/swap.c \
							$(UTILS_DIR)/utils.c

# Concatenate all source files
SRCS					= $(UTILS) push_swap.c

# Produce objext files and store it to OBJ_DIR
OBJ						= $(patsubst $(UTILS_DIR)/%.c, $(UTILS_DIR)/%.o, $(UTILS)) push_swap.o

# Building rules
start:					all

$(LIBFT):
						@$(MAKE) -s -C ../libft

all:					$(NAME)

$(NAME):				$(OBJ) $(LIBFT)
						@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile objects files from utils
$(UTILS_DIR)/%.o:		$(UTILS_DIR)/%.c
						@$(CC) $(CFLAGS) -c $< -o $@

# Compile push_swap.c
push_swap.o:			push_swap.c
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) $(OBJ)
					@$(MAKE) clean -s -C ../libft

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re:					fclean all

# PHONY targets represents actions not files
.PHONY:				start all clean fclean re

# Syntax 
# @ - silent modifier or quiet flag. Make command itself not to be printed to console before execution
# $(@D) - automatic variable that expands to the directiry part of the target file
# $< automatic variable, it refers to the source file being compiled
# $@ takes name of of source file
# .PHONY - special target of directive, declares the listed targets (start, clean ...) as phony targets
#		means they're not files but actions to be executed regardless of whether a file with the same name exists
# patsubst - "pattern substitution" $(patsubst [template_search], [template_replacement], [name of the searching file])