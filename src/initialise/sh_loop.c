/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:27:44 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/01 10:27:46 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialise.h"

int	g_signal;

static void	handle_input(t_msh *msh, char *input)
{
	if (ft_is_whitespaces(input))
	{
		free(input);
		return ;
	}
	add_history(input);
	if (input_handler(input, msh))
	{
		ft_free_token_list(msh->token_list);
		return ;
	}
	executor(msh);
	if (g_signal == SIGINT)
		msh->exit_status = 128 + g_signal;
	ft_free_token_list(msh->token_list);
}

void	sh_loop(t_msh *msh)
{
	char	*input;

	while (1)
	{
		g_signal = 0;
		config_signals_input();
		input = readline("mysh > ");
		if (g_signal == SIGINT)
			msh->exit_status = 1;
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		handle_input(msh, input);
	}
}
