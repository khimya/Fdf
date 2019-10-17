/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:18:01 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/17 22:36:28 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_line(t_coord *p0, t_coord *p1, int color, t_data *data)
 {
  int dx = abs(p1->x - p0->x);
  int sx = p0->x < p1->x ? 1 : -1;
  int dy = abs( p1->y - p0->y);
  int sy = p0->y < p1->y ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2, e2;

  while (1)
  {
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, p0->x, p0->y, color);

    if (p0->x == p1->x && p0->y == p1->y)
        break;
    e2 = err;
    if (e2 >-dx) { err -= dy; p0->x += sx; }
    if (e2 < dy) { err += dx; p0->y += sy; }
  }
}


void    ft_draw(t_data	*data)
{

    int j;
    int i;
    t_coord from;
	t_coord to;

    i = -1;
    from.x = HORIZONTAL / 4;
    from.y = VERTICAL / 4;
    while (++i < data->hight)
    {
        j = -1;
        while (++j < data->width - 1)
        {
            to.x = from.x + 20;
            to.y = from.y;
            ft_line(&from, &to, 0xbada55, data);
            from = to;
        }

        from.x = HORIZONTAL / 4;
        from.y += 20;
    }

    i = -1;
    from.x = HORIZONTAL / 4;
    from.y = VERTICAL / 4;
    while (++i < data->width)
    {
        
        j = -1;
        while (++j < data->hight - 1)
        {
            to.x = from.x;
            to.y = from.y + 20;
            ft_line(&from, &to, 0xbada55, data);
            from = to;
        }
from.y = VERTICAL / 4;
        from.x += 20;

    }
    /*i = -1;
    from.x = HORIZONTAL / 4;
    from.y = VERTICAL / 4;
    while (++i < data->width)
    {
        from.y = VERTICAL / 4;
        from.x += 20;
        j = -1;
        while (++j < data->hight)
        {
            to.x = from.x;
            to.y = from.y + 20;
            ft_line(&from, &to, 0xbada55, data);
            from = to;
        }

    }
	*/



    mlx_loop(data->mlx_ptr);
}