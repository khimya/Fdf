/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:06:56 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/10 03:33:48 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "libft/libft.h"
int ft_parse(char const *tab)
{
    int i;

    i = 0;
    char **strsplit_return;
    strsplit_return =  ft_strsplit(tab,' ');
    while (strsplit_return[i])
    {
        if (ft_strlen(strsplit_return[i]) != ft_strlen(strsplit_return[i + 1]))
        {
            return (0);
        }
        i++;
    }
    return (ft_strlen(strsplit_return[i]));
    }