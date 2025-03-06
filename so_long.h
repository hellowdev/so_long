#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int		c;
	int		e;
	char	*data;

	struct	s_list *next;
}	t_list;

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int	ft_len(char *str);
// walls checker //
int	first_wall(t_list *map);
int	last_wall(t_list *map);
int	else_walls(t_list *map);
int	lenmap(t_list *p);
int	walls(t_list *map);
// -------- //
int	countpec(t_list *map, char p);
////////////
int check_other(t_list *map);
int	checkdb(t_list *map);
// -- valid map -- 
int	valid_map(t_list *map);
// --------+++++++++----------
char	**copy_map(t_list *map);
int		check_pos(t_list *map);
void	fill(char **tab, int x, int y);
t_list 	flood_fill(char **tab, int x, int y);
void	tacos(char **s);
#endif