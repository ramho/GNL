/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:17:02 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/06/21 19:37:08 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		fill_next_line(char **line, const int fd, char **str)
{
	char		*tmp;

	if (ft_strchr(str[fd], '\n'))
	{
		*line = ft_strsub(str[fd], 0, ft_strchri(str[fd], '\n'));
		tmp = ft_strsub(str[fd], ft_strchri(str[fd], '\n') + 1,
				ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
		return (1);
	}
	if (ft_strchr(str[fd], '\0'))
	{
		*line = ft_strdup(str[fd]);
		if (!ft_strdup(str[fd]))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				read_fd(const int fd, char *buf, char **str)
{
	int			ret;
	char		*temp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			if (!(str[fd] = ft_strnew(1)))
				return (-1);
		temp = ft_strjoin(str[fd], buf);
		if (!ft_strjoin(str[fd], buf))
			return (-1);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	ret = read_fd(fd, buf, str);
	if (ret < 0)
		return (-1);
	else if (str[fd])
		fill_next_line(line, fd, str);
	else if (ret == 0 && str[fd] == NULL)
	{
		*line = NULL;
		return (0);
	}
	return (1);
}
