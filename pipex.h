/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:12:52 by iel-mach          #+#    #+#             */
/*   Updated: 2022/03/21 05:40:45 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	**find_path(char **s);
char	**ft_path_join(char **splt, char *s);
int		ft_strlen(char *s);
int		creat_file(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file(char *s);
char	*ft_substr(char *s, int start, size_t len);
#endif