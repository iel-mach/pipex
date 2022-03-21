/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:13:24 by iel-mach          #+#    #+#             */
/*   Updated: 2022/03/22 00:05:52 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*x;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	x = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!x)
		return (0);
	while (s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		x[i] = s2[j];
		j++;
		i++;
	}
	x[i] = '\0';
	free (s1);
	return (x);
}
