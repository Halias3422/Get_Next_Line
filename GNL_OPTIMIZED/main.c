/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 10:14:51 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/21 03:29:47 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../GNL_Perso/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
//	char	*line2;
//	int		fd2;

	line = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
//		fd2 = open(argv[1], O_RDONLY);
//		printf("fd = %d -- fd2 = %d\n", fd, fd2);
		ft_putstr("\n le fd open est -->");
		ft_putnbr(fd);
		ft_putchar('\n');
	}
	else
		return (2);
/*	get_next_line(fd, &line);
	printf("\nres =%s\n\n -------------------- \n", line);
	//	ft_putendl(line);
	free(line);
	get_next_line(fd, &line);
	printf("\nres =%s\n\n -------------------- \n", line);
//	ft_putendl(line);
	free(line);*/
/*	get_next_line(fd, &line);
//	ft_putendl(line);
	printf("\nres =%s\n\n --------------------- \n", line);
	free(line);*/
	while (get_next_line(fd, &line) == 1)
	{
		while (get_next_line(fd2, &line2) == 1)
		{
			ft_putendl(line2);
			free(line2);
		}
	//	ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
