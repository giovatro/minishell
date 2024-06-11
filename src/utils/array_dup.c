/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:37:13 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/07 11:37:18 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_arr(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i] != NULL)
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

char	**ft_arrdup(char **arr)
{
	char	**str;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	str = ft_calloc(sizeof(char *), i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		str[i] = ft_strdup(arr[i]);
		if (str[i] == NULL)
		{
			free_arr(str);
			return (str);
		}
		i++;
	}
	return (str);
}
