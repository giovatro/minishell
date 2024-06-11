/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:19:03 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/21 10:19:07 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;

	if (argc != 1 || argv[1])
		error_exit("Wrong command!\nTry: ./minishell");
	write_welcome();
	sh_init(&msh, envp);
	sh_loop(&msh);
	clean(&msh);
	return (0);
}
