NAME = pipex

CC = gcc

CFLAGS =  -Wall -Wextra -Werror

RM = rm -rf

SRCS = 	src/pipex.c src/utils_1.c src/utils_2.c\
		includes/libft/libft.a\

SRCS_BONUS = 	src_bonus/pipex_bonus.c\
				src_bonus/utils_bonus_1.c\
				src_bonus/utils_bonus_1.c\
				includes/libft/libft.a\

all : $(NAME)

$(NAME) :
	@make -s all -C includes/libft
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	@$(RM)
	@make -s clean -C includes/libft

fclean : clean
	@$(RM) $(NAME)
	@make -s fclean -C includes/libft

re : fclean all

bonus : clean
	@make -s all -C includes/libft
	@gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)