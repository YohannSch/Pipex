/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:34:02 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/06 19:34:02 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_everything(t_pipex *data)
{
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
	if (data->cmd1_args)
		free_tab(data->cmd1_args);
	if (data->cmd2_args)
		free_tab(data->cmd2_args);
	if (data->cmd1_path)
		free(data->cmd1_path);
	if (data->cmd2_path)
		free(data->cmd2_path);
	if (data->path_env)
		free_tab(data->path_env);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	pipex_init(t_pipex *data, char **argv, char **envp)
{
	data->infile = ft_strdup(argv[1]);
	if (data->infile == NULL)
		return (ERR_MALLOC);
	data->outfile = ft_strdup(argv[4]);
	if (data->outfile == NULL)
		return (free(data->infile), ERR_MALLOC);
	data->envp = envp;
	data->cmd1_args = ft_split(argv[2], ' ');
	if (data->cmd1_args == NULL)
		return (free(data->infile), free(data->outfile), ERR_MALLOC);
	data->cmd2_args = ft_split(argv[3], ' ');
	if (data->cmd2_args == NULL)
		return (free(data->infile), free(data->outfile),
			free_tab(data->cmd1_args), ERR_MALLOC);
	data->cmd1_path = NULL;
	data->cmd2_path = NULL;
	data->path_env = NULL;
	return (SUCCESS);
}

void	error_management(t_error err)
{
	if (err == ERR_ARGC)
		ft_putendl_fd("Error: Invalid number of arguments.", 2);
	else if (err == ERR_INFILE)
		ft_putendl_fd("Error: Unable to open input file.", 2);
	else if (err == ERR_OUTFILE)
		ft_putendl_fd("Error: Unable to open/create output file.", 2);
	else if (err == ERR_CMD1)
		ft_putendl_fd("Error: Command 1 not found.", 2);
	else if (err == ERR_CMD2)
		ft_putendl_fd("Error: Command 2 not found.", 2);
	else if (err == ERR_PIPE)
		ft_putendl_fd("Error: Pipe creation failed.", 2);
	else if (err == ERR_FORK)
		ft_putendl_fd("Error: Forking process failed.", 2);
	else if (err == ERR_DUP2)
		ft_putendl_fd("Error: Dup2 failed.", 2);
	else if (err == ERR_EXECVE)
		ft_putendl_fd("Error: Execve failed.", 2);
	else if (err == ERR_MALLOC)
		ft_putendl_fd("Error: Memory allocation failed.", 2);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		status;

	status = 0;
	if (argc != 5)
		return (error_management(ERR_ARGC), status);
	status = pipex_init(&data, argv, envp);
	if (status != SUCCESS)
		return (error_management(status), status);
	status = parsing(&data);
	if (status != SUCCESS)
		return (error_management(status), free_everything(&data), status);
	status = execute_pipex(&data);
	if (status != SUCCESS)
		return (error_management(status), free_everything(&data), status);
	free_everything(&data);
	return (SUCCESS);
}
