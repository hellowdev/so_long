/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:37:45 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/16 14:50:20 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	disp_player(mlx_t *mlx, t_list *map, t_my_img img)
{
	int	i;
	int	j;

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

void	check_instances(t_my_data *str, int y, int x)
{
	size_t			i;
	static size_t	j;

	i = 0;
	while (i < str->img.coin->count)
	{
		if (str->img.coin->instances[i].x == str->img.player->instances[0].x \
		&& str->img.coin->instances[i].y == str->img.player->instances[0].y)
		{
			str->img.coin->instances[i].enabled = false;
			str->m[y][x] = '0';
			j++;
			break ;
		}
		i++;
	}
	if (str->m[y][x] == 'E' && str->img.coin->count == j \
	&& str->img.exit->instances[0].x == str->img.player->instances[0].x \
		&& str->img.exit->instances[0].y == str->img.player->instances[0].y)
		mlx_close_window(str->mlx);
}

void	calcule_moves(mlx_key_data_t keydata, t_my_data *str)
{
	static int	m;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(str->mlx);
	if (((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS \
	&& str->m[str->y + 1][str->x] != '1') \
	|| (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS \
	&& str->m[str->y - 1][str->x] != '1') \
	|| (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS \
	&& str->m[str->y][str->x - 1] != '1') \
	|| (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS \
	&& str->m[str->y][str->x + 1] != '1')))
	{
		ft_putnbr(++m);
		write(1, "\n", 1);
	}
}

void	check_hooks(mlx_key_data_t keydata, void *param)
{
	t_my_data	*str;

	str = (t_my_data *)param;
	str->y = str->img.player->instances[0].y / 64;
	str->x = str->img.player->instances[0].x / 64;
	move_down(str, str->y + 1, str->x, keydata);
	move_up(str, str->y - 1, str->x, keydata);
	move_left(str, str->y, str->x - 1, keydata);
	move_right(str, str->y, str->x + 1, keydata);
	calcule_moves(keydata, str);
}
