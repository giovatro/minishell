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
}

int	msh_exit(t_msh *msh)
{
	int	exit_status;

	exit_status = msh->exit_status;
	clean(msh);
	if (msh->token_list != NULL)
	{
		ft_free_token_list(msh->token_list);
		msh->token_list = NULL;
	}
	msh = NULL;
	exit(exit_status);
	return (1);
}
