/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:34:06 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/09 11:34:08 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

bool	quotes_in_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (true);
		i++;
	}
	return (false);
}

int	handle_quotes(t_msh *msh)
{
	t_token_list	*temp;

	temp = msh->token_list;
	while (temp)
	{
		if (quotes_in_string(temp->token->value) == true
			&& (!temp->prev || (temp->prev
					&& temp->prev->token->e_type != REDIR_HERE_DOC)))
			remove_quotes(&temp);
		temp = temp->next;
	}
	return (0);
}
