/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:33:59 by hazali            #+#    #+#             */
/*   Updated: 2026/03/13 12:05:37 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <sys/ioctl.h>

static void	hd_sigint_handler(int sig)
{
	(void)sig;
	g_signal_received = SIGINT;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_done = 1;
}

int	handle_hd(char *delimiter)
{
	int					pipefd[2];
	char				*line;
	struct sigaction	sa;
	struct sigaction	sa_old;

	if (pipe(pipefd) == -1)
		return (perror("pipe"), -1);
	sa.sa_handler = hd_sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, &sa_old);
	g_signal_received = 0;
	while (!g_signal_received)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
			return (free(line), close(pipefd[1]), sigaction(SIGINT, &sa_old,
					NULL), pipefd[0]);
		write(pipefd[1], line, ft_strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
	}
	return (close(pipefd[1]), sigaction(SIGINT, &sa_old, NULL),
		close(pipefd[0]), -1);
}
