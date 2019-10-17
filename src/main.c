/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:40:58 by kbahrar           #+#    #+#             */
/*   Updated: 2019/10/17 20:33:05 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, HORIZONTAL,
	VERTICAL, "FDF: testing window");
	if (ac != 2)
		ft_error("FDF: error in arguments.");
	ft_check(av[1], &data);
	ft_draw(&data);
	return (0);
}
