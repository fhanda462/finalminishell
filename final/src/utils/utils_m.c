/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 05:04:18 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:19:49 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	main(int ac, char **av, char **env)
// {
// 	// int				s;
// 	(void)env;
// 	(void)av;
// 	(void)ac;
// 	// t_minishell minishell;
// 	// t_token *token = NULL;
// 	// while (1)
// 	// {
// 	// 	signal(SIGINT, &ft_handler_signum);
// 	// 	signal(SIGQUIT, SIG_IGN);
// 	// 	minishell.line = readline("MINISHELL > ");
// 	// 	if (!minishell.line)
// 	// 		break ;
// 	// 	token = ft_lexer(minishell.line);
// 	// 	// if(token)
// 	// 	// {
// 	// 	// 	printf("%s", token->value);
// 	// 	// 	break ;
// 	// 	// }
// 	// }
// 	// if (isatty(STDIN_FILENO))
// 	// 	write(2, "exit\n", 6);
// 	// return (0);
// 	while (1)
// 	{
// 		printf("MINISHELL > ");
// 	}
// }
// int main(void)
// {
//     char *line;
//     t_token *tokens;
//     // t_node  ast;
//     printf("=== MINISHELL LEXER TESTS ===\n\n");
//     while (1)
//     {
//         // Utiliser readline pour avoir l'historique et l'édition
//         line = readline("minishell> ");
//         // Ctrl+D (EOF)
//         if (!line)
//         {
//             printf("exit\n");
//             break ;
//         }
//         // Ligne vide
//         if (!*line)
//         {
//             free(line);
//             continue ;
//         }
//         // Ajouter à l'historique
//         add_history(line);
//         // Tokeniser
//         tokens = ft_lexer(line);
//         // ast = ft_parsing(tokens);
//         if (!tokens)
//         {
//             printf("❌ Syntax error detected\n");
//         }
//         else
//         {
//             print_tokens(tokens);
//             ft_clear_all_token(&tokens);
//         }
//         free(line);
//     }
//     // Nettoyer l'historique
//     rl_clear_history();
//     return (0);
// }

// int	main(void)
// {
// 	char	*line;
// 	t_token	*tokens;
// 	t_node	*ast;

// 	printf("╔════════════════════════════════════════════════════════════╗\n");
// 	printf("║        🐚 MINISHELL - DEBUG MODE (LEXER + PARSER)        ║\n");
// 	printf("╚════════════════════════════════════════════════════════════╝\n");
// 	printf("\n💡 Tips:\n");
// 	printf("  - Type 'exit' to quit\n");
// 	printf("  - Type 'clear' to clear screen\n");
// 	printf("  - Empty line = ignored\n\n");
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
// 		// === LEXER ===
// 		printf("\n┌─── 📋 LEXER OUTPUT ─────────────────────────────────\n");
// 		tokens = ft_lexer(line);
// 		if (!tokens)
// 		{
// 			printf("│ ❌ Syntax error detected in lexer\n");
// 			printf("└────────────────────────────────────────────────\n\n");
// 			free(line);
// 			continue ;
// 		}
// 		print_tokens(tokens);
// 		printf("└───────────────────────────────────────────────────\n");
// 		// === PARSER ===
// 		printf("\n┌─── 🌳 PARSER OUTPUT ────────────────────────────\n");
// 		ast = ft_parsing(tokens);
// 		if (!ast)
// 		{
// 			printf("│ ❌ Parsing failed\n");
// 			printf("└───────────────────────────────────────────────────\n\n");
// 			ft_clear_all_token(&tokens);
// 			free(line);
// 			continue ;
// 		}
// 		printf("│ ✅ Parsing successful!\n");
// 		printf("└─────────────────────────────────────────────\n");
// 		// === AST DEBUG ===
// 		ft_print_ast(ast);
// 		// Cleanup
// 		ft_clear_all_token(&tokens);
// 		ft_clear_ast(&ast);
// 		free(line);
// 	}
// 	rl_clear_history();
// 	return (0);
// }

// void test_basic_redirections(void)
// {
//     printf("\n=== TEST 1: Redirections basiques ===\n");
//     char *tests[] = {
//         "cat < input.txt",          // fd=0 implicite
//         "echo hello > output.txt",  // fd=1 implicite
//         "cat << EOF",               // fd=0 implicite
//         "echo test >> log.txt",     // fd=1 implicite
//         NULL
//     };
//     for (int i = 0; tests[i]; i++)
//     {
//         printf("\nInput: %s\n", tests[i]);
//         t_token *tokens = ft_lexer(tests[i]);
//         if (tokens)
//         {
//             print_tokens(tokens);
//             t_node *ast = ft_parsing(tokens);
//             if (ast)
//             {
//                 ft_print_ast(ast);
//                 ft_clear_ast(&ast);
//             }
//             ft_clear_all_token(&tokens);
//         }
//     }
// }

