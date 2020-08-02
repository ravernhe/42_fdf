/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:43:25 by mamisdra          #+#    #+#             */
/*   Updated: 2018/11/13 15:01:35 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i])
	{
		j = i;
		while (s1[j] == s2[j - i] && s1[j] && s2[j - i])
		{
			j++;
		}
		if (s2[j - i] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
