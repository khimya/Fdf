/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:40:58 by kbahrar           #+#    #+#             */
/*   Updated: 2019/10/25 00:40:04 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int c, char **v)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, H, V, "FDF");
	if (c != 2)
		ft_error("FDF: error in arguments.");
	ft_check(v[1], &data);
	mlx_hook(data.win_ptr, 2, 0, &key_press, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
