/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:30:51 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:30:54 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	cmd_not_found(char *str)
{
	printf(R"mysh: %s: Command not found"RST, str);
	printf("\n");
	return (127);
}

char	*join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*add_space;
	int		i;

	tmp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		new_str = tmp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	new_str = tmp;
	return (new_str);
}

char	**split_str(char **args)
{
	char	**res;
	char	*joined_str;

	joined_str = join_split_str(args, NULL);
	free_arr(args);
	res = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = join_split_str(res, NULL);
	free_arr(res);
	res = ft_split(joined_str, ' ');
	free(joined_str);
	return (res);
}

int	find_cmd(t_msh *msh, char **args)
{
	int		i;
	char	*cmd;

	if (!builtins_cmd(msh))
	{
		i = 0;
		args = split_str(args);
		if (!access(args[0], F_OK))
			execve(args[0], args, msh->envp);
		while (msh->paths[i])
		{
			cmd = ft_strjoin(msh->paths[i], args[0]);
			if (!access(cmd, F_OK))
				execve(cmd, args, msh->envp);
			free(cmd);
			i++;
		}
		return (cmd_not_found(args[0]));
	}
	return (EXIT_SUCCESS);
}

void	handle_cmd(t_msh *msh, char **args)
{
	int	exit_code;

	exit_code = 0;
	msh->paths = find_paths(msh);
	if (args[0][0] != '\0')
		exit_code = find_cmd(msh, args);
	msh->exit_status = exit_code;
	exit(exit_code);
}
