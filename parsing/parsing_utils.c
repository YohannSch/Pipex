/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:37:39 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/06 20:08:16 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_one(t_pipex *data, int cmd_number)
{
	if (cmd_number == 1)
	{
		if (data->cmd1_args[0] == NULL)
			return (SUCCESS);
		if (access(data->cmd1_args[0], X_OK) == 0)
		{
			data->cmd1_path = ft_strdup(data->cmd1_args[0]);
			if (data->cmd1_path == NULL)
				return (ERR_MALLOC);
			return (SUCCESS);
		}
	}
	else
	{
		if (data->cmd2_args[0] == NULL)
			return (SUCCESS);
		if (access(data->cmd2_args[0], X_OK) == 0)
		{
			data->cmd2_path = ft_strdup(data->cmd2_args[0]);
			if (data->cmd2_path == NULL)
				return (ERR_MALLOC);
			return (SUCCESS);
		}
	}
	return (15);
}

int	check_two(t_pipex *data, char *cmd_path, int cmd_number)
{
	if (access(cmd_path, X_OK) == 0)
	{
		if (cmd_number == 1)
			data->cmd1_path = cmd_path;
		else
			data->cmd2_path = cmd_path;
		return (SUCCESS);
	}
	return (15);
}
