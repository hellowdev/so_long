#include "./so_long.h"


void	check_instances(my_data *str, int y, int x)
{
	size_t i;
	static size_t j;
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
	&& str->img.exit->instances[0].x == str->img.player->instances[0].x 
		&& str->img.exit->instances[0].y == str->img.player->instances[0].y)
			mlx_close_window(str->mlx);
}

void	ft_putnbr(int nb) 
{
	if (nb >= 10) 
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb += 48;
		write(1, &nb, 1);
	}
}

void	calcule_moves(mlx_key_data_t keydata, my_data *str)
{
	static int m;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(str->mlx);

	if (((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS 
	&& str->m[str->y + 1][str->x] != '1')
	|| (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
	&& str->m[str->y - 1][str->x] != '1')
	|| (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
	&& str->m[str->y][str->x - 1] != '1')
	|| (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS 
	&& str->m[str->y][str->x + 1] != '1')))
	{
		ft_putnbr(++m);
		write(1, "\n", 1);
	}
}
void check_hooks(mlx_key_data_t keydata, void *param)
{
    my_data *str;
	str = (my_data *)param;
	
	
	str->y = str->img.player->instances[0].y / 64;
	str->x = str->img.player->instances[0].x / 64;
	move_down(str, str->y + 1, str->x, keydata);
	move_up(str, str->y - 1, str->x, keydata);
	move_left(str, str->y, str->x - 1, keydata);
	move_right(str, str->y, str->x + 1, keydata);
	
	calcule_moves(keydata, str);
}



