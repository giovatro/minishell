/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:56:03 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 13:57:02 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

void	ft_free_lexer(t_lexer *lexer)
{
	if (lexer->input != NULL)
	{
		free(lexer->input);
		lexer->input = NULL;
	}
	free(lexer);
	lexer = NULL;
}

t_lexer	*ft_init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	lexer->input = input;
	lexer->i = 0;
	lexer->c = input[lexer->i];
	return (lexer);
}

void	ft_lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->input))
	{
		lexer->i += 1;
		lexer->c = lexer->input[lexer->i];
	}
}

t_token	*ft_lexer_advance_with_token(t_lexer *lexer, t_token *token)
{
	ft_lexer_advance(lexer);
	return (token);
}

/* check the current character and returns the corresponding token. */
t_token	*ft_lexer(t_lexer *lexer)
{
	t_token	*token;

	token = NULL;
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->input))
	{
		if (lexer->c == '\"' || lexer->c == '\'')
			return (ft_get_string(lexer));
		while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
			ft_lexer_advance(lexer);
		token = ft_get_pipe(lexer);
		if (token != NULL)
			return (token);
		token = ft_get_less_than(lexer);
		if (token != NULL)
			return (token);
		token = ft_get_greater_than(lexer);
		if (token != NULL)
			return (token);
		if (ft_is_extended((int)lexer->c))
			return (ft_get_word(lexer));
	}
	ft_lexer_advance(lexer);
	return (NULL);
}

/*

if conditions:
c == ' " ' ascii code 34 double quotation
c == '\'' ascii code 39 single quote
c == ' ' || '\t' || '\n' ascii code 32 space, 09 tab, 10 end of line
c == '|' ascii code 124 pipe
c == '<' ascii code 60 "less than" is REDIR_IN
c == '<' && input[lexer.i + 1] == '<' is REDIR_HERE_DOC
c == '>' ascii code 62 "greater than" is REDIR_OUT
c == '>' && input[lexer.i + 1] == '>' is REDIR_APPEND
c == '$' ascii code 36 dollar sign (environment variable)
c == '&' ascii code 38 ampersand

*/
