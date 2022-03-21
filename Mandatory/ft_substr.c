/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:17:12 by iel-mach          #+#    #+#             */
/*   Updated: 2022/03/22 00:05:56 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*x;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	j = 0;
	while (i < len && s[i])
		i++;
	x = malloc(i + 1);
	if (!x)
		return (NULL);
	while (j < i)
		x[j++] = s[start++];
	x[i] = '\0';
	return (x);
}
