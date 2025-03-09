#include "../so_long.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// void	get_pos(t_list *map, char s)
// {
// 	t_list *head;
// 	int i;
// 	int j;
// 	my_pos position;

// 	j = 0;
// 	head = map;
// 	while (map)
// 	{
// 		i = 0;
// 		while (head->data[i])
// 		{
// 			if (head->data[i] == s)
// 			{
// 				position.x = i;
// 				position.y = j;
// 				return ;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// }

void	disp_window(mlx_t* mlx, t_list *map, my_img img)
{
	int i;
	int j;

	j = 0;
	while (map)
	{
		i = 0;
		while (map->data[i])
		{
			if (map->data[i] == '0')
				mlx_image_to_window(mlx, img.ground, i	* 64, j	* 64);
			else if (map->data[i] == '1')
				mlx_image_to_window(mlx, img.wall, i * 64, j * 64);
			else if (map->data[i] == 'C')
				mlx_image_to_window(mlx, img.coin, i * 64, j * 64);
			else if (map->data[i] == 'E')
				mlx_image_to_window(mlx, img.exit, i * 64, j * 64);
			else if (map->data[i] == 'P')
				mlx_image_to_window(mlx, img.player, i * 64, j * 64);
			i++;
		}
		j++;
		map = map->next;
	}
}

void	my_path(mlx_t *mlx, t_list *map)
{
	my_text texture;
	my_img img;

	texture.coin = mlx_load_png("./img/coin.png");
	img.coin = mlx_texture_to_image(mlx, texture.coin);

	texture.ground = mlx_load_png("./img/ground.png");
	img.ground = mlx_texture_to_image(mlx, texture.ground);
	
	texture.exit = mlx_load_png("./img/exit.png");
	img.exit = mlx_texture_to_image(mlx, texture.exit);

	texture.wall = mlx_load_png("./img/wall.png");
	img.wall = mlx_texture_to_image(mlx, texture.wall);

	texture.player = mlx_load_png("./img/player.png");
	img.player = mlx_texture_to_image(mlx, texture.player);
	
	disp_window(mlx, map, img);
}


// check_render(mlx, head, '0');
// check_render(mlx, head, 'C');
// check_render(mlx, head, 'E');
// check_render(mlx, head, 'P');
// void	check_render(mlx_t* mlx, t_list *map, char s)
// {
// 	my_img img;
// 	my_text texture;
// 	my_pos position;

// 	get_pos(map, s);
// 	mlx_image_to_window(mlx, , position.x, position.y);
// }


void    init(t_list *map)
{
    mlx_t* mlx;
	// my_text texture;
	// my_img img;

    mlx = mlx_init(WIDTH * ft_len(map->data), HEIGHT * ft_lstsize(map), "test game", false);
    if (!mlx)
	    ft_error();
	my_path(mlx, map);
	

	mlx_loop(mlx);
    // mlx_loop(mlx);
}
