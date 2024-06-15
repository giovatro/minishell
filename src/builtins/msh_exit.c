/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:35:54 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/21 11:35:59 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	remove_tempfile(void)
{
	if (access("/tmp/.msh_tempfile", F_OK) != -1)
		remove("/tmp/.msh_tempfile");
}

void	clean(t_msh *msh)
{
	remove_tempfile();
	if (msh->paths != NULL)
		free_arr(msh->paths);
	if (msh->envp != NULL)
		free_arr(msh->envp);
	if (msh->pwd != NULL)
		free(msh->pwd);
	if (msh->home != NULL)
		free(msh->home);
	if (msh->token_list != NULL)
	{
		ft_free_token_list(msh->token_list);
		msh->token_list = NULL;
	}
	msh = NULL;
}

static void	handle_too_many_arguments(t_msh *msh, char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		printf("msh: exit: too many arguments\n");
		msh->exit_status = 1;
		return ;
	}
}

static void	handle_numeric_argument(t_msh *msh, char **args)
{
	int	i;

	if (args[1] == NULL)
		return ;
	i = 0;
	if (args[1][0] == '-' || args[1][0] == '+')
		i++;
	while (args[1][i] != '\0')
	{
		if (!ft_isdigit(args[1][i]))
		{
			printf("msh: exit: %s: numeric argument required\n", args[1]);
			msh->exit_status = 255;
			return ;
		}
		i++;
	}
}

void	msh_exit(t_msh *msh)
{
	int		exit_status;
	char	**args;

	args = tokens_to_array(msh->token_list);
	handle_too_many_arguments(msh, args);
	handle_numeric_argument(msh, args);
	if (args[1] != NULL)
		exit_status = ft_atoi(args[1]);
	else
		exit_status = msh->exit_status;
	clean(msh);
	exit(exit_status);
}
