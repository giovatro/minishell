/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:36:30 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/21 11:36:31 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	unset_variable(char ***envp, int index)
{
	int	i;

	free((*envp)[index]);
	i = index;
	while ((*envp)[i] != NULL)
	{
		(*envp)[i] = (*envp)[i + 1];
		i++;
	}
}

static void	process_token(t_msh *msh, t_token_list *token, int *unset_count)
{
	char	*name;
	int		index;

	name = token->token->value;
	index = find_variable_index(msh->envp, name);
	if (index != -1)
	{
		unset_variable(&msh->envp, index);
		(*unset_count)++;
	}
	if (strcmp(name, "PATH") == 0)
		msh->paths = NULL;
}

int	msh_unset(t_msh *msh)
{
	t_token_list	*token;
	int				unset_count;

	if (msh->token_list->next == NULL)
		return (1);
	token = msh->token_list->next;
	unset_count = 0;
	while (token != NULL)
	{
		process_token(msh, token, &unset_count);
		token = token->next;
	}
	if (unset_count > 0)
		msh->exit_status = 0;
	else
		msh->exit_status = 1;
	return (1);
}
