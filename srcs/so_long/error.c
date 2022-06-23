/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:58:18 by mdelforg          #+#    #+#             */
/*   Updated: 2022/06/09 15:45:55 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tab(char **tab, size_t i)
{
	i++;
	while (i)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return ;
}

void	ft_error(char *msg)
{
	write(2, "Error\n", 6);
	printf("--%s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_map_error(char *msg, char **map)
{
	ft_free_tab(map, ft_map_size(map));
	write(2, "Error\n", 6);
	printf("--%s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_error_tab_str(char *msg, char *str, char **map)
{
	free(str);
	ft_free_tab(map, ft_map_size(map));
	write(2, "Error\n", 6);
	printf("--%s\n", msg);
	exit(EXIT_FAILURE);
}
