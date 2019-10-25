/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:48:35 by kbahrar           #+#    #+#             */
/*   Updated: 2019/10/25 01:26:26 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_check_line(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '\0')
		ft_error("FDF: line empty.");
	while (line[i] && line[i] != ',')
	{
		if (ft_isalpha(line[i]) == 1 && line[i] != ' ' &&
				ft_isdigit(line[i]) == 0)
			ft_error("FDF: Invalid character.");
		i++;
	}
}

static void	ft_checkfile2(t_data *data, char **tab, int j, int i)
{
	data->width = ft_count_tab(tab);
	data->p[i] = (t_point *)malloc(sizeof(t_point) * data->width);
	while (tab[++j])
	{
		data->p[i][j].value = ft_atoi(tab[j]);
		if (data->p[i][j].value == 0)
			data->p[i][j].color = 0xbada55;
		else
			data->p[i][j].color = 0xff0000;
		data->p[i][j].x = j * data->zoom + H / 2;
		data->p[i][j].y = i * data->zoom;
	}
	free(tab);
}

static void	ft_check_file(int fd, t_data *data)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;

	data->p = (t_point **)malloc(sizeof(t_point *) * data->hight);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_check_line(line);
		if (ft_strlen(line) > 4000)
			data->zoom = 2;
		else if (ft_strlen(line) > 400)
			data->zoom = 4;
		else
			data->zoom = 7;
		if (!(tab = ft_strsplit(line, ' ')))
			ft_error("FDF: problem in content.");
		j = -1;
		ft_checkfile2(data, tab, j, i);
		i++;
		free(line);
	}
	if (!i)
		ft_error("FDF: file empty. or Permission denied");
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
		ft_error("FDF: invalid name, (*.fdf) or argument");
	if (!(fd = open(nom, O_RDONLY)))
		ft_error("FDF: can't open file.");
	data->hight = ft_count_lines(nom);
	data->v = nom;
	ft_check_file(fd, data);
}
