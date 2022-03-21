/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:11:13 by iel-mach          #+#    #+#             */
/*   Updated: 2022/03/21 05:41:30 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (i < n - 1) && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	first_child(char *s, char **env, char *join, int *fd)
{
	pid_t	y;
	int		a;
	char	**cmd;

	cmd = ft_path_join(env, join);
	a = check_file(s);
	y = fork();
	if (y == 0)
	{
		close(fd[0]);
		dup2(a, 0);
		dup2(fd[1], 1);
		execve(cmd[0], cmd, env);
		write(1, "cmd not found", 14);
	}
	y = 0;
	while (cmd[y])
	{
		free(cmd[y]);
		y++;
	}
	free (cmd);
}

void	second_child(char *s, char **env, char *cmd, int *fd)
{
	pid_t	t;
	int		creat;
	char	**join;

	join = ft_path_join(env, cmd);
	creat = creat_file(s);
	t = fork();
	if (t == 0)
	{
		close (fd[1]);
		dup2(fd[0], 0);
		dup2(creat, 1);
		execve(join[0], join, env);
		perror("cmd not found");
	}
	t = 0;
	while (join[t])
	{
		free(join[t]);
		t++;
	}
	free (join);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];

	if (ac == 5)
	{
		if (pipe(fd) < 0)
		{
			printf("Error\n");
			exit(1);
		}
		first_child(av[1], env, av[2], fd);
		second_child(av[4], env, av[3], fd);
		close (fd[0]);
		close (fd[1]);
		while (wait(NULL) != -1)
		{};
	}
	else
		write (2, "Error\n", 6);
}
