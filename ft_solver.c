/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 01:24:32 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 02:00:45 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	**ft_allocate_dp(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = (int **)malloc(sizeof(int *) * rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dp[i] = (int *)malloc(sizeof(int) * cols);
		if (!dp[i])
		{
			ft_free_dp(dp, i);
			return (NULL);
		}
		i++;
	}
	return (dp);
}

static void	ft_update_max(t_square curr, int size, t_square *max)
{
	if (size > max->size)
	{
		max->size = size;
		max->r = curr.r;
		max->c = curr.c;
	}
}

static void	ft_procces_cell(t_map *map, int **dp, t_square curr, t_square *max)
{
	int	r;
	int	c;

	r = curr.r;
	c = curr.c;
	if (map->grid[r][c] == map->obstacle)
		dp[r][c] = 0;
	else if (r == 0 || c == 0)
		dp[r][c] = 1;
	else
		dp[r][c] = ft_min_of_three(dp[r - 1][c], dp[r][c - 1],
				dp[r - 1][c - 1]) + 1;
	ft_update_max(curr, dp[r][c], max);
}

void	ft_solve_bsq(t_map *map)
{
	int			**dp;
	t_square	curr;
	t_square	max;

	dp = ft_allocate_dp(map->rows, map->cols);
	if (!dp)
		return ;
	max.size = 0;
	max.r = 0;
	max.c = 0;
	curr.r = -1;
	while (++curr.r < map->rows)
	{
		curr.c = -1;
		while (++curr.c < map->cols)
		{
			ft_procces_cell(map, dp, curr, &max);
		}
	}
	ft_draw_and_print(map, max);
	ft_free_dp(dp, map->rows);
}
