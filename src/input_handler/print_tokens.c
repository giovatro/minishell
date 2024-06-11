/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:11:53 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:11:56 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

void	ft_print_token(t_token *token)
{
	const char	*type[] = {"STRING", "WORD", "PIPE",
		"REDIR_IN", "REDIR_HERE_DOC", "REDIR_OUT", "REDIR_APPEND",
		"NOT_TO_HANDLE", "VAR", "DEFAULT", "SQUOTE", "DQUOTE"};

	printf("TOKEN NUMBER: %d\t |", token->position);
	printf("TOKEN TYPE: %s\t |", type[token->e_type]);
	printf("TOKEN STATUS: %s\t |", type[token->status]);
	printf("TOKEN VALUE: %s\n", token->value);
}

void	ft_print_token_list(t_token_list *token_list)
{
	t_token_list	*current;

	current = token_list;
	while (current != NULL)
	{
		ft_print_token(current->token);
		current = current->next;
	}
}
