/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:25:50 by tluanamn          #+#    #+#             */
/*   Updated: 2024/04/24 18:25:53 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	display_environment(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

int	find_variable_index(char **envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) == 0
			&& envp[i][ft_strlen(name)] == '=')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	update_variable_value(char **variable, char *name, char *value)
{
	char	*new_var;
	size_t	value_len;

	value_len = 0;
	if (value != NULL)
		value_len = ft_strlen(value);
	new_var = (char *)malloc(ft_strlen(name) + value_len + 3);
	if (new_var == NULL)
		error_exit("Memory allocation failed: update_variable_value: new_var");
	ft_strcpy(new_var, name);
	ft_strcat(new_var, "=");
	if (value != NULL)
		ft_strcat(new_var, value);
	else
		ft_strcat(new_var, "''");
	free(*variable);
	*variable = new_var;
}

void	add_variable(char ***envp, char *name, char *value)
{
	char	*new_var;
	size_t	value_len;
	int		num_vars;

	value_len = 0;
	if (value != NULL)
		value_len = ft_strlen(value);
	new_var = (char *)malloc(ft_strlen(name) + value_len + 3);
	if (new_var == NULL)
		error_exit("Memory allocation failed: add_variable: new_var");
	ft_strcpy(new_var, name);
	ft_strcat(new_var, "=");
	if (value != NULL)
		ft_strcat(new_var, value);
	else
		ft_strcat(new_var, "''");
	num_vars = 0;
	while ((*envp)[num_vars] != NULL)
		num_vars++;
	*envp = (char **)ft_realloc(*envp, (num_vars + 2) * sizeof(char *));
	if (*envp == NULL)
		error_exit("Memory allocation failed: add_variable: envp");
	(*envp)[num_vars] = new_var;
	(*envp)[num_vars + 1] = NULL;
}
