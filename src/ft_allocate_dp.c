/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_dp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:34:42 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 07:35:44 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**ft_allocate_dp(int rows, int cols)
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
