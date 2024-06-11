/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:30:19 by gtroiano          #+#    #+#             */
/*   Updated: 2024/06/08 14:55:30 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	redirect_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(fd, 0);
	close(fd);
}

void	redirect_output(char *file, int append)
{
	int	fd;

	if (append)
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(fd, 1);
	close(fd);
}

char	*create_tempfile(void)
{
	char	*tempfile;
	int		fd;

	tempfile = ft_strdup("/tmp/.msh_tempfile");
	fd = open(tempfile, O_RDWR | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	close(fd);
	return (tempfile);
}

void	write_to_tempfile(char *tempfile, char *line)
{
	int	fd;

	fd = open(tempfile, O_RDWR | O_APPEND);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	close(fd);
}
