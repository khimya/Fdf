/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <benbraitit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:18:01 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/18 05:04:38 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_line(int color, t_point p0, t_point p1 , t_data *data)
 {
  int dx = abs(p1.x - p0.x);
  int sx = p0.x < p1.x ? 1 : -1;
  int dy = abs( p1.y - p0.y);
  int sy = p0.y < p1.y ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2, e2;

  while (1)
  {
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, p0.x, p0.y, color);

    if (p0.x == p1.x && p0.y == p1.y)
        break;
    e2 = err;
    if (e2 >-dx) { err -= dy; p0.x += sx; }
    if (e2 < dy) { err += dx; p0.y += sy; }
  }
}


void	ft_draw(t_data	*data)
{
	int j;
	int i;

	i = 0;
	while (i <= data->hight - 1)
	{
		j = 0;
		while (j < data->width)
		{
			if (j +1 < data->width)
				ft_line(0xbada55, data->points[i][j], data->points[i][j + 1] ,data);
			if (i + 1 < data->hight)
				ft_line(0xbada55, data->points[i][j], data->points[i + 1][j] ,data);
			j++;
		}
			i++;
	}
	mlx_loop(data->mlx_ptr);
}