/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:43:00 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/16 13:54:12 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	f_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	name_file(char *s)
{
	int		i;
	int		j;
	int		c;
	char	*name;

	i = f_strlen(s) - 1;
	j = 3;
	c = 0;
	name = ".ber";
	while (j >= 0 && s[i] == name[j])
	{
		c++;
		i--;
		j--;
	}
	return (c);
}

int	check_name(char *s)
{
	int	i;

	i = f_strlen(s) - 1;
	while (i > 0 && s[i] != '/')
		i--;
	if (s[i + 1] == '.')
		return (1);
	return (0);
}
