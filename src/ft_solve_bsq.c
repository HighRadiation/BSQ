/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:37:14 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 07:37:21 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void ft_solve_bsq(t_map *map)
{
	int **dp;
	t_square curr;
	t_square max;

	dp = ft_allocate_dp(map->rows, map->cols);
	if (!dp)
		return;
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
