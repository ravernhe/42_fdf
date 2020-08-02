/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:17:25 by mamisdra          #+#    #+#             */
/*   Updated: 2019/05/31 21:41:14 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pos	**init_struct(t_pos **pos, int x, int y)
{
	int i;

	i = -1;
	if (!(pos = (t_pos **)malloc(sizeof(t_pos *) * y)))
		return (NULL);
	while (++i < y)
	{
		if (!(pos[i] = (t_pos *)malloc(sizeof(t_pos) * x + 1)))
			return (NULL);
	}
	return (pos);
}

int		ft_get_color(char *str, int i)
{
	while (str[i] && str[i] != ',')
	{
		if (str[i] == '\0' || str[i] == ' ' || str[i] == '\n')
			return (6684833);
		i++;
	}
	i += 3;
	return (ft_atoi_base_i(str, 16, i));
}

void	ft_skip(char *str, int *i, int *x, int *y)
{
	int q;

	q = 0;
	if (str[*i] == '\n')
	{
		*y += 1;
		*x = 0;
		*i += 1;
	}
	if (str[*i] == ' ')
	{
		if (*i == 0 || (*i > 0 && str[*i - 1] == '\n'))
			q = 1;
		while (str[*i] != '\0' && str[*i] == ' ')
			*i += 1;
		if (q != 1)
			*x += 1;
	}
}

t_pos	**fill_struct(t_pos **pos, char *str)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	while (str[i] != '\0')
	{
		ft_skip(str, &i, &x, &y);
		pos[y][x].x = x;
		pos[y][x].y = y;
		pos[y][x].z = ft_atoi_i(str, i);
		pos[y][x].color = ft_get_color(str, i);
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
			i++;
		if (str[i] == '\0' || str[i + 1] == '\0')
			break ;
	}
	return (pos);
}

t_pos	**ft_read_check(int fd, t_pos **pos, t_ref *ref)
{
	char	*str;
	char	*buff;
	int		ret;
	int		nb_ld[2];

	nb_ld[0] = 0;
	if (!(str = ft_strnew(0)))
		print_error("Error : ft_strnew failed");
	while ((ret = get_next_line(fd, &buff)) == 1)
	{
		if ((nb_ld[1] = ft_check_line(buff)) == 0)
			exit(1);
		str = ft_strjoin_free_s1s2(str, buff);
		str = ft_strjoin_free_s1(str, "\n");
		nb_ld[0]++;
	}
	if (ret == -1 || nb_ld[0] == 0)
		print_error("Error : map error");
	if (!(pos = init_struct(pos, nb_ld[1], nb_ld[0])))
		return (NULL);
	pos = fill_struct(pos, str);
	ref->ligne = nb_ld[0];
	ref->col = nb_ld[1];
	free(str);
	return (pos);
}
