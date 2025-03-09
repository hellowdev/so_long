#include "so_long.h"
#include "./get_next_line/get_next_line.h"

void	tacos(char **s)
{
	int i;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	ft_len(char *str)
{
	int i;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
void	freelist(t_list **map)
{
	t_list *head;
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
	int fd;
	char *line;
	t_list *new;

	fd = open(av, O_RDONLY, 0777);
	while (fd != -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = ft_lstnew(line);
		if (!new)
			return (freelist(list));
		ft_lstadd_back(list, new);
	}
}

// void	f()
// {
// 	system("leaks -q so_long");
// }

int main(int ac, char *av[])
{
	// atexit(f);
	if (ac == 2)
	{
		t_list *head = NULL;
		init_map(&head, av[1]);
		if (!head)
			return (1);
		if (valid_map(head) == 1 || check_pos(head) == 1)
			return (freelist(&head), 1);
		// freelist(&head);
		init(head);
	}
}
