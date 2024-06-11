/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:36:15 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/08 14:27:28 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	parse_and_export_variables(t_msh *msh)
{
	t_token_list	*token;
	char			*arg;
	char			*name;
	char			*value;
	int				index;

	token = msh->token_list->next;
	while (token != NULL)
	{
		arg = token->token->value;
		name = ft_strtok(arg, "=");
		value = ft_strtok(NULL, "=");
		if (name == NULL)
		{
			printf("export: invalid argument format: %s\n", arg);
			msh->exit_status = 1;
			return ;
		}
		index = find_variable_index(msh->envp, name);
		if (index != -1)
			update_variable_value(&msh->envp[index], name, value);
		else
			add_variable(&msh->envp, name, value);
		token = token->next;
	}
}

int	msh_export(t_msh *msh)
{
	if (msh->token_list->next == NULL)
		display_environment(msh->envp);
	else
	{
		parse_and_export_variables(msh);
	}
	msh->exit_status = 0;
	return (1);
}
