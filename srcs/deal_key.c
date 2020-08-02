/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:16:50 by mamisdra          #+#    #+#             */
/*   Updated: 2019/05/31 20:32:35 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_angles(int key, t_ref *ref)
{
	if (key == 18)
	{
		ref->angle_x = 0;
		ref->angle_y = 0;
		ref->angle_z = 0;
	}
	else
	{
		ref->angle_x = 0.78;
		ref->angle_y = 0.78;
		ref->angle_z = -0.78;
	}
}

void	ft_set_data(int key, t_ref *ref)
{
	if (key == 126)
		ref->angle_x = ref->angle_x + 0.1;
	else if (key == 125)
		ref->angle_x = ref->angle_x - 0.1;
	else if (key == 123)
		ref->angle_z = ref->angle_z - 0.1;
	else if (key == 124)
		ref->angle_z = ref->angle_z + 0.1;
	else if (key == 38)
		ref->angle_y = ref->angle_y - 0.1;
	else if (key == 37)
		ref->angle_y = ref->angle_y + 0.1;
	else if (key == 88)
		ref->res = ref->res - 0.5;
	else if (key == 92)
		ref->res = ref->res + 0.5;
	else if (key == 69)
		ref->res_z = ref->res_z - 0.5;
	else if (key == 78)
		ref->res_z = ref->res_z + 0.5;
	else if (key == 18 || key == 19)
		change_angles(key, ref);
}

int		deal_key(int key, void *param)
{
	t_ref	*ref;

	ref = (t_ref *)param;
	if (key == 53)
	{
		free_struct(ref->pos, *ref);
		exit(0);
	}
	ft_set_data(key, ref);
	mlx_clear_window(ref->mlx_ptr, ref->win_ptr);
	if (!(ft_algo(ref->pos, *ref)))
		return (1);
	return (0);
}
