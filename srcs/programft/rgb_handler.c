/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:06:02 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/05 16:07:18 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	control(int x)
{
	return (x > -1 && x < 256);
}

int	rgb_control(char *box)
{
	int	i;

	i = 1;
	while (box[++i])
		if (!ft_isdigit(box[i]) && box[i] != ',')
			return (0);
	return (1);
}

int	rgb_fetcher(t_cub **cub, char c[4], int nvalue, int i)
{
	if (nvalue == 1)
		(*cub)->color.r = a_(c, 10);
	if (nvalue == 2)
		(*cub)->color.g = a_(c, 10);
	if (nvalue == 3)
	{
		(*cub)->color.b = a_(c, 10);
		if (i == 6)
			(*cub)->floor_color = (*cub)->color.r << 16
				| (*cub)->color.g << 8 | (*cub)->color.b;
		else
			(*cub)->ceil_color = (*cub)->color.r << 16
				| (*cub)->color.g << 8 | (*cub)->color.b;
	}
	if (!control((*cub)->color.r) || !control((*cub)->color.g)
		|| !control((*cub)->color.b))
		return (0);
	return (1);
}

int	value_builder(char *box, int *k, int *h, char c[4])
{
	ft_memset(c, 0, ft_strlen(c));
	*h = 0;
	while (ft_isdigit(box[(*k)]))
	{
		if (*h > 2)
			return (0);
		c[*h] = box[(*k)++];
		(*h)++;
	}
	c[*h] = 0;
	return (1);
}

int	skip_char(char *box, int *k, int *nvalue)
{
	while (!ft_isdigit(box[*k]))
		(*k)++;
	(*nvalue)++;
	return (1);
}
