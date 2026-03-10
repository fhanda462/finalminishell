/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:31:53 by hazali            #+#    #+#             */
/*   Updated: 2026/02/25 04:42:41 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_ast(t_node **ast)
{
	if (!*ast)
		return ;
	ft_clear_ast(&(*ast)->left);
	ft_clear_ast(&(*ast)->right);
	if ((*ast)->expand_args)
		free_args((*ast)->expand_args);
	if ((*ast)->io_list)
		free_io_list((*ast)->io_list);
	free(*ast);
	*ast = NULL;
}
