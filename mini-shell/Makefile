NAME = minishell

CC = cc
# Include debug symbols and disable optimizations for easier debugging
CFLAGS = -g -O0 -Wall -Werror -Wextra -I includes
RL_FLAGS = -lreadline -lhistory

LIBFT_DIR = libraries/libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRC_DIR = src
PRS_DIR = $(SRC_DIR)/parsing
EXEC_DIR = $(SRC_DIR)/execution
INCL_DIR = includes

SRC =	$(PRS_DIR)/0.1.main.c \
		$(PRS_DIR)/0.2.minishell_initialization.c \
		$(PRS_DIR)/0.3.signal_handling.c \
		$(PRS_DIR)/0.4.minishell_termination.c \
		$(PRS_DIR)/0.5.shell_loop.c \
		$(PRS_DIR)/1.1.parsing.c \
		$(PRS_DIR)/1.2.syntax_check.c \
		$(PRS_DIR)/1.3.syntax_utils.c \
		$(PRS_DIR)/1.4.prepare_parsing.c \
		$(PRS_DIR)/2.1.parse_cmd_line.c \
		$(PRS_DIR)/2.2.prepare_cmd_lst.c \
		$(PRS_DIR)/2.3.prepare_args_arr.c \
		$(PRS_DIR)/2.4.prepare_redirs.c \
		$(PRS_DIR)/2.5.prepare_hdoc_lst.c \
		$(PRS_DIR)/3.1.tokenize.c \
		$(PRS_DIR)/3.2.parse_quote.c \
		$(PRS_DIR)/3.3.parse_cmd.c \
		$(PRS_DIR)/3.4.parse_redir.c \
		$(PRS_DIR)/3.5.parse_hdoc.c \
		$(PRS_DIR)/4.1.handle_quotes.c \
		$(PRS_DIR)/4.2.check_builtin_cmds.c \
		$(PRS_DIR)/4.3.handle_redirs.c \
		$(EXEC_DIR)/5.1.1.exec_cmds.c \
		$(EXEC_DIR)/5.1.2.exec_cmds_utils.c \
		$(EXEC_DIR)/5.2.exec_builtin.c \
		$(EXEC_DIR)/5.3.1.exec_sys_cmd.c \
		$(EXEC_DIR)/5.3.2.exec_sys_cmd_utils.c \
		$(EXEC_DIR)/5.4.path_setup.c \
		$(EXEC_DIR)/5.5.1.redirs_setup.c \
		$(EXEC_DIR)/5.5.2.redirs_setup_utils.c \
		$(EXEC_DIR)/5.6.exec_multi_sys_cmd.c \
		$(EXEC_DIR)/6.1.1.cd.c \
		$(EXEC_DIR)/6.1.2.cd_utils.c \
		$(EXEC_DIR)/6.2.echo.c \
		$(EXEC_DIR)/6.3.env.c \
		$(EXEC_DIR)/6.4.exit.c \
		$(EXEC_DIR)/6.5.1.export.c \
		$(EXEC_DIR)/6.5.2.export_utils.c \
		$(EXEC_DIR)/6.6.pwd.c \
		$(EXEC_DIR)/6.7.unset.c \
		$(EXEC_DIR)/7.1.expand.c \
		$(EXEC_DIR)/7.2.expand_utils.c \
		$(EXEC_DIR)/7.3.expand_utils_2.c \
		$(EXEC_DIR)/7.4.expand_utils_3.c \
		$(EXEC_DIR)/8.1.env_init.c \
		$(EXEC_DIR)/9.1.1.heredoc_handle.c \
		$(EXEC_DIR)/9.1.2.heredoc_handle_utils.c \
		$(EXEC_DIR)/10.1.1.cleanup_and_exit.c \
		$(EXEC_DIR)/10.1.2.cleanup_after_cmd_exec.c \
		$(EXEC_DIR)/10.1.3.cleanup_hdocs.c \
		$(EXEC_DIR)/11.1.1.pipes_handle.c \
		$(EXEC_DIR)/11.1.2.pipes_handle_utils.c \
		$(EXEC_DIR)/12.1.shell_lvl.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I $(INCL_DIT) -I $(LIBF_DIR)

all: $(NAME)
	@printf "\033[0m"
	@echo "\n\033[1;92m╔══════════════════════════════════════════╗"
	@echo "║      Minishell ready for duty! 🫡         ║"
	@echo "╚══════════════════════════════════════════╝\033[0m\n"

$(LIBFT_A):
	@printf "\033[1;30m"
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@printf "\033[0m"

$(NAME): $(OBJ) $(LIBFT_A)
	@printf "\033[1;30m"
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT_A) $(RL_FLAGS)

valgrind: $(NAME)
	@printf "\033[1;30m"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline_suppress.supp --child-silent-after-fork=yes ./$(NAME)
	@printf "\033[0m"

valchild: $(NAME)
	@printf "\033[1;30m"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes --suppressions=readline_suppress.supp ./$(NAME)
	@printf "\033[0m"

clean:
	@printf "\033[1;30m"
	rm -rf $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@printf "\033[0m"
	@echo "\n\033[1;92m╔══════════════════════════════════════════╗"
	@echo "║      Cleaned object files  🧹            ║"
	@echo "╚══════════════════════════════════════════╝\033[0m\n"

fclean: clean
	@printf "\033[1;30m"
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@printf "\033[0m"
	@printf "\033[0m"
	@echo "\n\033[1;92m╔══════════════════════════════════════════╗"
	@echo "║      Fully cleaned  🗑️                    ║"
	@echo "╚══════════════════════════════════════════╝\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
