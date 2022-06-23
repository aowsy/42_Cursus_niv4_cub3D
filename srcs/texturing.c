/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:55:56 by mdelforg          #+#    #+#             */
/*   Updated: 2022/06/23 14:59:13 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_my_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->sz_line + x * (img->bits_ppxl / 8));
	*(unsigned int*)dst = color;
	return ;
}

int	ft_get_pixel(t_img *img, int x, int y)
{
	char	*ptr;

	ptr = img->addr + (y * img->sz_line + x * (img->bits_ppxl / 8));
	return (*(int*)ptr);
}

int	ft_get_texture(t_img *txtr, int x, int y, t_libx *libx)
{
	int	txtr_x;
	int	txtr_y;

	return (0x00FF0000);
}

void	ft_put_texture(int x, t_rcst *rcst, t_libx *libx, t_img *img)
{
	int y = 0;
	t_img txtr;

//	txtr->ptr = mlx_xpm_file_to_image(libx->mlx_ptr, W_NORTH, img_height, img_height);
//	txtr->addr = mlx_get_data_addr(txtr->ptr, &(txtr->bits_ppxl), &(txtr->sz_line), &(txtr->endian));
	while (y < HEIGHT)
	{
		img->addr = mlx_get_data_addr(img->ptr, &(img->bits_ppxl), &(img->sz_line), &(img->endian));
		if (y >= rcst->draw_start && y <= rcst->draw_end)
			ft_my_put_pixel(img, x, y, ft_get_texture(&txtr, x, y, libx));
		else if (y <= rcst->draw_start)
			ft_my_put_pixel(img, x, y, 0x0000FF00);
		else
			ft_my_put_pixel(img, x, y, 0x000000FF);
		y++;
	}
	return ;
}


//	creer 2 images a afficher consecutivement
//	destroy image
/*
void	ft_put_texture(int x, t_rcst *rcst, t_libx *libx)
{
	int y = 0;

	while (y < HEIGHT)
	{
		if (y >= rcst->draw_start && y <= rcst->draw_end)
			mlx_pixel_put(libx->mlx_ptr, libx->mlx_win, x, y, 0x00FF0000);		// remplacer par "WIDTH - x" pour inverser
		else if (y <= rcst->draw_start)
			mlx_pixel_put(libx->mlx_ptr, libx->mlx_win, x, y, 0x0000FF00);
		else
			mlx_pixel_put(libx->mlx_ptr, libx->mlx_win, x, y, 0x000000FF);
		y++;
	}
	return ;
}
*/
