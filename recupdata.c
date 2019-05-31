/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:10:08 by tblancha          #+#    #+#             */
/*   Updated: 2019/05/31 17:26:13 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**filldata(char *buf)
{
	char			**tetriminos;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(tetriminos = (char**)malloc(sizeof(char*) * 26 + 1)))
		return (NULL);
	tetriminos = NULL;
	while (buf[i])
	{
		if (!(buf + i + 19))
			return (NULL);
		else
			tetriminos[j] = ft_strsub((char const*)buf, i, 20);
		i += 21;
		tetriminos[j + 1] = NULL;
		if (!buf[i - 1])
			return (tetriminos);
		else if (buf[i - 1] != '\n')
			return (NULL);
		j++;
	}
	return (NULL);
}

char		**recupdata(char *file)
{
	int		fd;
	char	*buf;
	char	**tetriminos;

	buf = NULL;
	tetriminos = NULL;
	if (!file)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 1)
		return (NULL);
	if (read(fd, buf, 600) > 15)
		tetriminos = filldata(buf);
	else
		return (NULL);
	return (tetriminos);
}
