/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:02:36 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/14 15:21:47 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

//ecrire une fonction pour calcuer la taille du malloc de *line

int		get_next_line(const int fd, char **line)
{
	int		ret;
	static	char *mem;
	int i;

	i = 0;
	*line = malloc(BUFF_SIZE);
	ret = read(fd, mem, BUFF_SIZE);
	if (ret < 0 || BUFF_SIZE < 0 || !line)
			return(-1)
	while((ret = read(fd, mem, BUFF_SIZE)) != 0)
	{
		//creer index de ft_strchr
		line = ft_strsub(mem, 0, ft_strchri(mem,'\n'));
		tmp = ft_strsub(mem, ft_strchri(mem, '\n') + 1, ft_strlen(mem));
		free(mem);
		mem = ft_strdup(tmp);
		free(tmp);
		}
	}

}



int main()
{
	int fd;
	int	ret;
	char *line;

	fd = open("text1.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	ret = get_next_line(fd, &line);
	printf("%d\n", fd);
	printf("--------\n");
	printf("--------\nje lis: %d bit (ret).\n", ret);
	close(fd);
	return (0);
	}
