/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:12:40 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/08 14:57:53 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "msh.h"

int		executor(t_msh *msh);
int		execute(t_msh *msh, int infile, int *fd, int piped);
void	parser(t_msh *msh, int infile, int fd[2]);

//cmd utils
int		cmd_not_found(char *str);
char	*join_split_str(char **split_str, char *new_str);
char	**split_str(char **args);
int		find_cmd(t_msh *msh, char **args);
void	handle_cmd(t_msh *msh, char **args);

// exe utils
t_cmd	*init_cmd(void);
void	add_arg_to_command(t_cmd *command, char *arg);
void	redirect_input(char *file);
void	redirect_output(char *file, int append);
char	*create_tempfile(void);
void	write_to_tempfile(char *tempfile, char *line);

//redirections
void	handle_word(t_token_list **token_list, t_cmd **command);
void	handle_pipe(t_msh *msh, t_cmd **command, int *infile, int fd[2]);
void	handle_redir_in(t_token_list **token_list, t_cmd *command);
void	handle_redir_out(t_token_list **token_list, t_cmd *command);
void	handle_redir_here_doc(t_token_list **token_list, t_cmd *command);

#endif
