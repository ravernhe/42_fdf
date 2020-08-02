/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:09:04 by ravernhe          #+#    #+#             */
/*   Updated: 2019/05/31 20:32:38 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_struct(t_pos **pos, t_ref ref)
{
	int i;

	i = 0;
	while (i != ref.ligne)
	{
		free(pos[i]);
		i++;
	}
	free(pos);
}

t_max	find_size(t_pos **new_pos, t_ref ref)
{
	t_max	max;
	int		i;
	int		j;

	max.x_max = 0;
	max.y_max = 0;
	j = -1;
	while (++j < ref.ligne)
	{
		i = -1;
		while (++i < ref.col)
		{
			if (new_pos[j][i].x > max.x_max)
				max.x_max = new_pos[j][i].x;
			if (new_pos[j][i].y > max.y_max)
				max.y_max = new_pos[j][i].y;
		}
	}
	return (max);
}

void	ft_put_centre(t_pos **new_pos, t_ref ref)
{
	t_max	max;
	int		i;
	int		j;

	max = find_size(new_pos, ref);
	j = -1;
	while (++j < ref.ligne)
	{
		i = -1;
		while (++i < ref.col)
		{
			new_pos[j][i].y = ((max.y_max - new_pos[j][i].y) + 50);
			new_pos[j][i].x = ((max.x_max - new_pos[j][i].x) + 50);
		}
	}
}

t_ref	ft_set_res(t_ref ref)
{
	int i;
	int j;

	j = 1;
	i = 1;
	ref.res = -1;
	if (ref.ligne < 800 || ref.col < 800)
	{
		while (((i++ * ref.ligne) < 800) && ((i * ref.col) < 800))
			if (!(i % 10))
				j++;
		ref.res = -i;
		ref.res_z = -j;
	}
	else
	{
		while ((((ref.res * ref.ligne) < 800)
				|| ((ref.res * ref.col) < 800)) && (ref.res >= 0.1))
			ref.res += 0.1;
		ref.res_z = -0.1;
	}
	return (ref);
}
