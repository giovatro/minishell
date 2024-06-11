/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:19:55 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/09 11:19:58 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static bool	should_replace_var(t_token_list *temp, int i)
{
	return (temp->token->value[i] == '$'
		&& is_next_char_a_sep(temp->token->value[i + 1]) == false
		&& var_between_quotes(temp->token->value, i) == false
		&& (temp->token->status == DEFAULT
			|| temp->token->status == DQUOTE));
}

static void	process_token(t_token_list **temp, t_msh *msh)
{
	int	i;

	i = 0;
	while ((*temp)->token->value[i])
	{
		if (should_replace_var(*temp, i))
			replace_var(temp, recover_val((*temp)->token,
					(*temp)->token->value + i, msh), i);
		else
			i++;
	}
}

int	var_expander(t_msh *msh, t_token_list **token_list)
{
	t_token_list	*temp;

	temp = *token_list;
	while (temp)
	{
		if (temp->token->e_type == VAR)
			process_token(&temp, msh);
		temp = temp->next;
	}
	return (0);
}

char	*var_expander_heredoc(t_msh *msh, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$'
			&& is_next_char_a_sep(str[i + 1]) == false
			&& var_between_quotes(str, i) == false)
			str = replace_str_heredoc(str, recover_val(NULL, str + i, msh), i);
		else
			i++;
	}
	return (str);
}
