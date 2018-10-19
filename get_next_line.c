/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 10:14:51 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 17:48:46 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

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

int				get_next_line(const int fd, char **line)
{
	char		*buf;
	int			ret;
	static char	*str[0];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!(buf = (char*)malloc(BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	free(buf);
	*line = ft_fill_line(str[fd], line);
	if (*line == NULL)
		return (0);
	return (1);
}
