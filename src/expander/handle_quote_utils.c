/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:34:22 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/09 11:34:24 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	remove_quotes(t_token_list **token_list)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * count_len((*token_list)->token->value, i, i));
	if (!line)
		return (1);
	while ((*token_list)->token->value[i])
	{
		line[j++] = (*token_list)->token->value[i++];
	}
	line[j] = '\0';
	free_ptr((*token_list)->token->value);
	(*token_list)->token->value = line;
	(*token_list)->token->join = true;
	return (0);
}

int	count_len(char *str, int count, int i)
{
	int	status;

	status = DEFAULT;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && status == DEFAULT)
		{
			if (str[i] == '\'')
				status = SQUOTE;
			if (str[i] == '\"')
				status = DQUOTE;
			i++;
			continue ;
		}
		else if ((str[i] == '\'' && status == SQUOTE)
			|| (str[i] == '\"' && status == DQUOTE))
		{
			status = DEFAULT;
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count + 1);
}
