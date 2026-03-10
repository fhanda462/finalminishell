/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhanda <fhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:24:06 by hazali            #+#    #+#             */
/*   Updated: 2026/03/10 14:00:59 by fhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"
#include "../inc/minishell.h"
#include "../inc/utils.h"

// static void	ft_handler_signum(int signum)
// {
// 	if (signum == SIGINT)
// 	{
// 		// g_signum = signum;
// 		ft_putstr_fd("\n", STDOUT_FILENO);
// 		rl_replace_line("", STDIN_FILENO);
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// }

// int main(void)
// {
// 	char        *line;
// 	t_token     *tokens;
// 	t_node      *ast;
// 	t_minishell shell;

// 	// Initialiser le shell
// 	shell.exit_s = 0;
// 	shell.stdin = dup(STDIN_FILENO);
// 	shell.stdout = dup(STDOUT_FILENO);
// shell.environ = __environ;
// 	shell.envlst = init_env_list(shell.environ);
// TODO: initialiser la liste d'environnement

// 	while (1)
// 	{
// 		line = readline("minishell> ");
// 		if (!line)
// 		{
// 			printf("exit\n");
// 			break ;
// 		}
// 		if (!*line)
// 		{
// 			free(line);
// 			continue ;
// 		}
// 		add_history(line);

// 		// LEXER
// 		tokens = ft_lexer(line);
// 		if (!tokens)
// 		{
// 			shell.exit_s = 2;
// 			free(line);
// 			continue ;
// 		}
// 		// PARSER
// 		ast = ft_parsing(tokens, &shell);
// 		if (!ast)
// 		{
// 			ft_clear_all_token(&tokens);
// 			free(line);
// 			continue ;
// 		}

// 		// EXECUTION
// 		shell.exit_s = ft_execute(ast, &shell);

// 		// Cleanup
// 		ft_clear_all_token(&tokens);
// 		ft_clear_ast(&ast);
// 		free(line);
// 	}

// 	close(shell.stdin);
// 	close(shell.stdout);
// 	rl_clear_history();
// 	return (shell.exit_s);
// }

static void	init_shell(t_minishell *shell, char **envp)
{
	shell->exit_s = 0;
	shell->stdin = dup(STDIN_FILENO);
	shell->stdout = dup(STDOUT_FILENO);
	shell->environ = envp;
	shell->envlst = init_env_list(envp);
}

static void	cleanup_shell(t_minishell *shell)
{
	free_env_list(&shell->envlst);
	close(shell->stdin);
	close(shell->stdout);
	rl_clear_history();
}

static int	process_line(char *line, t_minishell *shell)
{
	t_token	*tokens;
	t_node	*ast;

	tokens = ft_lexer(line);
	if (!tokens)
	{
		shell->exit_s = 2;
		return (0);
	}
	ast = ft_parsing(tokens, shell);
	if (!ast)
	{
		ft_clear_all_token(&tokens);
		return (0);
	}
	shell->exit_s = ft_execute(ast, shell);
	ft_clear_all_token(&tokens);
	ft_clear_ast(&ast);
	return (1);
}

static void	main_loop(t_minishell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		if (!*line)
		{
			free(line);
			continue ;
		}
		add_history(line);
		process_line(line, shell);
		free(line);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_minishell	shell;

	(void)ac;
	(void)av;
	setup_signals();
	init_shell(&shell, envp);
	main_loop(&shell);
	cleanup_shell(&shell);
	return (shell.exit_s);
}
