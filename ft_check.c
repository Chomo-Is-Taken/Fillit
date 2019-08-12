/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:41:14 by jopaning          #+#    #+#             */
/*   Updated: 2019/08/12 14:01:25 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_can_fill(t_point coo, t_shapes tetri, char **board, int size)
{
	if ((tetri.t1.y + coo.y) >= size || (tetri.t1.x + coo.x) >= size
		|| (tetri.t2.y + coo.y) >= size || (tetri.t2.x + coo.x) >= size
		|| (tetri.t3.y + coo.y) >= size || (tetri.t3.x + coo.x) >= size
		|| (tetri.t4.y + coo.y) >= size || (tetri.t4.x + coo.x) >= size)
		return (0);
	else
		return (board[tetri.t1.y + coo.y][tetri.t1.x + coo.x] == '.'
		&& board[tetri.t2.y + coo.y][tetri.t2.x + coo.x] == '.'
		&& board[tetri.t3.y + coo.y][tetri.t3.x + coo.x] == '.'
		&& board[tetri.t4.y + coo.y][tetri.t4.x + coo.x] == '.');
}

int	ft_input_check(char *input)
{
	int	i;
	int	point;
	int	hash;

	point = 0;
	hash = 0;
	i = 0;
	while (i < 21)
	{
		if (i % 5 == 4 && input[i] != '\n')
		{
			return (0);
		}
		else
		{
			if (input[i] == '#')
				hash++;
			if (input[i] == '.')
				point++;
		}
		i++;
	}
	if (point != 12 || hash != 4)
		return (0);
	return (1);
}

int	ft_neighborscheck1(t_shapes tetri)
{
	return ((tetri.t1.x == tetri.t2.x + 1 && tetri.t1.y == tetri.t2.y)
		|| (tetri.t1.x == tetri.t2.x - 1 && tetri.t1.y == tetri.t2.y)
		|| (tetri.t1.y == tetri.t2.y - 1 && tetri.t1.x == tetri.t2.x)
		|| (tetri.t1.y == tetri.t2.y + 1 && tetri.t1.x == tetri.t2.x));
}

int	ft_neighborscheck2(t_shapes tetri)
{
	return ((tetri.t2.x == tetri.t3.x + 1 && tetri.t2.y == tetri.t3.y)
		|| (tetri.t2.x == tetri.t3.x - 1 && tetri.t2.y == tetri.t3.y)
		|| (tetri.t2.y == tetri.t3.y - 1 && tetri.t2.x == tetri.t3.x)
		|| (tetri.t2.y == tetri.t3.y + 1 && tetri.t2.x == tetri.t3.x));
}

int	ft_neighborscheck3(t_shapes tetri)
{
	return ((tetri.t3.x == tetri.t4.x + 1 && tetri.t3.y == tetri.t4.y)
		|| (tetri.t3.x == tetri.t4.x - 1 && tetri.t3.y == tetri.t4.y)
		|| (tetri.t3.y == tetri.t4.y - 1 && tetri.t3.x == tetri.t4.x)
		|| (tetri.t3.y == tetri.t4.y + 1 && tetri.t3.x == tetri.t4.x));
}
