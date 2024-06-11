/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:57:56 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:00:15 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

void	ft_greater_than_helper(t_lexer	*lexer, char *value, t_token **token)
{
	if (ft_count_the_same(lexer, '>') == 1)
	{
		value = ft_char_to_str(lexer);
		*token = ft_lexer_advance_with_token(lexer,
				ft_init_token(REDIR_OUT, value, '\0'));
		free(value);
	}
	else if (ft_count_the_same(lexer, '>') == 2)
	{
		lexer->i++;
		*token = ft_lexer_advance_with_token(lexer,
				ft_init_token(REDIR_APPEND, ">>", '\0'));
	}
	else if (ft_count_the_same(lexer, '>') >= 3)
	{
		value = ft_str_repeat('>', ft_count_the_same(lexer, '>'));
		lexer->i += ft_count_the_same(lexer, '>');
		lexer->c = lexer->input[lexer->i];
		*token = ft_init_token(NOT_TO_HANDLE, value, '\0');
		free(value);
	}
}

void	ft_less_than_helper(t_lexer	*lexer, char *value, t_token **token)
{
	if (ft_count_the_same(lexer, '<') == 1)
	{
		value = ft_char_to_str(lexer);
		*token = ft_lexer_advance_with_token(lexer,
				ft_init_token(REDIR_IN, value, '\0'));
		free(value);
	}
	else if (ft_count_the_same(lexer, '<') == 2)
	{
		lexer->i++;
		*token = ft_lexer_advance_with_token(lexer,
				ft_init_token(REDIR_HERE_DOC, "<<", '\0'));
	}
	else if (ft_count_the_same(lexer, '<') >= 3)
	{
		value = ft_str_repeat('<', ft_count_the_same(lexer, '<'));
		lexer->i += ft_count_the_same(lexer, '<');
		lexer->c = lexer->input[lexer->i];
		*token = ft_init_token(NOT_TO_HANDLE, value, '\0');
		free(value);
	}
}

t_token	*ft_get_greater_than(t_lexer *lexer)
{
	t_token	*token;
	char	*value;

	value = NULL;
	token = NULL;
	if (lexer->c == '>')
		ft_greater_than_helper(lexer, value, &token);
	return (token);
}

t_token	*ft_get_less_than(t_lexer *lexer)
{
	t_token	*token;
	char	*value;

	value = NULL;
	token = NULL;
	if (lexer->c == '<')
		ft_less_than_helper(lexer, value, &token);
	return (token);
}

t_token	*ft_get_pipe(t_lexer *lexer)
{
	t_token	*token;
	char	*value;

	if (lexer->c == '|' && ft_count_the_same(lexer, '|') == 1)
	{
		value = ft_char_to_str(lexer);
		token = ft_init_token(PIPE, value, '\0');
		free(value);
		return (ft_lexer_advance_with_token(lexer, token));
	}
	else if (lexer->c == '|' && ft_count_the_same(lexer, '|') >= 2)
	{
		value = ft_str_repeat('|', ft_count_the_same(lexer, '|'));
		lexer->i += ft_count_the_same(lexer, '|');
		lexer->c = lexer->input[lexer->i];
		token = ft_init_token(NOT_TO_HANDLE, value, '\0');
		free (value);
		return (token);
	}
	return (NULL);
}
