/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:34:11 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:32 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exec_and_or(t_node *node, t_minishell *shell)
{
	int	left_status;

	left_status = ft_execute(node->left, shell);
	if (node->type == N_AND)
	{
		if (left_status == 0)
			return (ft_execute(node->right, shell));
		return (left_status);
	}
	else if (node->type == N_OR)
	{
		if (left_status != 0)
			return (ft_execute(node->right, shell));
		return (left_status);
	}
	return (0);
}
