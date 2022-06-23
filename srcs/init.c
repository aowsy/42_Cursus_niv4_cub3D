/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:59:52 by mdelforg          #+#    #+#             */
/*   Updated: 2022/06/19 17:38:54 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_hero_init(t_hero *hero)
{
	hero->pos_x = 9.0;
	hero->pos_y = 2.5;
	hero->dir_x = -1.0;
	hero->dir_y = 0.0;
	hero->plane_x = 0.0;
	hero->plane_y = 0.66;
	return ;
}

void	ft_move_init(t_move *move)
{
	move->forward = 0;
	move->back = 0;
	move->left = 0;
	move->right = 0;
	return ;
}
