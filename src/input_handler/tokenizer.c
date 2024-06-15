/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:10:50 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:10:53 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

int	set_status(int status, char quotes)
{
	if (quotes == '\'')
		status = SQUOTE;
	else if (quotes == '\"')
		status = DQUOTE;
	else if (quotes == '\0')
		status = DEFAULT;
	return (status);
}

/* return a pointer to the created token */
t_token	*ft_init_token(int type, char *value, char quotes)
{
	t_token		*token;
	static int	order;

	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		error_exit("Error: Failed to allocate memory for token\n");
	token->e_type = type;
	token->var_exists = false;
	token->join = false;
	if (value && value[ft_strlen(value)] == '\0')
		token->value = ft_strdup(value);
	else
		error_exit("Error: Value is not null-terminated\n");
	token->position = order++;
	token->status = set_status(token->status, quotes);
	return (token);
}

bool	quotes_check(char *input)
{
	bool	single_quote;
	bool	double_quote;
	int		i;

	i = 0;
	single_quote = false;
	double_quote = false;
	while (input[i] != '\0')
	{
		if (input[i] == '\'')
			single_quote = !single_quote;
		else if (input[i] == '\"')
			double_quote = !double_quote;
		i++;
	}
	if (single_quote || double_quote)
	{
		if (single_quote)
			printf("Unmatched single quote found.\n");
		if (double_quote)
			printf("Unmatched double quote found.\n");
		return (true);
	}
	return (false);
}

/* Tokenize the input string and store the tokens in a token list */
int	ft_tokenize_input(char *input, t_msh *msh)
{
	t_lexer	*lexer;
	t_token	*token;

	if (quotes_check(input))
		return (EXIT_FAILURE);
	lexer = ft_init_lexer(input);
	msh->token_list = NULL;
	while (1)
	{
		token = ft_lexer(lexer);
		if (token == NULL)
			break ;
		msh->token_list = ft_add_token_list(msh->token_list, token);
	}
	ft_free_lexer(lexer);
	return (EXIT_SUCCESS);
}
