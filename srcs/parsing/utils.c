/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:11:39 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/06 11:15:01 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

char	*skip_space(int fd, char *temp)
{
	while (temp)
	{
		if (check_c(temp))
			return (temp);
		free(temp);
		temp = get_next_line(fd);
	}
	return (NULL);
}

int	is_invalid(char c)
{
	if (c != 'N' && c != 'W' && c != 'E' && c != 'S' && c != '3' && c != '1' && c != '0')
		return (1);
	return (0);
}
