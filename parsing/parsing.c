/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:40:18 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/06 21:40:26 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin_path(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(len1 + len2 + 2);
	if (joined == NULL)
		return (NULL);
	ft_strcpy(joined, s1);
	joined[len1] = '/';
	ft_strcpy(joined + len1 + 1, s2);
	return (joined);
}

int	find_command_path(t_pipex *data, int cmd_number)
{
	char	**cmd_args;
	char	*cmd_path;
	int		i;

	if (handle_absolute_path(data, cmd_number))
		return (SUCCESS);
	cmd_args = determine_command_args(data, cmd_number);
	i = 0;
	while (data->path_env && data->path_env[i] != NULL)
	{
		cmd_path = ft_strjoin_path(data->path_env[i], cmd_args[0]);
		if (cmd_path == NULL)
			return (ERR_MALLOC);
		if (access(cmd_path, X_OK) == 0)
		{
			if (cmd_number == 1)
				data->cmd1_path = cmd_path;
			else
				data->cmd2_path = cmd_path;
			return (SUCCESS);
		}
		free(cmd_path);
		i++;
	}
	return (SUCCESS);
}

int	create_path_env(t_pipex *data)
{
	int		i;
	char	*path_str;

	i = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
		{
			path_str = ft_strdup(data->envp[i] + 5);
			if (path_str == NULL)
				return (ERR_MALLOC);
			data->path_env = ft_split(path_str, ':');
			free(path_str);
			if (data->path_env == NULL)
				return (ERR_MALLOC);
			return (SUCCESS);
		}
		i++;
	}
	return (SUCCESS);
}

int	parsing(t_pipex *data)
{
	int	status;

	status = create_path_env(data);
	if (status != SUCCESS)
		return (status);
	status = find_command_path(data, 1);
	if (status != SUCCESS)
		return (status);
	status = find_command_path(data, 2);
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}
