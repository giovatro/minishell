/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:36:37 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/08 15:22:01 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "msh.h"

char	**ft_arrdup(char **arr);
void	free_arr(char **split_arr);
char	**tokens_to_array(t_token_list *token_list);

void	config_signals_input(void);
void	config_signals_exec(void);

#endif
