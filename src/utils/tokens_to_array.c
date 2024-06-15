/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:18:40 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:07 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	count_tokens(t_token_list *token_list)
{
	int				count;
	t_token_list	*current;

	count = 0;
	current = token_list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

char	**tokens_to_array(t_token_list *token_list)
{
	t_token_list	*current;
	int				count;
	char			**args;
	int				i;

	count = count_tokens(token_list);
	args = (char **)malloc((count + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	current = token_list;
	i = 0;
	while (i < count)
	{
		args[i] = current->token->value;
		current = current->next;
		i++;
	}
	args[count] = NULL;
	return (args);
}
