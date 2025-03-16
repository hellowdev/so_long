/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:42:16 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/16 00:23:00 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_my_data *str, int y, int x, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS \
	&& str->m[str->y - 1][str->x] != '1')
	{
		str->img.player->instances[0].y -= (64);
		if (str->m[y][x] == 'C' || str->m[y][x] == 'E')
			check_instances(str, y, x);
	}
}

void	move_left(t_my_data *str, int y, int x, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS \
	&& str->m[str->y][str->x - 1] != '1')
	{
		str->img.player->instances[0].x -= (64);
		if (str->m[y][x] == 'C' || str->m[y][x] == 'E')
			check_instances(str, y, x);
	}
}

void	move_right(t_my_data *str, int y, int x, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS \
	&& str->m[str->y][str->x + 1] != '1')
	{
		str->img.player->instances[0].x += (64);
		if (str->m[y][x] == 'C' || str->m[y][x] == 'E')
			check_instances(str, y, x);
	}
}

void	move_down(t_my_data *str, int y, int x, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS \
	&& str->m[str->y + 1][str->x] != '1')
	{
		str->img.player->instances[0].y += (64);
		if (str->m[y][x] == 'C' || str->m[y][x] == 'E')
			check_instances(str, y, x);
	}
}
