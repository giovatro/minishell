/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:52 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/05 10:17:53 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALISE_H
# define INITIALISE_H

# include "msh.h"

void	sh_init(t_msh *msh, char **envp);
void	sh_loop(t_msh *msh);
char	**find_paths(t_msh *msh);

#endif
