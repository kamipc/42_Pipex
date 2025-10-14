/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 14:50:15 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-06 14:50:15 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

char	*check_truecmd(char *cmd)
{
	int		i;
	char	*temp;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	i = ft_strlen(cmd);
	while (i > 0 && cmd[--i])
	{
		if (cmd[i] == '/')
		{
			temp = ft_substr(cmd, i + 1, ft_strlen(cmd));
			free(cmd);
			return (temp);
		}
	}
	return (cmd);
}

bool	check_outfile_exists(char *outfile)
{
	int	fd;

	if (access(outfile, F_OK) != 0)
	{
		fd = open(outfile, O_WRONLY | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fd == -1)
		{
			perror("Failed to create outfile");
			return (false);
		}
		else
		{
			close(fd);
		}
	}
	return (true);
}

void	free_split(char **splitpath)
{
	int	i;

	i = 0;
	while (splitpath[i])
	{
		free(splitpath[i]);
		i++;
	}
	free(splitpath);
}

void	free_struct(t_list *cmd_info)
{
	int	i;

	i = 0;
	while (cmd_info->cmd1[i])
	{
		free(cmd_info->cmd1[i]);
		i++;
	}
	free(cmd_info->cmd1);
	i = 0;
	while (cmd_info->cmd2[i])
	{
		free(cmd_info->cmd2[i]);
		i++;
	}
	free(cmd_info->cmd2);
	free(cmd_info->cmd1path);
	free(cmd_info->cmd2path);
	free(cmd_info);
}
