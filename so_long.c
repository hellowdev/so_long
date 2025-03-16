/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:25:43 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/16 15:06:29 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"

void	tacos(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	freelist(t_list **map)
{
	t_list	*head;

	head = (*map);
	while (head)
	{
		head = head->next;
		free((*map)->data);
		free(*map);
		*map = head;
	}
}

void	init_map(t_list **list, char *av)
{
	int		fd;
	char	*line;
	t_list	*new;

	fd = open(av, O_RDONLY, 0777);
	while (fd != -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = ft_lstnew(line);
		if (!new)
		{
			get_next_line(-1);
			close (fd);
			return (freelist(list));
		}
		ft_lstadd_back(list, new);
	}
	get_next_line(-1);
	close (fd);
}

int	main(int ac, char *av[])
{
	t_list	*head;
	t_list	*lst;

	if (ac == 2)
	{
		if ((check_name(av[1]) == 1 || av[1][0] == '.' \
		|| name_file(av[1]) != 4))
			return (write(2, "Not a Valid Argument\n", 22), 1);
		head = NULL;
		init_map(&head, av[1]);
		if (!head)
			return (write(2, "File not exist or empty\n", 25), 1);
		if (ft_len(head->data) > 40 || ft_lstsize(head) > 22)
			return (write(2, "Map Too Large\n", 15), 1);
		lst = head;
		if (valid_map(head) == 1 || check_pos(head, lst) == 1)
			return (freelist(&head), 1);
		init(head);
		freelist(&head);
	}
	else
		return (write(2, "Missed map Argument\n", 21), 1);
}
