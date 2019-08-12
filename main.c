/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 10:22:23 by jopaning          #+#    #+#             */
/*   Updated: 2019/08/12 12:57:02 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_file_open(t_shapes **tetri, char *filename)
{
	char	buff[22];
	int	fd;
	int	readres;

	readres = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (-1);
	ft_bzero(buff, 22);
	if (read(fd, buff, 1) == 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (-1);
	ft_bzero(buff, 22);
	readres = ft_tetri_read(tetri, buff, fd, 'A');  //store the teteris
	if (close(fd) == -1)				//go to block.c
		return (-1);
	return (readres);
}

void	ft_fill(t_point coo, t_shapes tetri, char **board, char c) //fill the board
{								   // with alpha
	board[tetri.t1.y + coo.y][tetri.t1.x + coo.x] = c;
	board[tetri.t2.y + coo.y][tetri.t2.x + coo.x] = c;
	board[tetri.t3.y + coo.y][tetri.t3.x + coo.x] = c;
	board[tetri.t4.y + coo.y][tetri.t4.x + coo.x] = c;
}

int	ft_iterate(char **board, int size, t_shapes **tetri, t_point coo)
{
	t_point start;

	start.x = 0;
	start.y = 0;
	if (*tetri == NULL)
		return (1);
	while (coo.y < size && *tetri != NULL)
	{
		while (coo.x < size && *tetri != NULL)
		{
			if (ft_can_fill(coo, **tetri, board, size))
			{
				ft_fill(coo, **tetri, board, (**tetri).alpha);
				tetri++;
				if (ft_iterate(board, size, tetri, start) == 0)
					ft_tetri_delete(board, size,
					**(--tetri));
				else
					return (1);
			}
			(coo.x)++;
		}
		(coo.y)++;
		coo.x = 0;
	}
	return (0);
}

void	ft_fillit(t_shapes **tetri)
{
	char	**board;
	t_point	coo;
	int		size;

	coo.x = 0;
	coo.y = 0;
	size = ft_size_board(ft_tetri_count(tetri));
	board = ft_create_board(size);
	while (ft_iterate(board, size, tetri, coo) == 0)
	{
		ft_free_board(board);
		board = ft_create_board(++size);
	}
	ft_board_display(board);
	ft_free_board(board);
}

int	main(int argc, char **argv)
{
	char			**board;
	t_shapes		**pt;
	int				i;

	i = 0;
	board = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: please provide exactly one file");
		return (0);
	}
	pt = (t_shapes**)malloc(sizeof(t_shapes*) * (27));
	while (i < 27)
		pt[i++] = NULL;   //initialising pt;
	if (ft_file_open(pt, argv[1]) < 0) //reading the tetrises and storing them
	{
		ft_putendl("error");
		ft_tetri_free(pt); //free to avoid leaks
		return (0);
	}
	ft_fillit(pt);
	ft_tetri_free(pt);
	return (1);
}
