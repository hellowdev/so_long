/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:26:44 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/05 21:40:54 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_other(t_list *map)
{
    int i;

    while (map)
    {
        i = 0;
        while (map->data[i])
        {
            if (map->data[i] != '1' && map->data[i] != '0' && map->data[i] != 'C' \
			&& map->data[i] != 'E' && map->data[i] != 'P' && map->data[i] != '\n')
                return (write(2, "Error\n", 7), 1);
        	i++;
        }
		map = map->next;
    }
    return (0);
}

int	countpec(t_list *map, char p)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (map)
	{
		i = 0;
		while (map->data[i])
		{
			if (map->data[i] == p)
				j++;
		i++;
		}
	map = map->next;
	}
	return (j);
}
int	checkdb(t_list *map)
{
	
	if (countpec(map, 'P') != 1)
	{
		write(2, "Error\n", 7);
		write(1, "Player Not Valid !\n", 20);
		return (1);
	}
	if (countpec(map, 'E') != 1)
	{
		write(2, "Error\n", 7);
		write(1, "Exit Not Valid !\n", 18);
		return (1);
	}
	if (countpec(map, 'C') < 1)
	{
		write(2, "Error\n", 7);
		write(1, "Collectable Not Valid !\n", 25);
		return (1);
	}
		return (0);
}

int	valid_map(t_list *map)
{
	if (check_other(map) == 1 || walls(map) == 1 || checkdb(map) == 1)
		return (1);
	return (0);
}
