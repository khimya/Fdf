/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:18:22 by kbahrar           #+#    #+#             */
/*   Updated: 2019/10/17 05:24:50 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	init_pts(t_point **p, char **tab, int *x)
// {
// 	*p = (t_point*)malloc(sizeof(t_point));
// 	(*p)->y = 0;
// 	(*p)->x = 0;
// 	(*p)->z = ft_atoi(tab[0]);
// 	(*p)->next = NULL;
// 	(*x)++;
// }

// void		ft_add_pts(char **tab, t_point **p, int y)
// {
// 	t_point *tmp;
// 	int		i;

// 	i = 0;
// 	if (*p == NULL)
// 		init_pts(p, tab, &i);
// 	tmp = *p;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	while (tab[i])
// 	{
// 		tmp->next = (t_point*)malloc(sizeof(t_point));
// 		tmp = tmp->next;
// 		tmp->x = i;
// 		tmp->y = y;
// 		tmp->z = ft_atoi(tab[i]);
// 		tmp->next = NULL;
// 		i++;
// 	}
// }