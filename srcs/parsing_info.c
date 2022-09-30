/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:29:31 by tluu              #+#    #+#             */
/*   Updated: 2022/09/28 19:00:14 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	put_info(char *line, char **info, int ismap, t_data *data)
{
	int		i;
	char	**new_line;

	new_line = ft_split(line, 32);
	if (!new_line)
		return (ft_error_int("Error: malloc failed", -2));
	if (ft_strncmp(new_line[0], "\n", 2))
	{
		i = 0;
		while (i < 6)
		{
			if (!ft_strncmp(new_line[0], info[i], ft_strlen(info[i]) + 1))
			{
				ismap = 1;
				if (!parse_texture(new_line[1], line, info[i], data->libx))
					ismap = -2;
				break ;
			}
			else
				ismap = -1;
			i++;
		}
	}
	free_split(new_line);
	return (ismap);
}

char	*putmap2(char *line, char *fline)
{
	char	*fstr;

	fstr = ft_strjoin(fline, line);
	free(line);
	free (fline);
	fline = fstr;
	if (!fline)
		return (ft_error_char("Error: malloc failed"));
	return (fline);
}

char	**putmap(int fd, char *fline)
{
	int		t;
	int		temp;
	char	*line;
	char	**map_temp;

	t = 0;
	temp = 1;
	line = 0;
	while (line || temp)
	{
		temp = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		fline = putmap2(line, fline);
		if (!fline)
			return (NULL);
	}
	map_temp = ft_split_cub(fline, '\n');
	free(fline);
	if (!map_temp)
		return (ft_error_char("Error: malloc failed"));
	return (map_temp);
}

int	verif_info(t_libx *libx, char *line)
{
	if (!libx->txtr_w_north || !libx->txtr_w_south
		|| !libx->txtr_w_west || !libx->txtr_w_east)
	{
		free(line);
		return (0);
	}
	if (libx->texture_floor < 0 || libx->texture_ceiling < 0)
	{
		free(line);
		return (0);
	}
	return (1);
}

char	**search_map_info(int fd, t_data *data, char **info)
{
	char	*line;
	int		ismap;
	char	**map_temp;

	ismap = 1;
	while (ismap >= 0)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_error_char("Error: miss information"));
		ismap = put_info(line, info, ismap, data);
		if (ismap >= 0 || ismap == -2)
			free(line);
		if (ismap == -2)
			return (NULL);
	}
	if (!verif_info(data->libx, line))
		return (ft_error_char("Error: miss information"));
	map_temp = putmap(fd, line);
	if (!map_temp)
		return (NULL);
	return (map_temp);
}
