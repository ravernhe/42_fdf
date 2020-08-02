/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:59:21 by mamisdra          #+#    #+#             */
/*   Updated: 2019/05/31 20:49:45 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_pos
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_pos;

typedef struct	s_bres
{
	int dxy[2];
	int sxy[2];
	int err;
	int e2;
}				t_bres;

typedef struct	s_max
{
	int	x_max;
	int	y_max;
}				t_max;

typedef struct	s_ref
{
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		ligne;
	int		col;
	double	res_z;
	double	res;
	void	*mlx_ptr;
	void	*win_ptr;
	t_pos	**pos;
}				t_ref;

t_pos			**ft_read_check(int fd, t_pos **pos, t_ref *ref);
t_pos			**init_struct(t_pos **pos, int x, int y);
t_ref			ft_set_res(t_ref ref);
void			ft_put_centre(t_pos **new_pos, t_ref ref);
int				ft_algo(t_pos **pos, t_ref ref);
void			free_struct(t_pos **pos, t_ref ref);
int				deal_key(int key, void *param);
int				ft_check_line(char *str);
int				print_error(char *error);

#endif
