/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:50:41 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/14 15:12:35 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

/* BUFF_SIZE macro permettnt de choisir la taille du buffer READ*/
#define BUFF_SIZE 10
// [OPEN_MAX][..]

int		get_next_line(const int fd, char **line);

#endif
