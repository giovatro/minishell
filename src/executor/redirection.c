/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:03:31 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 15:03:34 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	handle_word(t_token_list **token_list, t_cmd **command)
{
	if (!*command)
		*command = init_cmd();
	add_arg_to_command(*command, (*token_list)->token->value);
}

void	handle_pipe(t_msh *msh, t_cmd **command, int *infile, int fd[2])
{
	execute(msh, *infile, fd, 1);
	close(fd[1]);
	*infile = fd[0];
	*command = NULL;
}

void	handle_redir_in(t_token_list **token_list, t_cmd *command)

{
	*token_list = (*token_list)->next;
	command->input = ft_strdup((*token_list)->token->value);
	if (command->input == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
}

void	handle_redir_out(t_token_list **token_list, t_cmd *command)
{
	if ((*token_list)->token->e_type == REDIR_APPEND)
		command->append = 1;
	else
		command->append = 0;
	*token_list = (*token_list)->next;
	command->output = ft_strdup((*token_list)->token->value);
	if (command->output == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
}

void	handle_redir_here_doc(t_token_list **token_list, t_cmd *command)
{
	char	*delimiter;
	char	*tempfile;
	char	*line;

	tempfile = create_tempfile();
	command->input = tempfile;
	*token_list = (*token_list)->next;
	delimiter = ft_strdup((*token_list)->token->value);
	line = readline("heredoc> ");
	while (line != NULL)
	{
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		write_to_tempfile(tempfile, line);
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	free(delimiter);
}