// void test_explicit_fd_redirections(void)
// {
//     printf("\n=== TEST 2: Redirections avec FD explicites ===\n");
//     char *tests[] = {
//         "cat 2> err.txt",               // stderr vers err.txt
//         "ls -la 1> out.txt 2> err.txt", // stdout et stderr séparés
//         "echo test 1>> log.txt",        // stdout en append
//         "cat 2>> errors.log",           // stderr en append
//         "cmd 3> file3.txt",             // fd custom 3
//         "cmd 0< input.txt 1> out.txt 2> err.txt", // Triple redirection
//         NULL
//     };
//     for (int i = 0; tests[i]; i++)
//     {
//         printf("\nInput: %s\n", tests[i]);
//         t_token *tokens = ft_lexer(tests[i]);
//         if (tokens)
//         {
//             print_tokens(tokens);
//             t_node *ast = ft_parsing(tokens);
//             if (ast)
//             {
//                 ft_print_ast(ast);
//                 ft_clear_ast(&ast);
//             }
//             ft_clear_all_token(&tokens);
//         }
//     }
// }
// void test_multiple_redirections(void)
// {
//     printf("\n=== TEST 3: Redirections multiples ===\n");
//     char *tests[] = {
//         "cat < in1.txt < in2.txt",      // Double input (dernier gagne)
//         "echo test > out1.txt > out2.txt", // Double output (dernier gagne)
//         "cat < input.txt > output.txt 2> error.txt", // Triple redirection
//         "cmd 1> out.txt 2> err.txt 3> custom.txt",   // 3 fd différents
//         NULL
//     };
//     for (int i = 0; tests[i]; i++)
//     {
//         printf("\nInput: %s\n", tests[i]);
//         t_token *tokens = ft_lexer(tests[i]);
//         if (tokens)
//         {
//             print_tokens(tokens);
//             t_node *ast = ft_parsing(tokens);
//             if (ast)
//             {
//                 ft_print_ast(ast);
//                 ft_clear_ast(&ast);
//             }
//             ft_clear_all_token(&tokens);
//         }
//     }
// }

// void test_pipes_with_fd(void)
// {
//     printf("\n=== TEST 4: Pipes avec redirections FD ===\n");
//     char *tests[] = {
//         "cat < in.txt | grep test",
//         "ls -la 2> err.txt | wc -l",
//         "cat file.txt | grep test > out.txt 2> err.txt",
//         "cmd1 2> err1.txt | cmd2 2> err2.txt | cmd3 > final.txt",
//         NULL
//     };
//     for (int i = 0; tests[i]; i++)
//     {
//         printf("\nInput: %s\n", tests[i]);
//         t_token *tokens = ft_lexer(tests[i]);
//         if (tokens)
//         {
//             print_tokens(tokens);
//             t_node *ast = ft_parsing(tokens);
//             if (ast)
//             {
//                 ft_print_ast(ast);
//                 ft_clear_ast(&ast);
//             }
//             ft_clear_all_token(&tokens);
//         }
//     }
// }
// void test_edge_cases(void)
// {
//     printf("\n=== TEST 5: Cas limites ===\n");
//     char *tests[] = {
//         "cat 0< in.txt",        // fd 0 explicite
//         "echo test 1> out.txt", // fd 1 explicite
//         "cmd 9> file9.txt",     // fd très élevé
//         "cat 2> err.txt < in.txt > out.txt", // Ordre mélangé
//         NULL
//     };
//     for (int i = 0; tests[i]; i++)
//     {
//         printf("\nInput: %s\n", tests[i]);
//         t_token *tokens = ft_lexer(tests[i]);
//         if (tokens)
//         {
//             print_tokens(tokens);
//             t_node *ast = ft_parsing(tokens);
//             if (ast)
//             {
//                 ft_print_ast(ast);
//                 ft_clear_ast(&ast);
//             }
//             ft_clear_all_token(&tokens);
//         }
//     }
// }
// void print_test_summary(void)
// {
//     printf("\n");
//     printf("╔══════════════════════════════════════════════════════════╗\n");
//     printf("║              📊 TEST SUMMARY                              ║\n");
//     printf("╚══════════════════════════════════════════════════════════╝\n");
//     printf("\n");
//     printf("Tests effectués:\n");
//     printf("  ✅ Redirections basiques (<, >, <<, >>)\n");
//     printf("  ✅ Redirections avec FD explicites (2>, 3<, etc.)\n");
//     printf("  ✅ Redirections multiples\n");
//     printf("  ✅ Pipes avec redirections FD\n");
//     printf("  ✅ Cas limites\n");
//     printf("\n");
//     printf("Fonctionnalités testées:\n");
//     printf("  • Détection des FD explicites dans le lexer\n");
//     printf("  • Parsing correct des redirections avec FD\n");
//     printf("  • Création de l'AST avec io_list contenant les FD\n");
//     printf("  • Affichage correct des FD dans print_ast\n");
//     printf("\n");
//     printf("Prochaine étape:\n");
//     printf("  → Implémenter l'exécution avec apply_redirections()\n");
//     printf("\n");
// }
// int main(void)
// {
//     printf("╔══════════════════════════════════════════════════════════╗\n");
//     printf("║     🧪 TEST SUITE - FD REDIRECTIONS                      ║\n");
//     printf("╚══════════════════════════════════════════════════════════╝\n");
//     test_basic_redirections();
//     test_explicit_fd_redirections();
//     test_multiple_redirections();
//     test_pipes_with_fd();
//     test_edge_cases();
//     print_test_summary();
//     return (0);
// }