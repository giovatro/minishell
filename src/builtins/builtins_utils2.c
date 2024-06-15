/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:23:25 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:23:29 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	find_pwd(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->envp[i])
	{
		if (!ft_strncmp(msh->envp[i], "PWD=", 4))
			msh->pwd = ft_substr(msh->envp[i],
					4, ft_strlen(msh->envp[i]) - 4);
		if (!ft_strncmp(msh->envp[i], "OLDPWD=", 7))
			msh->old_pwd = ft_substr(msh->envp[i],
					7, ft_strlen(msh->envp[i]) - 7);
		i++;
	}
	return (1);
}

int	find_home(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->envp[i])
	{
		if (!ft_strncmp(msh->envp[i], "HOME=", 5))
			msh->home = ft_substr(msh->envp[i],
					5, ft_strlen(msh->envp[i]) - 5);
		i++;
	}
	return (1);
}

void	update_path(t_msh *msh)
{
	char	*tmp;

	tmp = ft_strdup(msh->pwd);
	free(msh->old_pwd);
	msh->old_pwd = tmp;
	free(msh->pwd);
	msh->pwd = getcwd(NULL, sizeof(NULL));
}

void	add_pwd_to_env(t_msh *msh)
{
	int		i;
	char	*tmp;

	i = 0;
	while (msh->envp[i])
	{
		if (!ft_strncmp(msh->envp[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", msh->pwd);
			free(msh->envp[i]);
			msh->envp[i] = tmp;
		}
		else if (!ft_strncmp(msh->envp[i], "OLDPWD=", 7) && msh->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", msh->old_pwd);
			free(msh->envp[i]);
			msh->envp[i] = tmp;
		}
		i++;
	}
}
