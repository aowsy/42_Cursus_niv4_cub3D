/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:55:09 by mdelforg          #+#    #+#             */
/*   Updated: 2022/06/21 23:03:36 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_turn_player(int type, t_data *data, t_hero *hero)
{																	// inverse lorsqu-on change pos_x
	double	old_dir;
	double	old_plane;

	if (type == 1)
	{
		old_dir = hero->dir_x;
		hero->dir_x = (old_dir * cos(TURN)) - (hero->dir_y * sin(TURN));
		hero->dir_y = (old_dir * sin(TURN)) + (hero->dir_y * cos(TURN));
		old_plane = hero->plane_x;
		hero->plane_x = (old_plane * cos(TURN)) - (hero->plane_y * sin(TURN));
		hero->plane_y = (old_plane * sin(TURN)) + (hero->plane_y * cos(TURN));
	}
	else if (type == 2)
	{
		old_dir = hero->dir_x;
		hero->dir_x = (old_dir * cos(-TURN)) - (hero->dir_y * sin(-TURN));
		hero->dir_y = (old_dir * sin(-TURN)) + (hero->dir_y * cos(-TURN));
		old_plane = hero->plane_x;
		hero->plane_x = (old_plane * cos(-TURN)) - (hero->plane_y * sin(-TURN));
		hero->plane_y = (old_plane * sin(-TURN)) + (hero->plane_y * cos(-TURN));
	}
	ft_raycast(data);					// faire un mlx_clear_window avant
	return ;
}

void	ft_move_player(int type, t_data *data, t_hero *hero)
{
	if (type == 1)
	{
		hero->pos_x += hero->dir_x * MOVE;
		hero->pos_y += hero->dir_y * MOVE;
	}
	else if (type == 2)
	{
		hero->pos_x -= hero->dir_x * MOVE;
		hero->pos_y -= hero->dir_y * MOVE;
	}
	ft_raycast(data);					// faire un mlx_clear_window avant
	return ;
}

int	ft_keyhook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);												// ft_close
	else if (keycode == 13)
		ft_move_player(1, data, data->hero);
	else if (keycode == 1)
		ft_move_player(2, data, data->hero);
	else if (keycode == 0)
		ft_turn_player(1, data, data->hero);
	else if (keycode == 2)
		ft_turn_player(2, data, data->hero);
	return (0);
}

int	ft_key_press(int keycode, t_move *move)
{
	if (keycode == 53)
		exit(0);												// ft_close
	if (keycode == 13)
		move->forward = 1;
	if (keycode == 1)
		move->back = 1;
	if (keycode == 0)
		move->left = 1;
	if (keycode == 2)
		move->right = 1;
	return (0);
}

int	ft_key_release(int keycode, t_move *move)
{
	if (keycode == 53)											// pas besoin dans le release
		exit(0);												// ft_close
	if (keycode == 13)
		move->forward = 0;
	if (keycode == 1)
		move->back = 0;
	if (keycode == 0)
		move->left = 0;
	if (keycode == 2)
		move->right = 0;
	return (0);
}
