/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:27:57 by kirill            #+#    #+#             */
/*   Updated: 2022/09/17 18:49:18 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_H
# define MIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_exec			t_exec;
typedef struct s_token			t_token;
typedef struct s_commande_line	t_commande_line;
typedef struct s_env			t_env;
int								g_exit_status;

typedef enum quote
{
	NONE,
	SINGLE,
	DOUBLE,
	BACKSLASH,
	END
}	t_quote;

typedef enum mod
{
	GET,
	DELETE,
	FREE,
	ADD
}	t_mod;

typedef enum token
{
	NON,
	ARG,
	BUILTIN,
	OPEN_FILE,
	HERE_DOC,
	LIMITOR,
	CREAT_FILE,
	WRITE_FILE,
	FILE_IN,
	FILE_OUT,
	FILE_OUT_OVER,
	ENDS
}	t_e_token;

struct		s_env
{
	char	*str;
	int		declare;
	t_env	*next;
};

struct			s_token
{
	char		*str;
	t_e_token	type;
	bool		expanded;
	t_token		*next;
};

struct		s_commande_line
{
	char			*string;
	t_token			*first_token;
	char			**envp;
	char			**argv;
	int				fd_in;
	int				fd_out;
	char			*name_file;
	t_commande_line	*next;
};

int			aleatori_char(void);
char		*creat_aleatori_name(void);
size_t		ft_strlen(const char *s);
char		*ft_strncpy(char *dst, char *src, int n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnew(size_t size);
int			ft_strncmp(char *str, char *to, int n);
int			ft_strcmp(char *str, char *in);
int			ft_is_alpha_num(char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			is_separator(char c);
int			is_redirection(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(const char *s1);
void		*ft_memset(void *b, int c, size_t len);
void		fill_new(char *new, int sign, int nbr, int j);
void		*ft_memalloc(size_t size);
char		*ft_itoa(int nbr);
int			ft_atoi(char *str);
int			len_cmd(t_commande_line *cmd);
int			len_int(int nbr, int *sign);
int			ft_count_words(const char *s, char c);
void		spliting(int words, char const *s, char c, char **tab);
char		**ft_strsplit(char const *s, char c);
int			check_str(char *str);
char		*if_no_envy(char *str, char *s1, int *cur);
char		*if_envy(char *str, char *s1, int *cur);
char		*expanded_str(char *str);
int			write_in_fd(int fd, char *limitor, bool expanded);
int			create_heredoc_fd(t_commande_line **cmdl, t_token **cur);
int			ft_add_env(char *str);
int			ft_get_lenkey(char *env);
int			ft_equal(char *str);
int			ft_special_lenkey(char *str);
int			ft_add_value_to_env(t_env **env_list, char *env, int declare);
int			ft_delete_env(char *str);
void		ft_delete_env_call(t_env **env, char *key);
char		*ft_final_add(char *env);
int			ft_push_front(char *env, t_env **begin_lst, int declare);
int			get_len_env_var(char *str);
int			is_env(char *str, char *env, int len);
char		*alloc_dollar(int *cur);
char		*get_envp(char *str, int *cur);
char		*get_env(int *cur, char *str);
char		*copy_fake_env(char *str);
char		*fake_env(int *j, int len_str);
int			len_fake_env(char *str);
int			ret_error_file_without_file(t_commande_line *cur_b);
int			ret_file_without_obj(t_e_token type);
char		*write_bad_cmd_free_split(char *str, char **split_path);
char		*write_bad_cmd_free(char *str);
int			ft_exec(t_commande_line **cmdl);
void		to_exec(t_commande_line **cmd_line, char *str);
int			ft_sup_int(char *str);
int			ft_non_int(char *str);
int			exit_bltin(char **args, t_commande_line **first, pid_t *pid);
void		free_fd_all_exit_malloc_error(t_commande_line **first);
void		free_str_fd_exit_malloc_error(char **str, t_commande_line **first);
void		free_str_exit_fd_error(char **str);
void		free_str_fd_all_env_pid_exit(t_commande_line **cmd,
				pid_t *pid, char **str);
int			print_exit_free_env_all(t_commande_line **cmd);
int			edit_type(t_commande_line **block, int limiter);
int			check_open_fil(t_commande_line **block);
int			expend_words(t_commande_line **block);
int			is_type_file(t_e_token type);
t_e_token	cp_type_change_file(t_e_token type, int *file);
char		*get_acces(char *str, char *path);
int			try_acces(char *str, char *path);
char		*get_bin_argv_zero(char *str, char *path, int i);
int			no_forking(t_commande_line **cmdl, pid_t *pid);
int			exec_builtin(char **str, t_commande_line **cmdl,
				t_commande_line **first, pid_t *pid);
int			forking(t_commande_line **cmdl, pid_t *pid);
void		ft_clean_env(void);
int			free_str_ret_malloc_error(char *str);
void		ft_clean_envlist(t_env **env);
void		ft_free_env_elem(t_env *env);
int			ft_singletone(char *str, int mode);
void		free_token(t_commande_line **cmd_line);
int			free_all(t_commande_line **cmd_line);
int			end_modif_two(char *str, t_token **stc, char *s1);
void		free_file_name(char *file_name);
int			free_in_builin(t_commande_line **first, pid_t *pid, int ret);
char		*free_split_token(char **split, t_token *tok);
int			free_cmdl_ret_malloc_error(t_commande_line *stc);
int			free_token_ret_malloc_error(t_token *tok);
char		*free_str_ret_null(char *s1);
void		free_both(char *s1, char *s2);
void		free_split(char **split);
int			free_all_env_str_ret_malloc_error(t_commande_line **cmd, char *str);
int			free_all_error(t_commande_line **cmd, char *str, int error);
char		*free_split_ret_null(char **split_path);
void		free_end(t_commande_line **cmd, char *str);
int			free_str_all_ret_malloc_error(t_commande_line **cmd, char *str);
char		*ft_get_str(char *str);
char		*ft_get_str_of_env(t_env **env, char *str);
char		*ft_get_env(char *str);
char		*ft_get_value_of_env(t_env **env, char *str);
int			create_and_fill_cmd(char *str, int cur, int start,
				t_commande_line **first);
int			get_cmd_line(char *string, t_commande_line **first_stc);
char		*init_str(char **str, char *duplica, int *cur, char **s1);
void		init_cmdl(t_commande_line *new);
void		cmdl_add_back(t_commande_line **first, t_commande_line *add_back);
int			ft_init_env(t_env **env_list);
t_env		**get_adress_env(void);
int			ft_init_t_env(char **env);
void		init_token(t_token *new);
void		init_type(t_token *new);
int			move_to(char *str, int *i, t_quote quote);
char		*limitor_unquote(char *str, int *i, char *s1, t_quote quote);
char		*expand_full_quote_str(void);
char		*devellope_limitor(t_token *stc, char *str, int i);
int			limitor(t_token *stc, char *str);
int			ft_built_in_pwd(char **str);
int			ft_built_in_pwd_fd(char **str, int fd);
void		signal_cmd(int sig);
void		error_str(void);
int			wait_pid(t_commande_line **cmdl, pid_t *pid);
void		signal_cmd_2(int sig);
char		*if_no_env(char *str, char *s1, int *cur);
char		*if_env(char *str, char *s1, int *cur);
char		**env_to_tabtab(t_env **envp);
int			ft_exec_cmd(t_commande_line **cmdl, t_commande_line **first,
				char **str, pid_t *pid);
int			ft_execve_fct(t_commande_line **cmdl, t_commande_line **first,
				pid_t *pid);
int			multi_fork(pid_t *pid, int i, t_commande_line **cmdl,
				t_commande_line **cur);
int			redirect_file_in(t_commande_line **cmdl, t_token *cur,
				t_e_token type);
int			redirect_file_out(t_commande_line **cmdl, t_token *cur,
				t_e_token type);
int			open_fd(t_commande_line **cmdl);
void		init_arg(t_commande_line *cmd);
int			nbr_arg_cmd(t_commande_line *cmd);
int			organise_arg(t_commande_line **cmd);
int			pars(char *str, t_commande_line **cmd_line);
void		free_nfd(int **nfd);
void		close_fd_all(t_commande_line **cmdl);
int			init_pipe(int **nfd, int i, t_commande_line *cur);
int			open_pipe(t_commande_line **cmdl);
int			unclose_quote(char	*str);
t_quote		update_quote_status(char c, t_quote quote);
void		to_pipe(int *i, char *str);
int			iter_to_end_arg(int *cur, char *str);
int			split_string_cur_cmdl(t_commande_line **stc);
int			split_all_cmdl_string_to_token(t_commande_line **first);
void		token_add_back(t_token **first, t_token *add_back);
int			create_add_back_token(int cur, int start, char *str,
				t_commande_line **stc);
void		iter_to_end_or_redirection(char	*str, int *cur);
char		*string_env(char *str, char *tmp, int *cur);
char		*string_before_env(char *str, char *s1, int *cur, int start);
char		*end_word_unquote(char *str, char *s1, int *i, int j);
char		*free_split_ret_str(char **split, char *str);
char		*new_token_env(t_token **stc, char **split, int i);
char		*if_n_env(char *str, int *i, char *s1);
char		*if_envc(t_token **stc, char *str, char *s1, int *i);
char		*word_will_unquote(t_token **stc, char *str, int *cur, char *s1);
char		*word_will_double(char *str, int *cur, char *s1);
char		*word_will_single(char *str, int *i, char *s1);
t_quote		update_quote_succes(t_token *stc, int *i, t_quote quote, char **s1);
int			word_modif_two(t_token **stc, char *duplica, t_quote quote,
				t_quote prec);
int			word_modif(t_token **stc, char *str, t_e_token token);
t_e_token	change_type_file(t_e_token type, int *file);
int			ft_is_builtin(char *str);
int			ft_exec_bd_fd(char *str, char **args, t_commande_line **first,
				pid_t *pid);
int			ft_exec_builtin(char *str, char **args, t_commande_line **first,
				pid_t *pid);
int			ft_check_n(char **str);
int			ft_built_in_echo(char **str);
int			ft_built_in_echo_fd(char **str, int fd);
int			ft_print_error(char *str1, char *str2);
char		*ft_get_home(void);
int			ft_pwd(char *s);
int			ft_built_in_cd(char **str);
int			ft_is_equal(char *str);
void		ft_built_in_show_env(t_env **env);
int			ft_built_in_env(char **str);
void		ft_built_in_show_env_fd(t_env **env, int fd);
int			ft_built_in_env_fd(char **str, int fd);
int			ft_built_in_unset(char **str);
int			ft_is_alpha(char c);
void		ft_show_export(t_env **env);
void		ft_built_in_show_export(void);
int			ft_export_is_incorrect(char *s);
int			ft_built_in_export(char **str);
void		ft_putstr_minus_fd(char *s, int len, int fd);
void		ft_show_export_fd(t_env **env, int fd);
void		ft_built_in_show_export_fd(int fd);
int			ft_built_in_export_fd(char **str, int fd);

#endif