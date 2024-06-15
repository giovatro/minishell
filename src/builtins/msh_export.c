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

static void	check_name(t_msh *msh, char *name, char *arg)
{
	if (name == NULL)
	{
		printf("export: invalid argument format: %s\n", arg);
		msh->exit_status = 1;
		return ;
	}
}

static char	*get_value(t_token_list **token)
{
	char	*value;

	if ((*token)->next != NULL && (*token)->next->token->e_type == STRING)
	{
		value = (*token)->next->token->value;
		*token = (*token)->next;
	}
	else
	{
		value = ft_strtok(NULL, "=");
	}
	return (value);
}

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
		value = get_value(&token);
		check_name(msh, name, arg);
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
	msh->paths = find_paths(msh);
	msh->exit_status = 0;
	return (1);
}
