/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:51:57 by panda             #+#    #+#             */
/*   Updated: 2022/09/25 12:23:50 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <pthread.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>


int count_space(int *i, char *str)
{
    int tmp;
    
    tmp = 0;
    while(str[++(*i)] == ' ')
        tmp++;
    return (tmp);
}


char *delete_space_before(char *str, int *i)
{
    char *tmp;
    char *tmp1;
    char *tmp2;
    int j = 0;

    tmp = ft_substr(str, 0, *i);
	tmp1 = ft_substr(str, *i, ft_strlen(str) - 1);
	tmp2 = ft_strjoin(tmp, tmp1);
	free(tmp);
	free(tmp1);
	free(str);
	(*i)--;
	return (tmp2);
    
    
}

char	*delete_space_after(char *str, int *i)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;

	temp1 = ft_substr(str, 0, *i + 1);
	temp2 = ft_substr(str, *i + 2, ft_strlen(str) - 1);
	temp3 = ft_strjoin(temp1, temp2);
	free(temp1);
	free(temp2);
	free(str);
	(*i)--;
    printf( "temp3 - %s\n", temp3);
	
	return (temp3);
}

char *check_space(char *str)
{
    int i;

    i = 0;

    while (str[i])
    {
        if (str[i] == '\'' && str[i] == '\"')
             check_quotes(str, i);
        else if(str[i] == ' ' && ((str[i + 1] == '>') || (str[i + 1] == '<') || str[i + 1] == '|'))
            str = delete_space_before(str, &i);
        else if((str[i] == '>' || str[i] == '<' || str[i] == '|') && str[i] == ' ')
            delete_space_after(str, &i);
		i++;
    }
    return (str);
}
