/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 13:26:21 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-06 13:26:21 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdbool.h>

typedef struct s_list
{
	char	**cmd1;
	char	*cmd1path;
	char	**cmd2;
	char	*cmd2path;
	char	*infile;
	char	*outfile;
}				t_list;

bool	check_outfile_exists(char *outfile);
t_list	*init_struct(char **args, char *envp[]);
char	*get_path(char *envp[]);
char	*find_truepath(char *cmd, char *fullpath);
void	exec_cmd1(t_list *cmd_info, int pipe_fd[2], char *envp[]);
pid_t	exec_cmd2(t_list *cmd_info, int pipe_fd[2], char *envp[]);
void	free_struct(t_list *cmd_info);
void	free_split(char **splitpath);
char	*check_truecmd(char *cmd);

#endif