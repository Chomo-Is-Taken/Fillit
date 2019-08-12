/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:45:42 by jopaning          #+#    #+#             */
/*   Updated: 2019/06/19 11:22:01 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_size_board(int nb)
{
	int		sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt < nb)
		sqrt++;
	return ((sqrt * sqrt == nb) ? 2 * sqrt : 2 * --sqrt);
}

void	ft_board_display(char **board)
{
	int	i;
	
	i = 0;
	while (board[i] != NULL)
	{
		ft_putendl(board[i]);
		i++;
	}
}

char	**ft_create_board(int nb)
{
	char	**board;
	int	i;
	int	j;

	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	board[nb] = NULL;
	while (i < nb)
	{
		if (!(board[i] = (char *)malloc(sizeof(char *) * (nb + 1))))
			return (NULL);
		board[i][nb] = '\0';
		i++;
	}
	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
			board[i][j++] = '.';
		i++;
	}
	return (board);
}

void	ft_free_board(char **board)
{
	int	i;

	i= 0;
	while (board[i])
	{
		free(board[i]);
		board[i] = NULL;
		i++;
	}
	free(board);
	board = NULL;
}
