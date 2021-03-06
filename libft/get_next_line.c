/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:42:51 by mmuteba           #+#    #+#             */
/*   Updated: 2018/08/27 17:54:29 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swapnfree(char **var, char *new_val)
{
	char	*tmp;

	free(*var);
	tmp = new_val;
	*var = tmp;
}

static int	index_of(const char *s, const char c)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (i);
			i++;
		}
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

static void	work(char **ret_line, char **buffer, int nl)
{
	char	*tmp;

	tmp = ft_strsub(*buffer, 0, nl + 1);
	tmp[nl] = '\0';
	swapnfree(ret_line, ft_strjoin(*ret_line, tmp));
	free(tmp);
	tmp = ft_strsub(*buffer, nl + 1, BUFF_SIZE);
	tmp[BUFF_SIZE - nl] = '\0';
	ft_memmove(*buffer, tmp, ft_strlen(tmp) + 1);
	if (buffer[0][0] == '\0')
		ft_bzero(*buffer, (size_t)(BUFF_SIZE + 1));
	free(tmp);
}

static int	gnl(const int fd, char **ret_line, char **buffer)
{
	int		read_ret;
	int		nl;

	nl = -1;
	read_ret = 3;
	while (nl == -1 && read_ret > 0)
	{
		nl = index_of(*buffer, '\n');
		if (nl != -1)
			work(ret_line, buffer, nl);
		else
		{
			swapnfree(ret_line, ft_strjoin(*ret_line, *buffer));
			ft_bzero(*buffer, (size_t)(BUFF_SIZE + 1));
			if ((read_ret = read(fd, *buffer, BUFF_SIZE)) < 0)
				return (-1);
			buffer[0][read_ret] = '\0';
		}
	}
	return (read_ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[MI];
	int			read_ret;

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buffer[fd], 0) < 0)
		return (-1);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(BUFF_SIZE + 1);
	if ((*line = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	if (0 == *buffer[fd])
	{
		if ((read_ret = read(fd, buffer[fd], BUFF_SIZE)) <= 0)
			return (read_ret);
		buffer[fd][read_ret] = '\0';
	}
	read_ret = gnl(fd, line, &buffer[fd]);
	if (read_ret < 0)
		return (-1);
	if (0 == **line && read_ret == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	return (1);
}
