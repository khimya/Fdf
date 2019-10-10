/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:49 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/09 23:38:18 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"


int	key_press(int key, void *param)
{
	puts("b");
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr,1440, 900, "FDF: testing window");
		mlx_pixel_put(mlx_ptr, win_ptr, 720, 450, 0xFFFF00);
	mlx_key_hook (win_ptr, key_press,(void *)0);
	mlx_loop(mlx_ptr);
}
