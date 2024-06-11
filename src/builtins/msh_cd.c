/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:35:23 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/08 14:26:13 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	change_path(t_msh *msh, char *path)
{
	if (chdir(path) != 0)
	{
		printf("cd: no such file or directory: %s\n", path);
		msh->exit_status = STDERR_FILENO;
	}
	else
	{
		update_path(msh);
		add_pwd_to_env(msh);
	}
}

int	msh_cd(t_msh *msh)
{
	char	**args;
	char	*new_dir;

	args = tokens_to_array(msh->token_list);
	if (!args[1] || ft_strcmp(args[1], "~") == 0)
		new_dir = msh->home;
	else if (ft_strcmp(args[1], "-") == 0)
	{
		printf("%s\n", msh->old_pwd);
		new_dir = msh->old_pwd;
	}
	else
		new_dir = args[1];
	change_path(msh, new_dir);
	if (args)
		free(args);
	return (1);
}
