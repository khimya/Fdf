/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:39:00 by kbahrar           #+#    #+#             */
/*   Updated: 2019/10/17 21:22:14 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define HORIZONTAL	1440
# define VERTICAL 900

typedef struct  s_point
{
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
void                ft_line(t_coord *p0, t_coord *p1, int color, t_data *data);
//void		        draw_line(t_window *w, int color, t_point p0, t_point p1);

#endif
