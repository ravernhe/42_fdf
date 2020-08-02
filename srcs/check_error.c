/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:47:51 by mamisdra          #+#    #+#             */
/*   Updated: 2019/05/31 20:32:27 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

int		is_hex(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || \
		(c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

void	ft_if_check(char *str, int *i, int *n)
{
	if (str[*i] == ' ')
	{
		while (str[*i] && str[*i] == ' ')
			*i += 1;
	}
	else if (str[*i] == ',' && str[*i + 1] == '0' && str[*i + 2] == 'x')
	{
		*i += 3;
		*n = 6;
		while (str[*i] && *n > 0)
		{
			if (!is_hex(str[*i]))
				print_error("Error : Bad color");
			*i += 1;
			*n -= 1;
			if (str[*i] == ' ')
				break ;
		}
		if (str[*i] != '\0' && str[*i] != '\n' && str[*i] != ' ')
			print_error("Error : map error");
		while (str[*i] && str[*i] == ' ')
			*i += 1;
	}
	else
		print_error("Error : map error");
}

void	ft_check_if(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
		*i += 1;
	if (str[*i] < '0' || str[*i] > '9')
		print_error("Error : map error");
}

int		ft_check_line(char *str)
{
	static int	data_check;
	int			i;
	int			n;
	int			nb_data;

	i = 0;
	nb_data = 0;
	while (str[i])
	{
		ft_check_if(str, &i);
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ',' || str[i] == ' ')
			ft_if_check(str, &i, &n);
		else if (str[i] != '\0' && str[i] != '\n')
			print_error("Error : map error");
		nb_data++;
	}
	if (!data_check)
		data_check = nb_data;
	else if (data_check != nb_data)
		print_error("Error : wrong number of data");
	return (nb_data);
}
