#include "../so_long.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	disp_player(mlx_t* mlx, t_list *map, my_img img)
{
	int i;
	int j;

	j = 0;
	while (map)
	{
		i = 0;
		while (map->data[i])
		{
			if (map->data[i] == 'P')
				mlx_image_to_window(mlx, img.player, i * 64, j * 64);
			i++;
		}
		j++;
		map = map->next;
	}
}

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
			 if (map->data[i] == '1')
				mlx_image_to_window(mlx, img.wall, i * 64, j * 64);
			else if (map->data[i] == 'C')
				mlx_image_to_window(mlx, img.coin, i * 64, j * 64);
			else if (map->data[i] == 'E')
				mlx_image_to_window(mlx, img.exit, i * 64, j * 64);
			i++;
		}
		j++;
		map = map->next;
	}
}

my_img	my_path(mlx_t *mlx)
{
	my_text texture;
	my_img img;

	texture.coin = mlx_load_png("./textures/coin.png");
	img.coin = mlx_texture_to_image(mlx, texture.coin);

	texture.exit = mlx_load_png("./textures/exit.png");
	img.exit = mlx_texture_to_image(mlx, texture.exit);

	texture.wall = mlx_load_png("./textures/wall.png");
	img.wall = mlx_texture_to_image(mlx, texture.wall);

	texture.player = mlx_load_png("./textures/player.png");
	img.player = mlx_texture_to_image(mlx, texture.player);
	
	mlx_delete_texture(texture.coin);
	mlx_delete_texture(texture.exit);
	mlx_delete_texture(texture.wall);
	mlx_delete_texture(texture.player);
	
	return (img);
}

void    init(t_list *map)
{
    mlx_t* mlx;
	my_data smih;

    mlx = mlx_init(WIDTH * ft_len(map->data), HEIGHT * ft_lstsize(map), "so_long", false);
    if (!mlx)
	    ft_error();
	smih.img = my_path(mlx);
   	smih.m = copy_map(map);
	smih.mlx = mlx;

	disp_window(mlx, map, smih.img);
	disp_player(mlx, map, smih.img);

	mlx_key_hook(mlx, &check_hooks, &smih);
	mlx_loop(mlx);
	tacos(smih.m);
	mlx_terminate(mlx);
	
}
