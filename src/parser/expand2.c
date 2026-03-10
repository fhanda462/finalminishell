/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:31:46 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:30:44 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
// 		if (input[i] == '\"' && !single_quote)
// 		{
// 			double_quote = !double_quote;
// 			i++;
// 			continue ;
// 		}
// 		if (input[i] == '$' && !single_quote)
// 		{
// 			var_name = extract_var_name(input, &i);
// 			if (var_name[0] != '\0')
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
// 			tmp = result;
// 			result = ft_strjoin_char(result, input[i]);
// 			free(tmp);
// 			i++;
// 		}
// 	}
// 	return (result);
// }

static int	toggle_quote(char *input, int *i, int *sq, int *dq)
{
	if (input[*i] == '\'' && !(*dq))
	{
		*sq = !*sq;
		(*i)++;
		return (1);
	}
	if (input[*i] == '\"' && !(*sq))
	{
		*dq = !*dq;
		(*i)++;
		return (1);
	}
	return (0);
}

static char	*append_char(char *result, char c)
{
	char	*tmp;

	tmp = result;
	result = ft_strjoin_char(result, c);
	free(tmp);
	return (result);
}

static char	*process_dollar(char *result, char *input, int *i,
		t_minishell *shell)
{
	char	*var_name;
	char	*var_value;
	char	*tmp;

	var_name = extract_var_name(input, i);
	if (var_name[0] != '\0')
	{
		var_value = get_var_value(var_name, shell);
		tmp = result;
		result = ft_strjoin(result, var_value);
		free(tmp);
		free(var_value);
	}
	else
	{
		tmp = result;
		result = ft_strjoin(result, "$");
		free(tmp);
	}
	free(var_name);
	return (result);
}

char	*expand_variables(char *input, t_minishell *shell)
{
	char	*result;
	int		i;
	int		sq;
	int		dq;

	if (!input)
		return (NULL);
	result = ft_strdup("");
	i = 0;
	sq = 0;
	dq = 0;
	while (input[i])
	{
		if (toggle_quote(input, &i, &sq, &dq))
			continue ;
		if (input[i] == '$' && !sq)
			result = process_dollar(result, input, &i, shell);
		else
			result = append_char(result, input[i++]);
	}
	return (result);
}
