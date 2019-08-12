/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:41:27 by jopaning          #+#    #+#             */
/*   Updated: 2019/08/12 12:50:44 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	ft_firstpiece(char *input)
{
	int	i;
	t_point	res;
	t_point	min;

	i = 0;
	min.x = 3;
	min.y = 3;
	while (i < 21)
	{
		if (input[i] == '#')
		{
			res.x = i % 5;
			res.y = i / 5;
			if (res.x < min.x)
				min.x = res.x;
			if (res.y < min.y)
				min.y = res.y;
		}
		i++;
	}
	return (min);
}

void	ft_abstorelative(t_point head, t_shapes *tetri) //we put tetris to top left
{
	tetri->t1.x = tetri->t1.x - head.x;
	tetri->t1.y = tetri->t1.y - head.y;
	tetri->t2.x = tetri->t2.x - head.x;
	tetri->t2.y = tetri->t2.y - head.y;
	tetri->t3.x = tetri->t3.x - head.x;
	tetri->t3.y = tetri->t3.y - head.y;
	tetri->t4.x = tetri->t4.x - head.x;
	tetri->t4.y = tetri->t4.y - head.y;
}

int	ft_chartotetri(char *input, t_shapes *tetri)
{
	int		i;

	i = 0;
	if (ft_input_check(input) == 0)
		return (0);
	while (input[i] != '#' && i < 21)
		i++;
	tetri->t1.x = i % 5;
	tetri->t1.y = i / 5;
	i++;
	while (input[i] != '#' && i < 21)
		i++;
	tetri->t2.x = i % 5;
	tetri->t2.y = i / 5;
	i++;
	while (input[i] != '#' && i < 21)
		i++;
	tetri->t3.x = i % 5;
	tetri->t3.y = i / 5;
	i++;
	while (input[i] != '#' && i < 21)
		i++;
	tetri->t4.x = i % 5;
	tetri->t4.y = i / 5;
	return (1);
}
