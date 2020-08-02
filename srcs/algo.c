/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:05:21 by mamisdra          #+#    #+#             */
/*   Updated: 2019/05/31 21:10:39 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pos	ft_get_new_pos(t_pos new_pos, t_pos pos, t_ref ref)
{
	int	x;
	int	y;
	int	z;

	new_pos.x = pos.x * ref.res;
	new_pos.y = pos.y * ref.res;
	new_pos.z = pos.z * ref.res_z;
	x = new_pos.x;
	z = new_pos.z;
	new_pos.x = cos(ref.angle_y) * x + sin(ref.angle_y) * z;
	new_pos.z = -sin(ref.angle_y) * x + cos(ref.angle_y) * z;
	y = new_pos.y;
	z = new_pos.z;
	new_pos.y = cos(ref.angle_x) * y - sin(ref.angle_x) * z;
	new_pos.z = sin(ref.angle_x) * y + cos(ref.angle_x) * z;
	x = new_pos.x;
	y = new_pos.y;
	new_pos.x = cos(ref.angle_z) * x - sin(ref.angle_z) * y;
	new_pos.y = sin(ref.angle_z) * x + cos(ref.angle_z) * y;
	new_pos.color = pos.color;
	new_pos.z = pos.z;
	return (new_pos);
}

t_pos	**rotate(t_pos **new_pos, t_pos **pos, t_ref ref)
{
	int	i;
	int	j;

	if (!(new_pos = init_struct(new_pos, ref.col, ref.ligne)))
		return (NULL);
	j = -1;
	while (++j < ref.ligne)
	{
		i = -1;
		while (++i < ref.col)
		{
			new_pos[j][i] = ft_get_new_pos(new_pos[j][i], pos[j][i], ref);
		}
	}
	return (new_pos);
}

void	drawline(t_pos n, t_pos n1, t_ref ref)
{
	t_bres bres;

	bres.dxy[0] = abs(n1.x - n.x);
	bres.sxy[0] = (n.x < n1.x) ? 1 : -1;
	bres.dxy[1] = abs(n1.y - n.y);
	bres.sxy[1] = (n.y < n1.y) ? 1 : -1;
	bres.err = ((bres.dxy[0] > bres.dxy[1]) ? bres.dxy[0] : -bres.dxy[1]) / 2;
	while (1)
	{
		mlx_pixel_put(ref.mlx_ptr, ref.win_ptr, n.x, n.y, \
			((n.color + n1.color) / 2) + (n.z + n1.z) / 2 * ref.res_z * 0.4);
		if (n.x == n1.x && n.y == n1.y)
			break ;
		bres.e2 = bres.err;
		if (bres.e2 > -bres.dxy[0])
		{
			bres.err -= bres.dxy[1];
			n.x += bres.sxy[0];
		}
		if (bres.e2 < bres.dxy[1])
		{
			bres.err += bres.dxy[0];
			n.y += bres.sxy[1];
		}
	}
}

int		ft_algo(t_pos **pos, t_ref ref)
{
	t_pos	**new_pos;
	int		i;
	int		j;

	new_pos = NULL;
	if (!(new_pos = rotate(new_pos, pos, ref)))
		return (0);
	i = 0;
	ft_put_centre(new_pos, ref);
	while (i < ref.ligne)
	{
		j = 0;
		while (j < ref.col)
		{
			if (j != ref.col - 1)
				drawline(new_pos[i][j], new_pos[i][j + 1], ref);
			if (i != ref.ligne - 1)
				drawline(new_pos[i][j], new_pos[i + 1][j], ref);
			j++;
		}
		i++;
	}
	free_struct(new_pos, ref);
	return (1);
}
