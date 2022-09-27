/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:41:28 by panda             #+#    #+#             */
/*   Updated: 2022/09/25 15:35:09 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list lists(char *str, char **envp)
{
    int i;
    t_all all;
    t_list *list;
    
    list = NULL;
    i = -1;
	all.i = 0;
	while (str[++i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			check_quotes(str, &i);
		else if (str[i] == '|')
			list = new_list_one(str, &all, &list, i);
		else if (check_redirect(str[i]) && str[i + 1] != '<' && str[i + 1] != '>')
			list = new_list_one(str, &all, &list, i);
		else if (check_redirect(str[i]) && (str[i + 1] == '<' || str[i + 1] == '>'))
			list = new_list_two(str, &all, &list, &i);
	}
	list = new_list_one(str, &all, &list, i);
	creation_array(&list, &all);
	send_parsing(&list, envp);
	return (list);
}