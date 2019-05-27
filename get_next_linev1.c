/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:49:32 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/09 16:58:49 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int		ret;

	if (!(*line = ft_strnew(ft_strlen(*line))))
			return (-1);
	while ((ret = read(fd, line, BUFF_SIZE)) > 0)
	{
		// check le(s) '\n'
		//line[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(*line);
	}
	ft_putnbr(ret);
	return (ret);
}

int main()
{
	int         fd;
	int         fd1;
//	int         fd2;
	int         ret;
	int         count_lines = 0;
	char        *line;
//	while (1)
//	{
		line = NULL;
		fd1 = open ( "/Users/rhoorntj/Desktop/get_next_line/text1.txt" , O_RDONLY);
//		fd2 = open("../test2.txt", O_RDONLY);
		fd = fd1;
		printf("%d", fd);
		printf("\n------\n");
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			printf("%s\n", line);
			ft_strdel(&line);
			count_lines++;
//			if (fd == fd1)
//				fd = fd2;
//			else
//				fd = fd1;
		}
		free(line);
		printf("\n------\nRet: %d\nLines: %d\n", ret, count_lines);
		close(fd1);
//		close(fd2);
//	}
	return(0);
}	


/*option to open file in text or binary mode with flag on read or open



  int fd;
  int ret;
  char buf [BUF_SIZE + 1];

  fd = open("42", O_RDONLY);
  if (fd == -1)
  {
  ft_putstr("open() error");
  return(1);
  }
  while (ret = read(fd, buf, BUF_SIZE))
  {
  but[ret] = '\0';
  ft_put*/
