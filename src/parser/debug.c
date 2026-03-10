/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:48:25 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:47 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// static char	*get_node_type_str(t_node_type type)
// {
// 	if (type == N_CMD)
// 		return ("CMD");
// 	else if (type == N_PIPE)
// 		return ("PIPE");
// 	else if (type == N_AND)
// 		return ("AND");
// 	else if (type == N_OR)
// 		return ("OR");
// 	else if (type == N_REDIR_IN)
// 		return ("REDIR_IN");
// 	else if (type == N_REDIR_OUT)
// 		return ("REDIR_OUT");
// 	else if (type == N_HEREDOC)
// 		return ("HEREDOC");
// 	else if (type == N_APPEND)
// 		return ("APPEND");
// 	return ("UNKNOWN");
// }

// static char	*get_io_type_str(t_io_type type)
// {
// 	if (type == IO_IN)
// 		return ("<");
// 	else if (type == IO_OUT)
// 		return (">");
// 	else if (type == IO_HEREDOC)
// 		return ("<<");
// 	else if (type == IO_APPEND)
// 		return (">>");
// 	return ("?");
// }

// static void	print_io_list(t_io_node *io_list, int indent)
// {
// 	t_io_node	*current;
// 	int			i;

// 	current = io_list;
// 	while (current)
// 	{
// 		i = 0;
// 		while (i++ < indent)
// 			printf("  ");
// 		printf("  📄 IO: ");
// 		if (current->fd != 0 && current->fd != 1)
// 			printf("%d", current->fd);
// 		printf("%s %s\n", get_io_type_str(current->type), current->value);
// 		current = current->next;
// 	}
// }

// static void	print_command_args(char **args, int indent)
// {
// 	int	i;
// 	int	j;

// 	if (!args)
// 		return ;
// 	i = 0;
// 	while (args[i])
// 	{
// 		j = 0;
// 		while (j++ < indent)
// 			printf("  ");
// 		printf("  💬 Arg[%d]: \"%s\"\n", i, args[i]);
// 		i++;
// 	}
// }

// void	print_ast_recursive(t_node *node, int depth, char *prefix)
// {
// 	int	i;

// 	if (!node)
// 		return ;
// 	i = 0;
// 	while (i++ < depth)
// 		printf("  ");
// 	printf("%s", prefix);
// 	printf("🌳 [%s]\n", get_node_type_str(node->type));
// 	if (node->type == N_CMD)
// 	{
// 		if (node->expand_args)
// 			print_command_args(node->expand_args, depth);
// 		if (node->io_list)
// 			print_io_list(node->io_list, depth);
// 	}
// 	if (node->left)
// 	{
// 		i = 0;
// 		while (i++ < depth)
// 			printf("  ");
// 		printf("  ⬅️  LEFT:\n");
// 		print_ast_recursive(node->left, depth + 1, "");
// 	}
// 	if (node->right)
// 	{
// 		i = 0;
// 		while (i++ < depth)
// 			printf("  ");
// 		printf("  ➡️  RIGHT:\n");
// 		print_ast_recursive(node->right, depth + 1, "");
// 	}
// }
