/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:29:16 by tluu              #+#    #+#             */
/*   Updated: 2022/09/29 10:27:02 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	verif_extension(char *file)
{
	char	*extension;
	char	*file_extension;

	extension = ".cub";
	file_extension = file + (ft_strlen(file) - ft_strlen(extension));
	if (ft_strncmp(file_extension, extension, ft_strlen(extension)) != 0)
		return (0);
	return (1);
}

char	**define_info(char *info[6])
{
	int	i;

	info[0] = ft_strdup("NO");
	info[1] = ft_strdup("SO");
	info[2] = ft_strdup("WE");
	info[3] = ft_strdup("EA");
	info[4] = ft_strdup("F");
	info[5] = ft_strdup("C");
	i = 0;
	while (i < 6)
	{
		if (!info[i])
			return (NULL);
		i++;
	}
	return (info);
}

void	*free_info(char *info[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(info[i]);
		i++;
	}
	return (NULL);
}

void	init_texture(t_data *data)
{
	data->libx->txtr_w_north = NULL;
	data->libx->txtr_w_south = NULL;
	data->libx->txtr_w_east = NULL;
	data->libx->txtr_w_west = NULL;
	data->libx->texture_floor = -1;
	data->libx->texture_ceiling = -1;
}

char	**parse_file(char *file, t_data *data, t_hero *hero)
{
	int		fd;
	char	*info[6];
	char	**map_temp;

	init_texture(data);
	if (!verif_extension(file))
		return (ft_error_char("Error: wrong extension"));
	if (open(file, O_DIRECTORY) != -1)
		return (ft_error_char("Error: file is a directory"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error_char("Error: open fail"));
	if (!define_info(info))
	{
		close(fd);
		return (ft_error_char("Error : malloc error"));
	}
	map_temp = search_map_info(fd, data, info);
	close(fd);
	if (!map_temp)
		return (free_info(info));
	if (!parsing_map(data, map_temp, hero))
		return (free_info(info));
	free_info(info);
	return (data->map);
}
