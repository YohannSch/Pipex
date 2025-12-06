/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:34:06 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/06 21:43:34 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**envp;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**path_env;
}			t_pipex;

typedef enum e_error
{
	SUCCESS,
	ERR_ARGC,
	ERR_INFILE,
	ERR_OUTFILE,
	ERR_CMD1,
	ERR_CMD2,
	ERR_PIPE,
	ERR_FORK,
	ERR_DUP2,
	ERR_EXECVE,
	ERR_MALLOC,
	ERR_PATH
}			t_error;

void		free_tab(char **tab);
void		free_everything(t_pipex *data);
int			parsing(t_pipex *data);
int			create_path_env(t_pipex *data);
int			find_command_path(t_pipex *data, int cmd_number);
int			execute_pipex(t_pipex *data);
int			pipex_init(t_pipex *data, char **argv, char **envp);
void		error_management(t_error err);
int			child_process2(t_pipex *data, int pipe_fd[2]);
int			child_process1(t_pipex *data, int pipe_fd[2]);
char		*ft_strjoin_path(char *s1, char *s2);
char		**determine_command_args(t_pipex *data, int cmd_number);
bool		handle_absolute_path(t_pipex *data, int cmd_number);

#endif