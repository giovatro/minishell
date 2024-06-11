/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:07:23 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:07:26 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handler.h"

t_token_list	*ft_add_token_list(t_token_list *head, t_token *token)
{
	t_token_list	*current;
	t_token_list	*new_node;

	if (token == NULL)
	{
		ft_putstr_fd("Error: Null token\n", 2);
		return (head);
	}
	new_node = malloc(sizeof(t_token_list));
	if (new_node == NULL)
		error_exit("Error: Failed to allocate memory for token_list");
	new_node->token = token;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (head == NULL)
		return (new_node);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	return (head);
}

void	ft_free_token_list(t_token_list *head)
{
	t_token_list	*current;
	t_token_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		if (current->token != NULL)
		{
			if (current->token->value != NULL)
			{
				free(current->token->value);
				current->token->value = NULL;
			}
			free(current->token);
			current->token = NULL;
		}
		if (current != NULL)
		{
			current = NULL;
			if (next != NULL)
				next->prev = NULL;
		}
		current = next;
	}
}
