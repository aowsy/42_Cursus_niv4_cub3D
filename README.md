
typedef struct s_draw
{
	int		tex_x;					// coordonnee sur la texture en x
	int		tex_y;
	double	wall_x;					// coordonnee sur le mur en x
	double	step;					// coefficient a franchir pour chaque pixel
	double	tex_pos;				// coordonnee du depart de la texture
}	t_draw;

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
}	t_rcst;

typedef struct s_hero
{
	double	pos_x;					// position de depart en x
	double	pos_y;
	double	dir_x;					// direction de depart en x
	double	dir_y;
	double	plane_x;				// demi-largeur du plan de focale en x
	double	plane_y;
}	t_hero;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*addr;
	int		bits_ppxl;
	int		sz_line;
	int		endian;

}	t_img;

typedef struct s_libx
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_img			txtr[4];
	char			*txtr_w_north;
	char			*txtr_w_south;
	char			*txtr_w_east;
	char			*txtr_w_west;

	unsigned int	texture_floor;
	unsigned int	texture_ceiling;
	t_img			*img;
}	t_libx;

typedef struct s_move
{
	int		forward;
	int		back;
	int		left;
	int		right;
	int		turn_l;
	int		turn_r;
}	t_move;

typedef struct s_data
{
	char		**map;
	t_hero		*hero;
	t_move		*move;
	t_libx		*libx;
}	t_data;
