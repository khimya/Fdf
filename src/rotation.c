/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <benbraitit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:06:58 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/18 05:18:22 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

 void		rotate(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;


	while (i <= data->hight - 1)
	{
		j = 0;
		while (j < data->width)
		{
			iso(&data->points[i][j].x, &data->points[i][j].y, data->points[i][j].value);
			j++;
		}
			i++;
	}
	
 }