/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:34:06 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/06 20:05:21 by yscheupl         ###   ########.fr       */
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
int			parsing(t_pipex *data);
int			execute_pipex(t_pipex *data);
int			check_one(t_pipex *data, int cmd_number);
int			check_two(t_pipex *data, char *cmd_path, int cmd_number);

#endif