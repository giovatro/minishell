/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:34:42 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/09 11:34:44 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	var_exists(t_msh *msh, char *var)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (msh->envp[i])
	{
		if (ft_strncmp(msh->envp[i], var, len) == 0)
			return (0);
		i++;
	}
	return (1);
}

static char	*search_env_var(t_msh *msh, char *var)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (msh->envp[i])
	{
		if (ft_strncmp(msh->envp[i], var, len) == 0)
			break ;
		i++;
	}
	str = ft_strdup(msh->envp[i] + len);
	return (str);
}

char	*recover_val(t_token *token, char *str, t_msh *msh)
{
	char	*value;
	char	*var;

	var = identify_var(str);
	if (var && var_exists(msh, var) == 0)
	{
		if (token != NULL)
			token->var_exists = true;
		value = search_env_var(msh, var);
	}
	else if (var && var[0] == '?' && var[1] == '=')
		value = ft_itoa(msh->exit_status);
	else
		value = NULL;
	free_ptr(var);
	return (value);
}
