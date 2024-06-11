/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:03:37 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:03:40 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

/* It gets the current character as a string */
char	*ft_char_to_str(t_lexer *lexer)
{
	char	*string;

	string = ft_calloc(2, sizeof(char));
	string[0] = lexer->c;
	string[1] = '\0';
	return (string);
}

char	*ft_process_chars(t_lexer *lexer, char *value)
{
	char	*tmp;

	tmp = ft_char_to_str(lexer);
	value = ft_realloc(value,
			(ft_strlen(value) + ft_strlen(tmp) + 1) * sizeof(char));
	ft_strcat(value, tmp);
	free(tmp);
	ft_lexer_advance(lexer);
	return (value);
}

/* Consider a sequence of characters between two double quotes. */
t_token	*ft_get_string(t_lexer *lexer)
{
	t_token	*token;
	char	*value;
	char	quotes;

	quotes = lexer->c;
	ft_lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (lexer->c != quotes)
		value = ft_process_chars(lexer, value);
	ft_lexer_advance(lexer);
	if (lexer->c == quotes)
		return (ft_get_string(lexer));
	token = ft_init_token(STRING, value, quotes);
	free(value);
	return (token);
}

/* As a word, consider a sequence of alphanumeric characters. */
t_token	*ft_get_word(t_lexer *lexer)
{
	t_token	*token;
	char	*value;

	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (ft_is_extended((int)lexer->c))
	{
		if (lexer->c == ' ' || lexer->c == '|'
			|| lexer->c == '>' || lexer->c == '<')
			break ;
		value = ft_process_chars(lexer, value);
	}
	while (lexer->c == ' ')
		ft_lexer_advance(lexer);
	token = ft_init_token(WORD, value, '\0');
	token->status = DEFAULT;
	free(value);
	return (token);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (malloc(size));
	if (!size)
	{
		if (ptr)
		{
			free(ptr);
			ptr = NULL;
		}
		return (NULL);
	}
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	ptr = NULL;
	return (new);
}
