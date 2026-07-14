/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 01:24:32 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 01:38:45 by buoksuz          ###   ########.fr       */
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
