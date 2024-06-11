/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_welcome.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:04:39 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/01 09:04:40 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_msg.h"

void	write_welcome(void)
{
	int	i;

	i = 0;
	printf(C"\n");
	while (i <= 80)
	{
		printf("*");
		i++;
	}
	printf("\n*                            MSH by Tony and Johny");
	printf("                              *\n");
	i = 0;
	while (i <= 80)
	{
		printf("*");
		i++;
	}
	printf("\n\n"RST);
}
