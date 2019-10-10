/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:21:15 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/10 03:33:38 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "libft/libft.h"

int		main(int c, char **v)
{
	int		fd; //to store the file discriptor of the file
	char	*line; //to store the line
	

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