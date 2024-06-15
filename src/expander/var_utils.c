/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:35:42 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/09 11:35:44 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	variable_check(t_token_list **token_list)
{
	int	i;

	i = 0;
	while ((*token_list)->token->value[i])
	{
		if ((*token_list)->token->value[i] == '$')
		{
			if ((*token_list)->prev
				&& (*token_list)->prev->token->e_type == REDIR_HERE_DOC)
				break ;
			(*token_list)->token->e_type = VAR;
			return ;
		}
		i++;
	}
}

int	check_if_var(t_token_list **token_list)
{
	t_token_list	*temp;

	temp = *token_list;
	while (temp)
	{
		variable_check(&temp);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}

void	copy_var_value(char *new_str, char *var_value, int *j)
{
	int	k;

	k = 0;
	while (var_value[k])
	{
		new_str[*j] = var_value[k];
		k++;
		(*j)++;
	}
}

char	*get_new_token_string(char *oldstr, char *var_value,
		int newstr_size, int index)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * newstr_size);
	if (!new_str)
		return (NULL);
	while (oldstr[i])
	{
		if (oldstr[i] == '$' && i == index)
		{
			copy_var_value(new_str, var_value, &j);
			i = i + var_length(oldstr + index) + 1;
			if (oldstr[i] == '\0')
				break ;
		}
		new_str[j++] = oldstr[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
