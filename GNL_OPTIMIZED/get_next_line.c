/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 10:14:51 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/21 04:00:32 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char			*ft_fill_line(char *str, char **line)
{
	int			i;
	char		*tmp;
	int			verif;

	i = 0;
	verif = 0;
	if (!(*str))
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		verif++;
	*line = ft_strsub(str, 0, i);
	tmp = ft_strsub(str, i + verif, (ft_strlen(str)));
	str = ft_strcpy(str, tmp);
	free(tmp);
	return (*line);
}

int				ft_check_line(char *buf, int fd, char **str)
{
	int			i;
	int			fill_tmp;
	char		*tmp;

	i = 0;
	if (!str[fd])
		str[fd] = ft_strnew(1);
	fill_tmp = ft_strlen(str[fd]);
//	printf("str=%s\n", str[fd]);
	tmp = ft_strjoin(str[fd], buf);
//	printf("buf=%s\n", buf);
//	printf("tmp =%s\n", tmp);
	free(str[fd]);
	while (buf[i] && buf[i] != '\n')
	{
		tmp[fill_tmp] = buf[i];
//		printf("buf[%d] = %c ----> tmp[%d] = %c\n", i, buf[i], fill_tmp, tmp[fill_tmp]);
		i++;
		fill_tmp++;
	}
		if (buf[i])
	{
		while (buf[i])
		{
			tmp[fill_tmp] = buf[i];
//			printf("BUF2[%d] = %c ----> TMP2[%d] = %c\n", i, buf[i], fill_tmp, tmp[fill_tmp]);
			i++;
			fill_tmp++;
		}
		str[fd] = tmp;
			return (1);
	}
		str[fd] = tmp;
//		printf("\n\nSTRFINAL=%s\n", str[fd]);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*str[0];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
			//|| !(buf = (char*)malloc(BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && ft_check_line(buf, fd, str) == 0)
		buf[ret] = '\0';
//	free(buf);
	if (ret < 0)
		return (-1);
	*line = ft_fill_line(str[fd], line);
	if (*line == NULL)
		return (0);
	return (1);
}

/*int			main(int ac, char **av)
{
	int		fd;
	char	*line;

	ac = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("res=%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("res2=%s\n", line);
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
