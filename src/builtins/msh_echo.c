/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:35:32 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/21 11:35:34 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	msh_echo(t_msh *msh)
{
	t_token_list	*current;
	bool			n;

	n = false;
	current = msh->token_list;
	if (current != NULL)
		current = current->next;
	if (current != NULL && ft_strcmp(current->token->value, "-n") == 0)
	{
		n = true;
		current = current->next;
	}
	while (current != NULL)
	{
		ft_putstr_fd(current->token->value, STDOUT_FILENO);
		current = current->next;
		if (current != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (!n)
		ft_putchar_fd('\n', STDOUT_FILENO);
	msh->exit_status = 0;
	return (1);
}
