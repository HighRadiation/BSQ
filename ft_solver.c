/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 01:24:32 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 01:42:36 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static	void	ft_free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i])
		i++;
	}
	free(dp);
}

static int	**ft_allocate_dp(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = (int **)malloc(sizeof(int *)* rows);
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

static int	**ft_allocate_dp(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = (int **)malloc(sizeof(int *)* rows);
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

static void	ft_update_max(int r, int c, int size, t_square *max)
{
	if (size > max-> size)
	{
		max->size = size;
		max->r = r;
		max->c = c;
	}
}

static void	ft_procces_cell(t_map	*map, int **dp, int r, int c, t_square *max)
{
	if (map->grid[r][c] == map->obstacle)
		dp[r][c] = 0;
	else if (r == 0 || c == 0)
		dp[r][c] = 1;
	else
		dp[r][c] = ft_min_of_three(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1] + 1);
	ft_update_max(r, c, dp[r][c], max);
}
