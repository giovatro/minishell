/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:53:34 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/07 11:53:36 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

bool	has_not_to_handle(t_token_list *token_list)
{
	while (token_list != NULL)
	{
		if (token_list->token->e_type == NOT_TO_HANDLE)
		{
			printf("mysh:command not to handle: %s\n",
				token_list->token->value);
			return (true);
		}
		token_list = token_list->next;
	}
	return (false);
}

int	input_handler(char *input, t_msh *msh)
{
	if (ft_tokenize_input(input, msh) == EXIT_FAILURE)
	{
		msh->exit_status = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	if (has_not_to_handle(msh->token_list) == true)
	{
		msh->exit_status = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	if (check_if_var(&msh->token_list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	var_expander(msh, &msh->token_list);
	handle_quotes(msh);
	return (EXIT_SUCCESS);
}
