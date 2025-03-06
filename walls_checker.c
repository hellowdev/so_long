#include "so_long.h"

int	lenmap(t_list *p)
{
	t_list *head;
	
	head = p;
	while (head)
	{
		p = head->next;
		while (p)
		{
			if (ft_len(p->data) != ft_len(head->data))
				return (1);
			p = p->next;
		}
		head = head->next;
	}
	return (0);
}

int	first_wall(t_list *map)
{
	int i;
	i = 0;
	
	while (map->data[i] == '1')
	{
		if (map->data[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}
int	last_wall(t_list *map)
{
	int i;
	i = 0;

	map = ft_lstlast(map);
	while (map->data[i] && map->data[i] == '1')
	{
		if (!map->data[i + 1] || map->data[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	else_walls(t_list *map)
{
	int i;
	i = 0;
	int j = 0;
	map = map->next;

	while (map && map->next)
	{
		if (map->data[0] == '1')
		{
			i = 0;
			while (map->data[i])
			{
				if (map->data[i] != '1' && map->data[i + 1] == '\n')
					return (1);
			i++;
			}
		}
		else
			return (1);
		j++;
		map = map->next;
	}
	
	return (0);
}

int	walls(t_list *map)
{
	if (lenmap(map) == 1)
	{
		write(2, "Error\n", 6);
		return (write (2, "The map is not rectangular !\n", 30), 1);
	}
	else if (first_wall(map) == 1)
	{
		write(2, "Error\n", 6);
		return (write (2, "The upper wall is broken !\n", 28), 1);
	}
	else if (last_wall(map) == 1)
	{
		write(2, "Error\n", 6);
		return (write (2, "The bottom wall is broken !\n", 29), 1);
	}
	else if (else_walls(map) == 1)
	{
		write(2, "Error\n", 6);
		return (write(2, "The side wall is broken !\n", 27), 1);
	}
	return (0);
}
