/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:58:15 by mamisdra          #+#    #+#             */
/*   Updated: 2019/05/31 21:22:52 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_fdf(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i < 5 || str[i - 4] != '.' || str[i - 3] != 'f'\
		|| str[i - 2] != 'd' || str[i - 1] != 'f')
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_pos	**pos;
	t_ref	ref;
	int		fd;

	pos = NULL;
	if (ac != 2 || is_fdf(av[1]) == 0)
		return (print_error("Usage : ./fdf filename.fdf"));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (print_error("Open error ! Good filename ?"));
	if (!(pos = ft_read_check(fd, pos, &ref)))
		return (0);
	close(fd);
	ref.mlx_ptr = mlx_init();
	ref.win_ptr = mlx_new_window(ref.mlx_ptr, 1600, 1200, av[1]);
	ref.angle_x = 0.78;
	ref.angle_y = 0.78;
	ref.angle_z = -0.78;
	ref.pos = pos;
	ref = ft_set_res(ref);
	if (!(ft_algo(pos, ref)))
		return (0);
	mlx_hook(ref.win_ptr, 2, 0, deal_key, &ref);
	mlx_loop(ref.mlx_ptr);
	return (0);
}
