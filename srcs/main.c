/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:59:06 by mdelforg          #+#    #+#             */
/*   Updated: 2022/06/21 23:02:07 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include "so_long/so_long.h"

//	remettre les flags

int	ft_check_move(t_move *move, t_hero *hero)
{
	if (move->forward || move->back)
	{
		if (move->forward)
		{
			hero->pos_x += hero->dir_x * MOVE;
			hero->pos_y += hero->dir_y * MOVE;
		}
		if (move->back)
		{
			hero->pos_x -= hero->dir_x * MOVE;
			hero->pos_y -= hero->dir_y * MOVE;
		}
		return (1);
	}
	return (0);
}

/*
void	ft_get_image(t_libx *libx)
{
	int	*img_height;

	*img_height = WALL;
	libx->n = mlx_xpm_file_to_image(libx->mlx_ptr, W_NORTH, img_height, img_height);
	libx->s = mlx_xpm_file_to_image(libx->mlx_ptr, W_SOUTH, img_height, img_height);
	libx->w = mlx_xpm_file_to_image(libx->mlx_ptr, W_WEST, img_height, img_height);
	libx->e = mlx_xpm_file_to_image(libx->mlx_ptr, W_EAST, img_height, img_height);
	return ;
}
*/

void	ft_mlx_init(t_libx *libx)
{
	libx->mlx_ptr = mlx_init();
	libx->mlx_win = mlx_new_window(libx->mlx_ptr, WIDTH, HEIGHT, "oui");
//	libx->img.ptr = mlx_new_image(libx->mlx_ptr, libx->screen_width, libx->screen_height);
//	libx->img.address = mlx_get_data_addr(libx->img.ptr, &(libx->img.bits_ppxl), &(libx->img.sz_line), &(libx->img.endian));
//	ft_get_image(libx);
	return ;
}

/*
void	ft_textures()
{
	img->ptr = mlx_xpm_file_to_image(libx->mlx_ptr, file, img->size_x, img->size_y);
	img->address = mlx_get_data_addr(img->ptr, &(img->bits_ppxl), &(img->endian));
}
*/

int	main(int ac, char **av)
{
	t_data	data;
	t_hero	hero;
	t_move	move;
	t_libx	libx;
	t_img	img;

	data.map = ft_map_init(av[1]);
	ft_hero_init(&hero);
	data.hero = &hero;
	ft_move_init(&move);
	data.move = &move;
	ft_mlx_init(&libx);
	libx.img = &img;
	data.libx = &libx;
	data.img = &img;
//	ft_get_image(&libx);
	ft_raycast(&data);
	mlx_hook(libx.mlx_win, 2, 1L<<0, ft_keyhook, &data);
	mlx_hook(libx.mlx_win, 17, 0L, ft_close, &data);
//	mlx_hook(libx.mlx_win, 2, 1L<<0, ft_key_press, &data);
//	mlx_hook(libx.mlx_win, 3, 1L<<1, ft_key_release, &data);
//	mlx_loop_hook(libx.mlx, ft_raycast, &data);
//	mlx_do_key_autorepeatoff(libx.mlx);
	mlx_loop(libx.mlx_ptr);
	return (0);
}
