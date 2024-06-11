/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:44 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/08 14:15:23 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"

char	**handle_no_path(t_msh *msh, int i)
{
	if (!msh->envp[i])
	{
		printf("Error: PATH not found in environment variables.\n");
		msh->paths = NULL;
		return (NULL);
	}
	return (msh->envp);
}

char	**find_paths(t_msh *msh)
{
	int		i;
	char	*tmp;
	char	**paths;

	i = 0;
	while (msh->envp[i] && ft_strnstr(msh->envp[i], "PATH=", 5) == 0)
		i++;
	msh->envp = handle_no_path(msh, i);
	if (msh->envp == NULL)
		return (NULL);
	paths = ft_split(msh->envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		if (ft_strncmp(&paths[i][ft_strlen(paths[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(paths[i], "/");
			free(paths[i]);
			paths[i] = tmp;
		}
		i++;
	}
	return (paths);
}

void	sh_init(t_msh *msh, char **envp)
{
	msh->envp = ft_arrdup(envp);
	msh->exit_status = 0;
	msh->paths = find_paths(msh);
	find_pwd(msh);
	find_home(msh);
}
