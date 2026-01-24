/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:29:52 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/08 16:33:57 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* LIBRARIES */
# include "../libraries/libft/libft.h"

/* HEADERS */
// for readline and all rl_* functions:
# include <readline/readline.h>
# include <readline/history.h>

// for printf, readline
# include <stdio.h>

// for malloc, free, getenv
# include <stdlib.h>

// for access, getcwd, chdir, unlink, execve,
// dup, dup2, pipe, isatty, ttyname, ttyslot
# include <unistd.h>

// for write, open, read, close, unlink
# include <fcntl.h>

// for fork, stat, lstat, fstat, opendir
# include <sys/types.h>

// for wait, waitpid
# include <sys/wait.h>

// for signal, sigaction, etc.
# include <signal.h>

// for stat, lstat, fstat
# include <sys/stat.h>

// for opendir, readdir, closedir
# include <dirent.h>

// for strerror
# include <string.h>

// for boolean expressions
# include <stdbool.h>

// for max limits macroses
# include <limits.h>

/* ======== SIGNAL GLOBAL ========= */
extern volatile sig_atomic_t	g_signal_num;

/* MACROS */
# define SUCCESS 0
# define FAILURE 1

/* STRUCTURES */

/* struct for expansion */
typedef struct s_exp
{
	char	*temp;
	char	*temp2;
	int		last_opt;
}	t_exp;

/* hdocs struct */
typedef struct s_hdoc
{
	int				index;
	char			*hdoc_delim;
	int				hdoc_fd[2];
	struct s_hdoc	*next;
}	t_hdoc;

/* redirections struct */
typedef struct s_redirs
{
	char			**list;
	int				in_fd;
	int				out_fd;
	int				hdoc_count;
	t_hdoc			*hdocs;
}	t_redirs;

/* command data structure */
typedef struct s_cmd
{
	int				index;
	char			**args;
	int				args_count;
	int				redirs_count;
	bool			builtin;
	t_redirs		*redirs;
	bool			skip_in_pipe;
	bool			skip_out_pipe;
	bool			has_redir_err;
	struct s_cmd	*next;
}	t_cmd;

/* main data storage */
typedef struct s_shell
{
	char			*prompt;
	int				pipe_count;
	int				**pipes;
	char			**env;
	t_cmd			*cmd;
	int				exit_status;
	pid_t			shell_pid;
	pid_t			last_pid;
	int				orig_stdin;
	int				orig_stdout;
	t_exp			*expansion;
}	t_shell;

/* FUNCTIONS */
/* PARSING FOLDER */
// 0.2.minishell_initialization.c
int		init_minishell(t_shell *minishell);

// 0.3.signal_handling.c
void	ft_signal_handler(int signum);
void	ft_setup_signals(void);
void	ft_signal_handler_for_parent(int signum);
void	ft_handle_child_status(t_shell *shell, int status);
void	ft_reset_signals(void);

// 0.4.minishell_termination.c
void	end_minishell(t_shell *minishell);

// 0.5.shell_loop.c
void	shell_loop(t_shell *minishell);

// 1.1.parsing.c
int		parse(char *pipeline, t_shell *minishell);
char	*blackout_quoted_content(char *str);
t_exp	*prepare_expasion(void);

// 1.2.syntax_check.c
int		is_valid_syntax(char *copy, int pipe_count);
int		are_valid_pipes(char *copy);
int		are_valid_redirs(char *copy);
int		are_closed_quotes(char *copy);

// 1.3.syntax_utils.c
int		is_whitespace(char c);
int		is_operator(char c);
int		is_redir(char c);
int		is_quote(char c);
int		is_other(char c);

// 1.4.prepare_parsing.c
int		get_pipe_count(char *copy);

// 2.1.parse_cmd_line.c
int		parse_cmd_lines(char *copy, char *pline,
			int cmd_count, t_shell *minishell);
char	**split_pipeline(char *copy, char *pipeline, t_shell *minishell);
int		process_cmd(t_shell *minishell, char *cmd_str);

// 2.2.prepare_cmd_lst.c
void	create_cmd_list(char **arr, int cmd_count, t_shell *minishell);
void	add_node(t_cmd **list, t_cmd *new);
t_cmd	*create_node(char *cmd_line);
void	set_index(t_cmd *stack, int cmd_count);

