/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:06:58 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/25 01:36:57 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void			rotate(t_data *data)
{
	int			i;
	int			j;

	i = -1;
	while (++i <= data->hight - 1)
	{
		j = -1;
		while (++j < data->width)
			iso(&data->p[i][j].x, &data->p[i][j].y, data->p[i][j].value);
	}
}
