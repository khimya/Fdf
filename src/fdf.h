/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <benbraitit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:39:00 by kbahrar           #+#    #+#             */
/*   Updated: 2019/10/18 05:18:32 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define HORIZONTAL	1440
# define VERTICAL 900

typedef struct  s_point
{
	int				x;
	int				y; 
    int             value;
    int             color;
}               t_point;

typedef struct      s_coord
{
    int             x;
    int             y;
}                   t_coord;

typedef struct	s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
    int     width;
    int     hight;
    t_point **points;
}				t_data;

void                ft_error(char *str);
void		        ft_check(char *nom, t_data *data);
void                ft_draw(t_data	*data);
void		        ft_add_pts(char **tab, t_point **p, int y);
void ft_line(int color, t_point p0, t_point p1 , t_data *data);
void			rotate(t_data *data);
//t_coord				rotate(t_coord from, t_data *data, int i, int j);
//void		        draw_line(t_window *w, int color, t_point p0, t_point p1);

#endif
