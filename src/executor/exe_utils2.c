/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:51:58 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/09 11:52:01 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*command;

	command = malloc(sizeof(t_cmd));
	if (command == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	command->args = NULL;
	command->input = NULL;
	command->output = NULL;
	command->append = 0;
	return (command);
}

void	add_arg_to_command(t_cmd *command, char *arg)
{
	int	i;

	i = 0;
	while (command->args && command->args[i])
		i++;
	command->args = ft_realloc(command->args, sizeof(char *) * (i + 2));
	if (command->args == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	command->args[i] = arg;
	command->args[i + 1] = NULL;
}
