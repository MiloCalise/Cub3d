/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:11:39 by miltavar          #+#    #+#             */
/*   Updated: 2025/12/15 14:40:08 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	skip_whitespaces(char *s, int *i)
{
	if (!s || !s[*i])
		return ;
	while (s[*i])
	{
		if (is_whitespace(s[*i]))
			(*i)++;
		else
			return ;
	}
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}

int	check_c(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_whitespace(s[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

void	skip_space(int fd, char **temp)
{
	if (!temp || !*temp)
		return ;
	while (*temp)
	{
		if (check_c(*temp))
			return ;
		free(*temp);
		*temp = get_next_line(fd);
	}
}

int	is_invalid(char c)
{
	if (c != 'N' && c != 'W' && c != 'E'
		&& c != 'S' && c != '3' && c != '1' && c != '0')
		return (1);
	return (0);
}
