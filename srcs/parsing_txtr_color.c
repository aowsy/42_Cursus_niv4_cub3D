/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_txtr_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:29:24 by tluu              #+#    #+#             */
/*   Updated: 2022/09/28 18:32:07 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	put_texture(char *path, char **texture)
{
	*texture = ft_strtrim(path, "\n");
	if (!*texture)
		return (0);
	return (1);
}

unsigned int	parse_color(char **color_split)
{
	int				is_false;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	if (!verif_is_digit(color_split))
		return (-1);
	red = ft_atoi_v(color_split[0], &is_false);
	if (red > 255 || is_false == 1)
		return (-1);
	green = ft_atoi_v(color_split[1], &is_false);
	if (green > 255 || is_false == 1)
		return (-1);
	blue = ft_atoi_v(color_split[2], &is_false);
	if (blue > 255 || is_false == 1)
		return (-1);
	return ((red * 256 * 256) + (green * 256) + blue);
}

int	put_color(char *color_rgb, int *color)
{
	char	**color_split;

	if (nword(color_rgb, ',') != 3 || count_char(color_rgb, ',' != 2))
		return (ft_error_int("Error: wrong arg for color", 0));
	color_split = ft_split(color_rgb, ',');
	if (!color_split)
		return (ft_error_int("Error: malloc failed", 0));
	*color = parse_color(color_split);
	if (*color < 0)
	{
		free_split(color_split);
		return (ft_error_int("Error: wrong arg for color", 0));
	}
	free_split(color_split);
	return (1);
}

int	parse_texture(char *newline, char *line, char *i, t_libx *lx)
{
	int		temp;

	temp = -10;
	if (nword(line, 32) != 2)
		return (0);
	if (!ft_strncmp(i, "NO", 3) && !lx->txtr_w_north)
		temp = put_texture(newline, &lx->txtr_w_north);
	if (!ft_strncmp(i, "SO", 3) && !lx->txtr_w_south)
		temp = put_texture(newline, &lx->txtr_w_south);
	if (!ft_strncmp(i, "WE", 3) && !lx->txtr_w_west)
		temp = put_texture(newline, &lx->txtr_w_west);
	if (!ft_strncmp(i, "EA", 3) && !lx->txtr_w_east)
		temp = put_texture(newline, &lx->txtr_w_east);
	if (!ft_strncmp(i, "F", 2) && lx->texture_floor == -1)
		temp = put_color(newline, &lx->texture_floor);
	if (!ft_strncmp(i, "C", 2) && lx->texture_ceiling == -1)
		temp = put_color(newline, &lx->texture_ceiling);
	if (temp == -10)
		return (ft_error_int("Error: information", 0));
	if (!temp)
		return (0);
	return (1);
}

int	put_hero(t_data *data, t_hero *hero, int i, int j)
{
	double	dir_x;
	double	dir_y;

	dir_x = 1;
	dir_y = 1;
	if (!verifset(data->map[i][j], "NESW"))
		return (0);
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S')
		dir_x = 0.0;
	if (data->map[i][j] == 'W' || data->map[i][j] == 'E')
		dir_y = 0.0;
	if (data->map[i][j] == 'S')
		dir_y = -1.0;
	if (data->map[i][j] == 'W')
		dir_x = -1.0;
	hero->pos_x = (double)j + 0.5;
	hero->pos_y = (double)i + 0.5;
	hero->dir_x = 1.0 * dir_x;
	hero->dir_y = 1.0 * dir_y;
	hero->plane_x = 0.66 * dir_y;
	hero->plane_y = -0.66 * dir_x;
	data->hero = hero;
	data->map[i][j] = '0';
	return (1);
}
