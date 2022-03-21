/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:14:23 by iel-mach          #+#    #+#             */
/*   Updated: 2022/03/21 05:49:59 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **s)
{
	int		i;
	char	*sub;
	char	**splt;

	i = 0;
	while (s[i])
	{
		if (ft_strncmp("PATH", s[i], 4) == 0)
		{
			sub = ft_substr(s[i], 5, ft_strlen(s[i]));
			splt = ft_split(sub, ':');
			free (sub);
			return (splt);
		}
		i++;
	}
	return (NULL);
}

char	**ft_path_join(char **env, char *s)
{
	int		i;
	char	**cmd;
	char	**splt;
	char	*k;

	splt = find_path(env);
	cmd = ft_split(s, ' ');
	i = -1;
	while (splt[++i])
	{
		splt[i] = ft_strjoin(splt[i], "/");
		k = ft_strjoin(splt[i], cmd[0]);
		if (access(k, X_OK) == 0)
		{
			while (splt[++i])
				free (splt[i]);
			free (splt);
			free (cmd[0]);
			cmd[0] = k;
			return (cmd);
		}
		free (k);
	}
	free (splt);
	return (cmd);
}

int	creat_file(char *s)
{
	int	fd;

	fd = open(s, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (fd < 0)
	{
		printf("Error file\n");
		return (-1);
	}
	return (fd);
}

int	check_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		perror(s);
		return (-1);
	}
	return (fd);
}
