/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 10:28:27 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 13:38:50 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char			*ft_fill_tab(char *buf, char **line, char *str)
{
	int			i;
	int			fill_str;
	char		*tmp;

	i = 0;
	fill_str = 0;
	tmp = ft_strdup(buf);
	while (tmp[i] != '\n')
		i++;
	printf("i = %d", i);
	if (i < (BUFF_SIZE))
		str = ft_memalloc((BUFF_SIZE) - i);
	while (i++ < (BUFF_SIZE))
	{
		if (buf[i] != '\n')
			str[fill_str] = buf[i];
		printf("str[%d] = %c\n", fill_str, str[fill_str]);
		fill_str++;
	}
	str[fill_str] = '\0';
	printf("fill_str = %d\n", fill_str);
	printf("str = %s\n", str);
	*line = ft_strdup(tmp);
	free (tmp);
	return (*line);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char *str;
	int			i;
	int			new_line;

	new_line = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0 && new_line == 0)
	{
		buf[ret] = '\0';
		i = 0;
		while (buf[i] && new_line == 0)
		{
			if (buf[i] == '\n')
				new_line++;
			i++;
		}
		ft_fill_tab(buf, line, str);
	}
	if (line == NULL)
		return (0);
	return (1);
}

int				main(int ac, char **av)
{
	int			fd;
	char		*line;

	ac = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	free(line);
	close (fd);
}

/*int			main(int argc, char **argv)
{
	int			fd;
	char		*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_putstr("\n le fd open est -->");
		ft_putnbr(fd);
		ft_putchar('\n');
	}
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}*/
