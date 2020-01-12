/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:00:17 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/25 17:00:19 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ECHO 1
# define CD 2
# define SETENV 4
# define UNSETENV 8
# define ENV 16
# define EXIT 32
# define LOZENGE 64
# define EIGHT 128

# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <signal.h>
# include <limits.h>
# include "../libft/includes/binary_tree.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct		s_command
{
	uint8_t			command_btin;
	char			*argv;
	char			*command_env;
	char			*flags;
	char			*env_path;
	char			*env_home;
	char			*env_tmp;
	char			*pwd;
	char			*oldpwd;
	char			**all_env;
}					t_command;

int					ms_parser(char *input, t_command *command, char **environ);
int					ms_function_box(t_command *command);
int					check_type_perm(char *function, char *where);
char				*remain_input(char **all_args, char *input, char **all_env);
char				*ms_check_path(char *function, char *paths);
char				*ms_quotmarks(char *extra_input);
char				*ms_lastquotmarks(char *final);
char				*ms_clean_input(char *input);
void				whereami(t_command *command);
void				initialize(t_command *command);
void				ms_echo(t_command *command);
void				ms_cd(t_command *command);
void				ms_env(t_command *command);
void				ms_setenv(t_command *command);
void				ms_unsetenv(t_command *command);
void				ms_random_8();
void				ms_tarot(void);
void				ms_clean(t_command *command);
void				ms_final_clean(t_command *command);

#endif
