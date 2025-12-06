/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:34:23 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/06 19:34:25 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	child_process1(t_pipex *data, int pipe_fd[2])
{
	int	infile_fd;

	infile_fd = open(data->infile, O_RDONLY);
	if (infile_fd < 0)
		return (close(pipe_fd[1]), close(pipe_fd[0]), ERR_INFILE);
	if (data->cmd1_path == NULL)
		return (close(pipe_fd[1]), close(pipe_fd[0]), close(infile_fd),
			ERR_CMD1);
	dup2(infile_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(infile_fd);
	close(pipe_fd[1]);
	execve(data->cmd1_path, data->cmd1_args, data->envp);
	return (ERR_EXECVE);
}

int	child_process2(t_pipex *data, int pipe_fd[2])
{
	int	outfile_fd;

	outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		return (close(pipe_fd[1]), close(pipe_fd[0]), ERR_OUTFILE);
	if (data->cmd2_path == NULL)
		return (close(pipe_fd[1]), close(pipe_fd[0]), close(outfile_fd),
			ERR_CMD2);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(outfile_fd);
	close(pipe_fd[0]);
	execve(data->cmd2_path, data->cmd2_args, data->envp);
	return (ERR_EXECVE);
}

int	execute_pipex(t_pipex *data)
{
	pid_t	child1;
	pid_t	child2;
	int		pipe_fd[2];
	int		status;

	if (pipe(pipe_fd) == -1)
		return (ERR_PIPE);
	child1 = fork();
	if (child1 < 0)
		return (ERR_FORK);
	if (child1 == 0)
		return (child_process1(data, pipe_fd));
	child2 = fork();
	if (child2 < 0)
		return (ERR_FORK);
	if (child2 == 0)
		return (child_process2(data, pipe_fd));
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	return (SUCCESS);
}
