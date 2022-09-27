/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:13 by panda             #+#    #+#             */
/*   Updated: 2022/09/25 14:41:23 by panda            ###   ########.fr       */
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

// проверяет есть ли дичь после знаков
int check_error(char *str, int i)
{
    while(str[++i])
    {
        if(str[i] == '\'' || str[i] == '\"')
            check_quotes_wrong(str, &i);
        else if (str[i] == '>' && str[i + 1] == '>')
            check_double(str, &i + 1);
        else if (str[i] == '<' && str[i + 1] == '<')
            check_double(str, &i + 1);
        else if (str[i] == '<')
            check_right_left(str, &i, 1);
        else if (str[i] == '>')
            check_right_left(str, &i, 1);
        else if (str[i] == '|')
            check_pipe(str, &i);
    }
	return (0);
}


int process(char **str)
{
    int i;
    
    i = -1;
    if(*str[0] == ' ')
        *str = delete_space_left(str, 0);
    *str = delete_space_middle(str);
    printf("ng!!! - %s\n", str);
    if (check_error(*str, i) == 1)
		return (1);
	*str = check_space(*str);
	return (0);
}

int		main(int argc, char **argv, char **env)
{
    (void) argc;
    (void) argv;
	char *cmd;
	t_list *list;

    write(1, "\033[46;36m Hello \033[0m\n", 21);
	while (1)
	{
		cmd = readline(PANDA);
		if (!cmd)
            ft_err("\033[36m Exit \033[0m");
        add_history(cmd);
		if (process(cmd) == 0)
		{
			list = lists(cmd, env);
		}
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		free(cmd);
	}
	exit(EXIT_SUCCESS);
}