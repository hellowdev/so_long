/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:27:14 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/15 23:56:25 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	disp_window(mlx_t *mlx, t_list *map, t_my_img img)
{
	int	i;
	int	j;

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

t_my_img	text_to_wind(mlx_t *mlx, t_my_text texture)
{
	t_my_img	img;

	img.coin = mlx_texture_to_image(mlx, texture.coin);
	img.exit = mlx_texture_to_image(mlx, texture.exit);
	img.wall = mlx_texture_to_image(mlx, texture.wall);
	img.player = mlx_texture_to_image(mlx, texture.player);
	return (img);
}

t_my_text	my_path(void)
{
	t_my_text	texture;

	texture.coin = mlx_load_png("./textures/coin.png");
	texture.exit = mlx_load_png("./textures/exit.png");
	texture.wall = mlx_load_png("./textures/wall.png");
	texture.player = mlx_load_png("./textures/player.png");
	return (texture);
}

void	delete_text(t_my_text texture)
{
	if (texture.coin)
		mlx_delete_texture(texture.coin);
	if (texture.exit)
		mlx_delete_texture(texture.exit);
	if (texture.wall)
		mlx_delete_texture(texture.wall);
	if (texture.player)
		mlx_delete_texture(texture.player);
}

void	init(t_list *map)
{
	mlx_t		*mlx;
	t_my_data	smih;
	t_my_text	texture;

	mlx = mlx_init(WIDTH * ft_len(map->data), HEIGHT \
	* ft_lstsize(map), "so_long", false);
	if (!mlx)
		return ;
	smih.mlx = mlx;
	texture = my_path();
	if (!texture.coin || !texture.coin || !texture.player || !texture.wall)
		return (delete_text(texture));
	smih.img = text_to_wind(mlx, texture);
	delete_text(texture);
	smih.m = copy_map(map);
	if (!smih.m)
		return ;
	disp_window(mlx, map, smih.img);
	disp_player(mlx, map, smih.img);
	mlx_key_hook(mlx, &check_hooks, &smih);
	mlx_loop(mlx);
	tacos(smih.m);
	mlx_terminate(mlx);
}
