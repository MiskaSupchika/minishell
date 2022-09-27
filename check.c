/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:59:18 by panda             #+#    #+#             */
/*   Updated: 2022/09/25 12:32:49 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_quotes(char *str, int *i)
{
    if(str[*i] == '\'')
        while (str[++(*i)] != '\'' && str[*i])
            ;
    else if  (str[*i] == '\"')
        while (str[++(*i)] != '\"' && str[*i])
            ;
}

void check_quotes_wrong(char *str, int *i)
{
    char j;
    
    j = str[*i];
    if(str[*i] == '\'')
        while (str[++(*i)] != '\'' && str[*i])
            ;
    else if  (str[*i] == '\"')
        while (str[++(*i)] != '\"' && str[*i])
            ;
    if (str[*i] == '\0')
        wrong_quote(str, j);
}

void check_right_left(char *str, int *i, int fl)
{
    if (fl == 1)
    {
        if (str[*i + 1] == '|' && (str[*i + 2] == '>' || str[*i + 2] == '|' || str[*i + 2] == '<'))
            error_arrow(str, *i + 1, 0);
        else if (str[*i + 1] == ' ' && (str[*i + 2] == '>' || str[*i + 2] == '|' || str[*i + 2] == '<'))
            error_arrow(str, *i + 2, 1);
    }
    else if (fl == 0)
    {
        if (str[*i + 1] == '|' && (str[*i + 2] == '>' || str[*i + 2] == '|' || str[*i + 2] == '<'))
            error_arrow(str, *i + 1, 0);
        else if (str[*i + 1] == ' ' && (str[*i + 2] == '>' || str[*i + 2] == '|' || str[*i + 2] == '<'))
            error_arrow(str, *i + 2, 1);
    }
}

void check_dobble(char *str, int *i, int fl)
{
    if (fl == 1)
    {
        if (str[*i + 1] == '>' || str[*i + 1] == '|' || str[*i + 1] == '<')
            error_arrow(str, *i + 1, 0);
        else if (str[*i + 1] == ' ' && (str[*i + 2] == '>' || str[*i + 2] == '|' || str[*i + 2] == '<'))
            error_arrow(str, *i + 2, 1);
    }
    else if (fl == 0)
    {
        if (str[*i + 1] == '>' || str[*i + 1] == '|' || str[*i + 1] == '<')
            error_arrow(str, *i + 1, 0);
        else if (str[*i + 1] == ' ' && (str[*i + 2] == '>' || str[*i + 2] == '|' || str[*i + 2] == '<'))
            error_arrow(str, *i + 2, 1);
    }
}

void    check_pipe(char *str, int *i)
{
    if ((str[*i + 1] == '<' || str[*i + 1] == '>') && (str[*i + 2] == '<' || str[*i + 2] == '>') && str[*i + 3] == '|') // |
        error_pipe(*i + 3);
    if ((str[*i + 1] == '<' || str[*i + 1] == '>') && (str[*i + 2] == '<' || str[*i + 2] == '>') && str[*i + 3] == '|' && str[*i + 4] == '|') // ||
        error_pipe(*i + 3);
    if (str[*i + 1] == '<' && str[*i + 2] == '|')  // |
		error_pipe(*i);
	else if (str[*i + 1] == '>' && str[*i + 2] == '<')  // <
		error_pipe(*i + 2);
	else if (str[*i + 1] == '>' && str[*i + 2] == '|' && (str[*i + 3] == '|' || (str[*i + 3] == '<' || str[*i + 3] == '<')))  // |
		error_pipe(*i);
	else if (str[*i + 1] == '>' && str[*i + 2] == '>' && (str[*i + 3] == '|' || (str[*i + 3] == '<' || str[*i + 3] == '<')))  // |
		error_pipe(*i);
	else if (str[*i + 1] == ' ' && (str[*i + 2] == '|'))  // |
		error_pipe(*i);
}
