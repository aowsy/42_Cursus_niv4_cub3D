/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:12:20 by mdelforg          #+#    #+#             */
/*   Updated: 2022/06/23 14:59:45 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <float.h>
# include <stdlib.h>
# include <mlx.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MOVE 0.1
# define TURN 0.03
# define WALL 64			// 256
# define W_NORTH "../Textures/Stone3.xpm"
# define W_SOUTH "../Textures/stone.xpm"
# define W_WEST "../Textures/brick.xpm"
# define W_EAST "../Textures/metal.xpm"

/*
typedef struct s_cast
{
	double	pos_x;					// position de depart en x
	double	pos_y;
	double	dir_x;					// direction de depart en x
	double	dir_y;
	double	plane_x;				// demi-largeur du plan de focale en x
	double	plane_y;
	double	camera_x;				// coordonnee sur le plan de focale (entre -1 et 1)
	double	raydir_x;				// direction d'un rayon en x
	double	raydir_y;
	int		map_x;					// care dans lequel on se trouve en x
	int		map_y;
	double	side_x;					// distance entre le depart et la 1ere arrete en x
	double	side_y;
	double	delta_x;				// distance pour franchir 1 unite de x
	double	delta_y;
	int		step_x;					// savoir si le rayon en x est + ou - (-1 ou 1)
	int		step_y;
	double	perp;					// distance perpendiculaire du rayon
	int		hit;					// savoir si un mur est atteint
	int		side_wall;				// savoir si c'est un mur en x (0) ou en y (1) qui a ete touche
	int		line_height;			// hauteur du mur en perspective
	int		draw_start;				// arrete basse du mur
	int		draw_end;				// arrete haute du mur
} t_cast;
*/

typedef struct s_rcst
{
	double	camera_x;				// coordonnee sur le plan de focale (entre -1 et 1)
	double	raydir_x;				// direction d'un rayon en x
	double	raydir_y;
	int		map_x;					// care dans lequel on se trouve en x
	int		map_y;
	double	side_x;					// distance entre le depart et la 1ere arrete en x
	double	side_y;
	double	delta_x;				// distance pour franchir 1 unite de x
	double	delta_y;
	int		step_x;					// savoir si le rayon en x est + ou - (-1 ou 1)
	int		step_y;
	double	perp;					// distance perpendiculaire du rayon
	int		hit;					// savoir si un mur est atteint
	int		face_wall;				// savoir si c'est un mur en x (0) ou en y (1) qui a ete touche
	int		line_height;			// hauteur du mur en perspective
	int		draw_start;				// arrete basse du mur
	int		draw_end;				// arrete haute du mur
} t_rcst;

typedef struct s_hero
{
	double	pos_x;					// position de depart en x
	double	pos_y;
	double	dir_x;					// direction de depart en x
	double	dir_y;
	double	plane_x;				// demi-largeur du plan de focale en x
	double	plane_y;
} t_hero;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_ppxl;
	int		sz_line;
	int		endian;
} t_img;

typedef struct s_libx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*n;
	void	*s;
	void	*w;
	void	*e;
	t_img	*img;
} t_libx;

typedef struct s_move
{
	int		forward;
	int		back;
	int		left;
	int		right;
} t_move;

typedef struct s_data
{
	char	**map;
	t_hero	*hero;
	t_move	*move;
	t_libx	*libx;
	t_img	*img;
} t_data;

/*					init.c						*/
void	ft_hero_init(t_hero *hero);
void	ft_move_init(t_move *move);

/*					raycast.c					*/
int		ft_raycast(t_data *data);

/*					keyhook.c					*/
int		ft_keyhook(int keycode, t_data *data);
int		ft_key_press(int keycode, t_move *move);
int		ft_key_release(int keycode, t_move *move);
void	ft_move_player(int type, t_data *data, t_hero *hero);
void	ft_turn_player(int type, t_data *data, t_hero *hero);
/*					texturing.c					*/
void	ft_put_texture(int x, t_rcst *rcst, t_libx *libx, t_img *img);

#endif
