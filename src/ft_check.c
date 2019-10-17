/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:48:35 by kbahrar           #+#    #+#             */
/*   Updated: 2019/10/17 22:28:51 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_check_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0')
		ft_error("FDF: line empty.");
	while (line[i])
	{
		if (ft_isalpha(line[i]) == 1 && line[i] != ' '
		&& line[i] != 'x' && line[i] != ',' && ft_isdigit(line[i]) == 0)
			ft_error("FDF: Invalid character.");
		i++;
	}
}

// static void	boucle_file(int fd, char **tab, char *line, t_data *data)
// {
// 	int	i;
// 	int w1;

// 	i = 1;
// 	while (get_next_line(fd, &line) != 0)
// 	{
// 		ft_check_line(line);
// 		if (!(tab = ft_strsplit(line, ' ')))
// 			ft_error("FDF: problem in content.");
// 		ft_add_pts(tab, &data->points, i++);
// 		w1 = ft_count_tab(tab);
// 		if (data->w != w1)
// 			ft_error("FDF: not the same width.");
// 		free(line);
// 		free(tab);
// 	}
// 	data->h = i;
// }

static void	ft_check_file(int fd, t_data *data)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = NULL;
	line = NULL;
	data->points = (t_point **)malloc(sizeof(t_point *) * data->hight);
	while (get_next_line(fd, &line) > 0)
	{
		ft_check_line(line);
		if (!(tab = ft_strsplit(line, ' ')))
			ft_error("FDF: problem in content.");
		j = -1;
		data->width = ft_count_tab(tab);
		data->points[i] = (t_point *)malloc(sizeof(t_point) * data->width);
		while (tab[++j])
			data->points[i][j].value = ft_atoi(tab[j]);
		i++;
		free(line);
		free(tab);
	}
	if (!i)
		ft_error("FDF: file empty.");
}

int			ft_count_lines(char *file)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

void		ft_check(char *nom, t_data *data)
{
	int		fd;

	if (ft_strstr(nom, ".fdf") == NULL)
		ft_error("FDF: invalid name, (*.fdf).");
	if (!(fd = open(nom, O_RDONLY)))
		ft_error("FDF: can't open file.");
	data->hight = ft_count_lines(nom);
	ft_check_file(fd, data);
}
