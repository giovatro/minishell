/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:35:00 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/08 14:21:16 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_builtins(t_msh *msh)
{
	char	*command;

	command = msh->token_list->token->value;
	if (ft_strcmp(command, "pwd") == 0)
		return (msh_pwd(msh));
	if (ft_strcmp(command, "exit") == 0)
		return (msh_exit(msh));
	if (ft_strcmp(command, "echo") == 0)
		return (msh_echo(msh));
	if (ft_strcmp(command, "cd") == 0)
		return (msh_cd(msh));
	if (ft_strcmp(command, "env") == 0)
		return (msh_env(msh));
	if (ft_strcmp(command, "export") == 0)
		return (msh_export(msh));
	if (ft_strcmp(command, "unset") == 0)
		return (msh_unset(msh));
	return (0);
}