// 2.3.prepare_args_arr.c
int		prepare_args_arr(char *copy, t_cmd *cmd);
int		get_arg_count(char *copy, int redirs_count);
int		get_redir_count(char *copy);

// 2.4.prepare_redirs.c
int		prepare_redirs(char *copy, t_cmd *cmd);
int		get_hdoc_count(char *copy);

// 2.5.prepare_hdoc_lst.c
void	prepare_hdoc_list(t_redirs *redirects);
t_hdoc	*create_hdoc_node(int index);
void	add_hdoc_node(t_hdoc **list, t_hdoc *new);

// 3.1.tokenize.c
int		tokenize(char *cmd_str, t_cmd *cmd);

// 3.2.parse_quote.c
int		parse_quote(char *cmd_str, t_cmd *cmd);
int		get_arg_len_in_quotes(char *str);

// 3.3.parse_cmd.c
int		parse_cmd(char *str, t_cmd *cmd);
int		get_arg_len(char *str);
void	fill_args_arr(char *arg_str, t_cmd *cmd);

// 3.4.parse_redir.c
int		parse_redir(char *cmd_str, t_cmd *cmd);
int		get_redir_len(char *str);
void	fill_redirs_arr(char *redirect, t_cmd *cmd);

// 3.5.parse_hdoc.c
void	parse_hdoc(t_redirs *redirs);
char	*get_delimiter(char *cmd_str);

// 4.1.handle_quotes.c
int		cleanup_quotes(char **arr);
char	*get_clean_str(char *orig_str);
int		get_strlen_clean(char *orig_str);

//4.2.check_builtin_cmds.c
int		is_builtin_cmd(t_cmd *cmd);

// 4.3.handle_redirs.c
int		handle_redirs(t_shell *shell, t_cmd *cmd);
int		process_redirs(t_shell *shell, t_cmd *cmd,
			char *rdr_str, char *filename);
char	*get_filename(char *redir_str);
int		handle_infile(t_shell *shell, char *filename, t_cmd *cmd, int op_count);
int		handle_out_redir(t_shell *shell, char *filename,
			t_cmd *cmd, int op_count);

/* ==================== */

/* EXECUTION FOLDER */

// 5.1.1.exec_cmds.c
void	ft_exec_cmds(t_shell *shell);

// 5.1.2.exec_cmds_utils.c
void	ft_wait_for_childs(t_shell *shell,
			int *status, int expected_childs);
void	ft_handle_cat(t_shell *shell);

// 5.2.1.exec_builtin.c
int		ft_exec_builtin(t_shell *shell, t_cmd *cmd, char *cmd_name);
int		ft_error_and_exit(t_shell *shell, char *arg);

// 5.2.2.redirs_setup_utils.c
t_hdoc	*ft_get_last_hdoc(t_hdoc *head);

// 5.3.1.exec_sys_cmd.c
int		ft_exec_sys_solo_cmd(t_shell *shell, t_cmd *cmd);
int		ft_err(t_shell *shell, char *cmd);
void	ft_err_dir(t_shell *shell, char *cmd, char *err, int code);
void	ft_exec_err(char *cmd, char *path);

// 5.3.2.exec_sys_cmd_utils.c
bool	ft_is_cmd_is_dir(t_shell *shell, char *arg);
void	ft_err_msg(t_shell *shell, char *cmd, char *msg, int code);

// 5.4.path_setup.c
char	*ft_getpath(char *cmd, char **env);
char	*ft_parse_env(char *name, char **env);
void	ft_free_arr_str(char **arr);

// 5.5.1.redirs_setup.c
void	ft_setup_cmd_redirs(t_shell *shell, t_cmd *cmd);
void	ft_restore_orig_fds(t_shell *shell);

// 5.5.2.redirs_setup_utils.c
t_hdoc	*ft_get_last_hdoc(t_hdoc *head);

// 5.6.exec_multi_sys_cmd.c
int		ft_exec_multi_sys_cmd(t_shell *shell, t_cmd *cmd);
int		ft_isdir(char *path);

