/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:27:14 by hazali            #+#    #+#             */
/*   Updated: 2026/02/26 02:44:33 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_next_token(t_token **list_token)
{
	if (*list_token)
		*list_token = (*list_token)->next;
}

void	ft_free_tmp_arg(char **tmp_arg, int i)
{
	while (i > 0)
		free(tmp_arg[--i]);
	free(tmp_arg);
}

void	ft_free_expandes_args(char **expanded_args, int i)
{
	while (i > 0)
		free(expanded_args[--i]);
	free(expanded_args);
}
