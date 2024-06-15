/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:12:33 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/08 14:56:58 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
sort -r	< infile grep a1 | wc -w > outfile | wc -l | cat -e

cat << EOF
Line 1
Line 2
EOF

echo "Hello, World!" > greeting.txt
echo "Another line" >> greeting.txt
sort < unsorted_list.txt > sorted_list.txt

cat << EOF > output.txt
Line 1
Line 2
EOF
*/

static void	handle_child_process(t_msh *msh, int infile, int *fd, int piped)
{
	if (infile != 0)
	{
		dup2(infile, 0);
		close(infile);
	}
	if (piped)
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
	if (msh->command->input)
		redirect_input(msh->command->input);
	if (msh->command->output)
		redirect_output(msh->command->output, msh->command->append);
	handle_cmd(msh, msh->command->args);
	exit(1);
}

int	execute(t_msh *msh, int infile, int *fd, int piped)
{
	int	status;

	pipe(fd);
	msh->pid = fork();
	config_signals_exec();
	if (msh->pid < 0)
	{
		perror("Fork failed");
		return (EXIT_FAILURE);
	}
	if (msh->pid == 0)
	{
		handle_child_process(msh, infile, fd, piped);
	}
	waitpid(msh->pid, &status, 0);
	if (WIFEXITED(status))
		msh->exit_status = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}

void	parser(t_msh *msh, int infile, int fd[2])
{
	while (msh->token_list)
	{
		if (msh->token_list->token->e_type == WORD
			|| msh->token_list->token->e_type == STRING
			|| msh->token_list->token->e_type == VAR)
			handle_word(&msh->token_list, &msh->command);
		else if (msh->token_list->token->e_type == PIPE)
			handle_pipe(msh, &msh->command, &infile, fd);
		else if (msh->token_list->token->e_type == REDIR_IN)
			handle_redir_in(&msh->token_list, msh->command);
		else if (msh->token_list->token->e_type == REDIR_OUT
			|| msh->token_list->token->e_type == REDIR_APPEND)
			handle_redir_out(&msh->token_list, msh->command);
		else if (msh->token_list->token->e_type == REDIR_HERE_DOC)
			handle_redir_here_doc(&msh->token_list, msh->command);
		msh->token_list = msh->token_list->next;
	}
	execute(msh, infile, fd, 0);
}

void	free_command(t_cmd *command)
{
	if (command)
	{
		if (command->args)
			free_arr(command->args);
		if (command->input)
			free(command->input);
		if (command->output)
			free(command->output);
		free(command);
	}
}

int	executor(t_msh *msh)
{
	int				fd[2];
	int				infile;

	signal(SIGINT, SIG_IGN);
	msh->command = init_cmd();
	infile = STDIN_FILENO;
	if (!check_builtins(msh))
		parser(msh, infile, fd);
	if (msh->command)
		free_command(msh->command);
	return (EXIT_SUCCESS);
}