// 6.1.1.cd.c
int		ft_cd(t_shell *shell, t_cmd *cmd);

// 6.1.2.cd_utils.c
int		ft_set_cd_vars(t_shell *shell, char *key, char *value);

// 6.2.echo.c
int		ft_echo(t_cmd *cmd);

// 6.3.env.c
int		ft_env(t_shell *shell, t_cmd *cmd);
char	*ft_getenv(char **env, char *var_name);

// 6.4.exit.c
int		ft_exit(t_shell *shell, t_cmd *cmd);

// 6.5.1.export.c
int		ft_export(t_shell *shell, t_cmd *cmd);
bool	ft_is_valid_var_name(char *var);

// 6.5.2.export_utils.c
char	**ft_sort_env(char **env);
char	*ft_normalize_env_var(char *var);
void	ft_print_var_with_quotes(char *var);

// 6.6.pwd.c
int		ft_pwd(t_shell *shell, t_cmd *cmd);

// 6.7.unset.c
int		ft_unset(t_shell *shell, t_cmd *cmd);

// 7.1.expand.c
int		ft_expand(t_shell *shell);
int		ft_expand_redirs_list(t_shell *shell, t_cmd *cmd);
int		ft_expand_args_list(t_shell *shell, t_cmd *cmd);
char	*ft_expand_str(t_shell *shell, char *str);
char	*ft_expand_dollar_start(t_shell *shell, char *str);

// 7.2.expand_utils.c
char	*ft_expand_env_var(t_shell *shell, char *str, int len);
char	*get_expand_str(t_shell *shell, char *str, char *unexp_str, int flag);
char	*get_unexpand_str(char *str, char *exp_str);
char	*ft_expand_dquotes_str(t_shell *shell, char *str);
char	*ft_patch_with_dquotes(char *str);

// 7.3.expand_utils_2.c
size_t	ft_get_var_name_len(char *arg);
bool	ft_is_valid_var_char(int c);
int		get_var_len_expanded(char *str);
void	handle_dollar_sign(t_shell *shell, t_exp *curr, char *str);

// 7.4.expand_utils_3.c
char	*ft_expand_simple_str(t_shell *shell, char *str);
char	*return_and_free_temps(char *str);

// 8.1.env_init.c
char	**ft_env_dup(char **env);

// 9.1.1.heredoc_handle.c
void	ft_process_all_heredocs(t_shell *shell);
int		ft_handle_heredoc(t_shell *shell, t_hdoc *curr_hdoc);

// 9.1.2.heredoc_handle_utils.c
char	*ft_expand_heredoc_str(t_shell *shell, char *str);
char	*ft_get_delim(char *old_delim);
// 10.1.1.cleanup_and_exit.c
void	ft_cleanup_and_exit(t_shell *shell, int exit_code);
void	ft_cleanup_shell(t_shell *shell);
void	ft_cleanup_cmd_list(t_cmd **cmd_list);
void	ft_cleanup_cmd(t_cmd *cmd);
void	ft_cleanup_reset_redirs(t_redirs *redirs);

// 10.1.2.cleanup_after_cmd_exec.c
void	ft_cleanup_after_cmd_exec(t_shell *minishell);
void	ft_restore_std_fds(t_shell *shell);
void	ft_child_cleanup_fds_only(t_shell *shell);

// 10.1.3.cleanup_hdocs.
void	ft_cleanup_hdocs_list(t_hdoc **hdocs_list);
void	ft_cleanup_hdoc(t_hdoc *hdoc);

// 11.1.pipes_handle.c
int		ft_pipes_init(t_shell *shell);
void	ft_setup_pipes_for_cmd(t_shell *shell, t_cmd *cmd, int cmd_index);
void	ft_close_all_pipes(t_shell *shell);
void	ft_cleanup_pipes_array(t_shell *shell);
void	ft_close_unused_child_pipes(t_shell *shell, int child_index);

// 11.1.2.pipes_handle_utils.c
void	ft_adjust_pipes_for_skipped_cmds(t_shell *shell);

// 12.1.shell_lvl.c
void	ft_setup_shlvl(t_shell *shell);
char	**ft_add_str_arr(char **arr, char *str);

#endif
