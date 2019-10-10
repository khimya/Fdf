/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:21:15 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/10 04:19:52 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int c, char **v)
{
	int		fd;
	char	*line;
	
	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			if (ft_parse(line) == 0)
			{
				free(line);
				return (0);
			}
			free(line);
		}
	}
	if (c == 2)
	close(fd);
}