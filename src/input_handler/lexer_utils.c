/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:01:16 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:01:24 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

int	ft_count_the_same(t_lexer *lexer, char symbol)
{
	int		count;
	int		i;

	count = 0;
	i = lexer->i;
	while (lexer->input[i] == symbol)
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_str_repeat(char c, int count)
{
	char	*str;
	int		i;

	str = malloc(count + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = c;
		i++;
	}
	str[count] = '\0';
	return (str);
}

int	ft_is_extended(int c)
{
	return ((c >= 32 && c <= 255) && c != 127 && c != 129 && c != 141
		&& c != 143 && c != 144 && c != 157 && c != 160
		&& c != 173 && c != 34 && c != 39);
}
