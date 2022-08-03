/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:13 by panda             #+#    #+#             */
/*   Updated: 2022/08/03 18:06:05 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>



void	ft_err(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(0);
}



int		main(int argc, char **argv, char **env)
{
    (void) argc;
    (void) argv;
	char *cmd;

    write(1, "\033[46;36m Hello \033[0m\n", 21);
	while (1)
	{
		//write(1, "\033[45;31m Panda$ \033[0m", 21);
		cmd = readline(PANDA);
		if (!cmd)
            ft_err("\033[36m Exit \033[0m");
        add_history(cmd);
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		free(cmd);
	}
	exit(EXIT_SUCCESS);
}