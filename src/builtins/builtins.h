/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:35:06 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/21 11:35:08 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "msh.h"

int		check_builtins(t_msh *msh);
int		builtins_cmd(t_msh *msh);
int		msh_pwd(t_msh *msh);
int		msh_echo(t_msh *msh);
int		msh_echo_no_path(t_msh *msh);
int		msh_cd(t_msh *msh);
int		msh_env(t_msh *msh);
int		msh_export(t_msh *msh);
int		msh_unset(t_msh *msh);
void	msh_exit(t_msh *msh);
void	clean(t_msh *msh);
void	remove_tempfile(void);

void	display_environment(char **envp);
int		find_variable_index(char **envp, char *name);
void	update_variable_value(char **variable, char *name, char *value);
void	add_variable(char ***envp, char *name, char *value);

char	*find_path(char *cmd, char **env);
int		find_pwd(t_msh *msh);
void	add_pwd_to_env(t_msh *msh);
int		find_home(t_msh *msh);
void	update_path(t_msh *msh);

#endif
