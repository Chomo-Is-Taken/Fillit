/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:19:34 by jopaning          #+#    #+#             */
/*   Updated: 2019/06/19 16:04:52 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct		s_shapes
{
	t_point	t1;
	t_point	t2;
	t_point	t3;
	t_point	t4;
	char	alpha;
}			t_shapes;

void	ft_putchar(char c);
void	ft_putendl(char const *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int	ft_size_board(int nb);
void	ft_board_display(char **board);
char	**ft_create_board(int nb);
void	ft_free_board(char **board);
int	ft_tetri_read(t_shapes **t, char *buff, int fd, char al);
void	ft_tetri_free(t_shapes **tetri);
void	ft_tetri_delete(char **board, int size, t_shapes tetri);
int	ft_chartotetri(char *input, t_shapes *tetri);
t_point	ft_firstpiece(char *input);
void	ft_abstorelative(t_point head, t_shapes *tetri);
int	ft_can_fill(t_point coo, t_shapes t, char **b, int size);
int	ft_input_check(char *input);
int	ft_neighborscheck1(t_shapes tetri);
int	ft_neighborscheck2(t_shapes tetri);
int	ft_neighborscheck3(t_shapes tetri);
int	ft_neighborscheck4(t_shapes tetri);
int	ft_neighborscheck5(t_shapes tetri);
int	ft_neighborscheck6(t_shapes tetri);
int	ft_neighbors(t_shapes tetri);
void	ft_fill(t_point coo, t_shapes tetri, char **board, char c);
int	ft_file_open(t_shapes **tetri, char *filename);
int	ft_iterate(char **b, int size, t_shapes **t, t_point coo);
void	ft_fillit(t_shapes **tetri);
int	ft_tetri_count(t_shapes **tetri);
int	ft_sqrt_recursive(int l, int r, int nb);

#endif
