/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procces_cell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:36:17 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 07:36:23 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_procces_cell(t_map *map, int **dp, t_square curr, t_square *max)
{
	int r;
	int c;

	r = curr.r;
	c = curr.c;
	if (map->grid[r][c] == map->obstacle)
		dp[r][c] = 0;
	else if (r == 0 || c == 0)
		dp[r][c] = 1;
	else
		dp[r][c] = ft_min_of_three(dp[r - 1][c], dp[r][c - 1],
								   dp[r - 1][c - 1]) +
				   1;
	ft_update_max(curr, dp[r][c], max);
}
