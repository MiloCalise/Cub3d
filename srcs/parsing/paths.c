/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:04:08 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/14 11:44:52 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*grab_path(char *str, char *to_find)
{
	char	*res;
	size_t	len;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	skip_whitespaces(str, &i);
	if (ft_strncmp(str + i, to_find, 2) != 0)
		return (NULL);
	i += 2;
	skip_whitespaces(str, &i);
	if (!str[i])
		return (NULL);
	len = ft_strlen(str + i);
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str + i, len);
	return (res);
}
