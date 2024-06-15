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

bool	check_n_option(char **args)
{
	bool	n;

	n = false;
	if (args[1] != NULL && ft_strcmp(args[1], "-n") == 0)
	{
		n = true;
	}
	return (n);
}

int	get_start_index(bool n)
{
	int	i;

	if (n)
	{
		i = 2;
	}
	else
	{
		i = 1;
	}
	return (i);
}

int	msh_echo(t_msh *msh)
{
	char	**args;
	bool	n;
	int		i;

	args = msh->command->args;
	n = check_n_option(args);
	i = get_start_index(n);
	while (args[i] != NULL)
	{
		write(STDOUT_FILENO, args[i], ft_strlen(args[i]));
		if (args[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (!n)
		write(STDOUT_FILENO, "\n", 1);
	msh->exit_status = 0;
	return (1);
}

int	msh_echo_no_path(t_msh *msh)
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
