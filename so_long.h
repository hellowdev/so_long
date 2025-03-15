#ifndef SO_LONG_H
#define SO_LONG_H

#include "MLX42/MLX42.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 64
#define HEIGHT 64

typedef struct s_list
{
    int		c;
	int		e;
	char	*data;
	struct	s_list *next;
}	t_list;

typedef struct s_txt
{
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*player;
	mlx_texture_t	*ground;
	mlx_texture_t	*exit;
}	my_text;

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*coin;
	mlx_image_t	*player;
	mlx_image_t	*ground;
	mlx_image_t	*exit;
}	my_img;

typedef struct hook_str
{
	char	**m;
	mlx_t	*mlx;
	my_img	img;
	int		y;
	int		x;
	int		total;	
}	my_data;


t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int	ft_len(char *str);
// walls checker //
int	first_wall(t_list *map);
int	last_wall(t_list *map);
int	else_walls(t_list *map);
int	lenmap(t_list *p);
int	walls(t_list *map);
// -------- //
int	countpec(t_list *map, char p);
////////////
int check_other(t_list *map);
int	checkdb(t_list *map);
// -- valid map -- 
int	valid_map(t_list *map);
// --------+++++++++----------
char	**copy_map(t_list *map);
int		check_pos(t_list *map);
void	fill(char **tab, int x, int y);
t_list 	flood_fill(char **tab, int x, int y);
void	tacos(char **s);
//////////////game 
void    init(t_list *map);

void	disp_window(mlx_t* mlx, t_list *map, my_img);
void	disp_player(mlx_t* mlx, t_list *map, my_img img);
my_img	my_path(mlx_t *mlx);
// MOVES --------->
void 	check_hooks(mlx_key_data_t keydata, void *param);
void	check_instances(my_data *str, int y, int x);
void	move_up(my_data *str, int y, int x, mlx_key_data_t keydata);
void	move_left(my_data *str, int y, int x, mlx_key_data_t keydata);
void	move_right(my_data *str, int y, int x, mlx_key_data_t keydata);
void	move_down(my_data *str, int y, int x, mlx_key_data_t keydata);
void	calcule_moves(mlx_key_data_t keydata, my_data *str);
void	ft_putnbr(int nb);

#endif