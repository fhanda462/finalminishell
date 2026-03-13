/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:46:44 by hazali            #+#    #+#             */
/*   Updated: 2026/02/26 02:28:19 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/parser.h"

// char *extract_var_name(char *str, int *index)
// {
//     int start;
//     int len;
//     char *var_name;

//     (*index)++; // Skip the '$'
//     if(str[*index] == '?')
//     {
//         (*index)++;
//         return (ft_strdup("?"));
//     }
//     start = *index;
//     while (str[*index] && !is_special_char(str[*index]))
//         (*index)++;
//     len = *index - start;
//     if (len == 0)
//         return (ft_strdup("?"));
//     var_name = ft_substr(str, start, len);
//     return (var_name);
// }

// char	*expand_variables(char *input, t_minishell *shell)
// {
// 	char	*result;
// 	char	*var_name;
// 	char	*var_value;
// 	char	*tmp;
// 	int		i;
// 	int		single_quote;
// 	int		double_quote;

// 	if (!input)
// 		return (NULL);
// 	result = ft_strdup("");
// 	i = 0;
// 	single_quote = 0;
// 	double_quote = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '\'' && !double_quote)
// 		{
// 			single_quote = !single_quote;
// 			i++;
// 			continue ;
// 		}
// 		if (input[i] == '"' && !single_quote)
// 		{
// 			double_quote = !double_quote;
// 			i++;
// 			continue ;
// 		}
// 		if (input[i] == '$' && !single_quote)
// 		{
// 			var_name = extract_var_name(input, &i);
// 			if (ft_strcmp(var_name, "$") != 0) // Pas un $ seul
// 			{
// 				var_value = get_var_value(var_name, shell);
// 				tmp = result;
// 				result = ft_strjoin(result, var_value);
// 				free(tmp);
// 				free(var_value);
// 			}
// 			else
// 			{
// 				tmp = result;
// 				result = ft_strjoin(result, "$");
// 				free(tmp);
// 			}
// 			free(var_name);
// 		}
// 		else
// 		{
// 			// Caractère normal
// 			tmp = result;
// 			result = ft_strjoin_char(result, input[i]);
// 			free(tmp);
// 			i++;
// 		}
// 	}
// 	return (result);
// }

// char	**expand_args(char **args, t_minishell *shell)
// {
// 	char	**expanded_args;
// 	int		i;

// 	if (!args)
// 		return (NULL);
// 	expanded_args = malloc(sizeof(char *) * (count_args(args) + 1));
// 	if (!expanded_args)
// 		return (NULL);
// 	i = 0;
// 	while (args[i])
// 	{
// 		expanded_args[i] = expand_variables(args[i], shell);
// 		i++;
// 	}
// 	expanded_args[i] = NULL;
// 	return (expanded_args);
// }

t_node	*ft_create_node(t_node_type type, t_node *left, t_node *right)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = type;
	node->left = left;
	node->right = right;
	node->io_list = NULL;
	node->args = NULL;
	node->expand_args = NULL;
	return (node);
}

t_io_node	*ft_create_io_node(t_io_type type, char *value, int fd)
{
	t_io_node	*io_node;
	char		*name_file;

	io_node = (t_io_node *)malloc(sizeof(t_io_node));
	if (!io_node)
		return (NULL);
	name_file = remove_quotes(value);
	io_node->type = type;
	io_node->value = name_file;
	io_node->fd = fd;
	if (!io_node->value)
	{
		free(io_node);
		return (NULL);
	}
	io_node->next = NULL;
	return (io_node);
}

int	ft_get_precedence(t_token_type type)
{
	if (type == T_PIPE)
		return (1);
	else if (type == T_AND || type == T_OR)
		return (2);
	return (0);
}

t_node	*ft_create_cmd_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = N_CMD;
	node->left = NULL;
	node->right = NULL;
	node->io_list = NULL;
	node->args = NULL;
	node->expand_args = NULL;
	return (node);
}

void	ft_add_io_node(t_io_node **io_list, t_io_node *new_io)
{
	t_io_node	*current;

	if (!*io_list)
	{
		*io_list = new_io;
		return ;
	}
	current = *io_list;
	while (current->next)
		current = current->next;
	current->next = new_io;
}
