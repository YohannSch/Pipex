/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:37:39 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/06 21:40:03 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**determine_command_args(t_pipex *data, int cmd_number)
{
	if (cmd_number == 1)
		return (data->cmd1_args);
	else
		return (data->cmd2_args);
}

bool	handle_absolute_path(t_pipex *data, int cmd_number)
{
	if (cmd_number == 1)
	{
		if (data->cmd1_args[0] == NULL)
			return (true);
		if (access(data->cmd1_args[0], X_OK) == 0)
		{
			data->cmd1_path = ft_strdup(data->cmd1_args[0]);
			if (data->cmd1_path == NULL)
				return (true);
			return (true);
		}
	}
	else
	{
		if (data->cmd2_args[0] == NULL)
			return (true);
		if (access(data->cmd2_args[0], X_OK) == 0)
		{
			data->cmd2_path = ft_strdup(data->cmd2_args[0]);
			if (data->cmd2_path == NULL)
				return (true);
			return (true);
		}
	}
	return (false);
}
