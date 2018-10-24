/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 14:03:06 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 12:03:37 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_fill_line(char *str, char **line)
{
	int			i;
	char		*tmp;
	int			new_line;

	new_line = 0;
	i = 0;
	if (!(*str))
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		new_line = 1;
	*line = ft_strsub(str, 0, i);
	tmp = ft_strsub(str, i + new_line, ft_strlen(str));
	str = ft_strcpy(str, tmp);
	free(tmp);
	return (*line);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*str[0];
	char		*tmp;

	ret = 1;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!(str[fd]))
		str[fd] = ft_strnew(1);
	while (!ft_strchr(str[fd], '\n') && ret > 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			tmp = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = tmp;
		}
	}
	if (ret < 0)
		return (-1);
	if ((*line = ft_fill_line(str[fd], line)) == NULL)
		return (0);
	return (1);
}
