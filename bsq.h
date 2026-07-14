/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 01:56:47 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 01:56:50 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int	r;
	int	c;
	int	size;
}	t_square;

/* utils.c */
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_min_of_three(int a, int b, int c);
void	ft_free_dp(int **dp, int rows);

/* solver.c */
void	ft_solve_bsq(t_map *map);

/* draw.c */
void	ft_draw_and_print(t_map *map, t_square max);

#endif
