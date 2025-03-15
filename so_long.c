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
#include <string.h>
int	check_file(char *s)
{
	int j = strlen(s);
	
	while (j > 0)
	{
		if (s[j] == '/' && s[j + 1] == '.')
			return (1);
		j--;
	}
	return (0);
}

int	name_file(char *s)
{
	int i;
	int j;
	int c;
	// int v = 0;
	char *name;
	c = 0;
	i = 0;
	name = ".ber";

	while (s[i])
	{
		j = 0;
		while (name[j])
		{
			if (name[j] == s[i])
				c++;
			j++;
		}
		i++;
	}
	// printf("j >> %d\n", j);
	// printf("i , c >> %d %d\n", i, c);
	// printf("[%c]", s[c - i + 4]);
	// printf("s > [%c]\n", s[i - 1]);
	// printf("name > [%c]\n", name[j - 1]);
	if (name[j - 1] != s[i - 1])
	{
		write(1, "Error\n", 7);
		exit(1);
	}
		
	return (c);
}

void	f()
{
	system("leaks -q so_long");
}

int main(int ac, char *av[])
{
	// atexit(f);
	if (ac == 2 && name_file(av[1]) == 4)
	{	
		if (check_file(av[1]) == 1 || strlen(av[1]) < 5)
			return (write(1, "Error\n", 7), 1);
			
		t_list *head = NULL;
		init_map(&head, av[1]);
		if (!head)
			return (1);
		if (valid_map(head) == 1 || check_pos(head) == 1)
			return (freelist(&head), 1);
		
		init(head);
		freelist(&head);
		
	}
	else
		return (write(1, "Error\n", 7), 1);
}
