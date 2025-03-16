/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:38:18 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/16 14:47:56 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_list *map)
{
	char	**p;
	int		j;
	int		i;
	int		size;

	j = 0;
	p = malloc((ft_lstsize(map) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	size = ft_lstsize(map);
	while (j < size)
	{
		i = -1;
		p[j] = malloc((ft_len(map->data) + 1) * sizeof(char));
		if (!p[j])
			return (tacos(p), NULL);
		while (++i < ft_len(map->data))
			p[j][i] = map->data[i];
		p[j][i] = '\0';
		map = map->next;
		j++;
	}
	p[j] = NULL;
	return (p);
}

int	check_pos(t_list *map, t_list *lst)
{
	int		i;
	int		j;
	t_list	t;
	char	**cp;

	j = 0;
	while (map)
	{
		i = -1;
		while (map->data[++i])
		{
			if (map->data[i] == 'P')
			{
				cp = copy_map(lst);
				if (!cp)
					return (1);
				t = flood_fill(cp, i, j);
			}
		}
		map = map->next;
		j++;
	}
	if (countpec(lst, 'C') != t.c || countpec(lst, 'E') != t.e)
		return (tacos(cp), write(2, "Error\nNot valid Path\n", 22), 1);
	return (tacos(cp), 0);
}

void	fill(char **tab, int x, int y)
{
	if (tab[y][x - 1] == '0' || tab[y][x - 1] == 'C' \
	|| tab[y][x - 1] == 'E')
		flood_fill(tab, x - 1, y);
	if (tab[y - 1][x] == '0' || tab[y - 1][x] == 'C' \
	|| tab[y - 1][x] == 'E')
		flood_fill(tab, x, y - 1);
	if (tab[y][x + 1] == '0' || tab[y][x + 1] == 'C' \
	|| tab[y][x + 1] == 'E')
		flood_fill(tab, x + 1, y);
	if (tab[y + 1][x] == '0' || tab[y + 1][x] == 'C' \
	|| tab[y + 1][x] == 'E')
		flood_fill(tab, x, y + 1);
}

t_list	flood_fill(char **tab, int x, int y)
{
	t_list		tacker;
	static int	c;
	static int	e;

	if (tab[y][x] == 'C')
		c++;
	if (tab[y][x] == 'E')
		e++;
	tab[y][x] = 'M';
	fill(tab, x, y);
	tacker.c = c;
	tacker.e = e;
	return (tacker);
}
