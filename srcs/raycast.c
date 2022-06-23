/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:48:02 by mdelforg          #+#    #+#             */
/*   Updated: 2022/06/23 15:00:13 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include "so_long/so_long.h"
//				retirer so_long.h

void	ft_camera_init(t_rcst *rcst)
{
	rcst->line_height = (int)(HEIGHT / rcst->perp);
	rcst->draw_start = (-(rcst->line_height) / 2) + (HEIGHT / 2);
	if (rcst->draw_start < 0)
		rcst->draw_start = 0;
	rcst->draw_end = (rcst->line_height / 2) + (HEIGHT / 2);
	if (rcst->draw_end >= HEIGHT)
		rcst->draw_end = HEIGHT - 1;
	return ;
}

void	ft_rcst_trace(t_rcst *rcst, t_data *data)
{
	while (!(rcst->hit))
	{
		if (rcst->side_x < rcst->side_y)
		{
			rcst->side_x += rcst->delta_x;
			rcst->map_x += rcst->step_x;
			rcst->face_wall = 0;
		}
		else
		{
			rcst->side_y += rcst->delta_y;
			rcst->map_y += rcst->step_y;
			rcst->face_wall = 1;
		}
		if (data->map[rcst->map_y][rcst->map_x] > '0')							// j'ai inverse le x et le y
			rcst->hit = 1;
	}

	if (!(rcst->face_wall))
		rcst->perp = (rcst->side_x - rcst->delta_x);							// pas confiance en la formule
	else
		rcst->perp = (rcst->side_y - rcst->delta_y);
	return ;
}

void	ft_rcst_side(t_rcst *rcst, t_hero *hero)
{
	if (rcst->raydir_x < 0)
	{
		rcst->step_x = -1;
		rcst->side_x = (hero->pos_x - rcst->map_x) * rcst->delta_x;
	}
	else
	{
		rcst->step_x = 1;
		rcst->side_x = (rcst->map_x + 1.0 - hero->pos_x) * rcst->delta_x;
	}
	if (rcst->raydir_y < 0)
	{
		rcst->step_y = -1;
		rcst->side_y = (hero->pos_y - rcst->map_y) * rcst->delta_y;
	}
	else
	{
		rcst->step_y = 1;
		rcst->side_y = (rcst->map_y + 1.0 - hero->pos_y) * rcst->delta_y;
	}
	return ;
}

void	ft_rcst_delta(t_rcst *rcst)
{
	if (!(rcst->raydir_x))
		rcst->delta_x = DBL_MAX;												// convertis le 1/30
	else
		rcst->delta_x = sqrt(1.0 + ((rcst->raydir_y * rcst->raydir_y)
			/ (rcst->raydir_x * rcst->raydir_x)));								// autre formule
	if (!(rcst->raydir_y))
		rcst->delta_y = DBL_MAX;
	else
		rcst->delta_y = sqrt(1.0 + ((rcst->raydir_x * rcst->raydir_x)
			/ (rcst->raydir_y * rcst->raydir_y)));
	return ;
}

void	ft_rcst_init(int x, t_hero *hero, t_rcst *rcst)
{
	rcst->camera_x = 2 * (double)x / (double)WIDTH - (double)1;
	rcst->raydir_x = hero->dir_x + hero->plane_x * rcst->camera_x;
	rcst->raydir_y = hero->dir_y + hero->plane_y * rcst->camera_x;

	rcst->map_x = (int)hero->pos_x;
	rcst->map_y = (int)hero->pos_y;

	rcst->hit = 0;
	return ;
}

int	ft_raycast(t_data *data)
{
	int		x;
	t_rcst	rcst;
	t_hero	*hero;
	t_libx	*libx;
	t_img	*img;

	hero = data->hero;
	libx = data->libx;
	img = libx->img;
	int width = WIDTH;
	int height = HEIGHT;
	img->ptr = mlx_new_image(libx->mlx_ptr, 1920, 1080);
	x = 0;
	while (x < WIDTH)
	{
		ft_rcst_init(x, hero, &rcst);
		ft_rcst_delta(&rcst);
		ft_rcst_side(&rcst, hero);
		ft_rcst_trace(&rcst, data);
		ft_camera_init(&rcst);
		ft_put_texture(x, &rcst, libx, img);
		x++;
	}
	mlx_put_image_to_window(libx->mlx_ptr, libx->mlx_win, img->ptr, 0, 0);
	return (0);
}



// printf("pos_x = %lf\npos_y = %lf\ndir_x = %lf\ndir_y = %lf\ncamera_x = %lf\nraydir_x = %lf\nraydir_y = %lf\nmap_x = %d\nmap_y = %d\nside_x = %lf\nside_y = %lf\ndelta_x = %lf\ndelta_y = %lf\nstep_x = %d\nstep_y = %d\nperp = %lf\nhit = %d\nface_wall = %d\nline_height = %d\ndraw_start = %d\ndraw_end = %d\n\n\n", hero->pos_x, hero->pos_y, hero->dir_x, hero->dir_y, rcst.camera_x, rcst.raydir_x, rcst.raydir_y, rcst.map_x, rcst.map_y, rcst.side_x, rcst.side_y, rcst.delta_x, rcst.delta_y, rcst.step_x, rcst.step_y, rcst.perp, rcst.hit, rcst.face_wall, rcst.line_height, rcst.draw_start, rcst.draw_end);	// side_x
