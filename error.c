/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:03:10 by panda             #+#    #+#             */
/*   Updated: 2022/09/25 12:09:46 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void wrong_quote(char *str, char j)
{
    write(2, "Panda: syntax error - unclosed quote ", 36);
    write(2, &j, 1);
	write(2, "\n", 1);
}

void error_arrow(char *str, int i, int flag)
{
    if (flag == 1)
    {
        write(2, "Mini: syntax error near unexpected token ", 42);
        write(2, &i, 1);
	    write(2, "\n", 1);
    }
}