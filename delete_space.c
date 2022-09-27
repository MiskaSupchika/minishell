/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:59:13 by panda             #+#    #+#             */
/*   Updated: 2022/09/25 12:33:12 by panda            ###   ########.fr       */
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

char *delete_space_middle(char *str)
{
    int space;
    char *tmp;
    int c_space;
    
    space = -1;
    while(str[++space])
    {
        if(str[space] == '\'' || str[space] == '\"')
            check_quotes(str, &space);
        else if (str[space] == ' ')
            break ;
    } 
    tmp = ft_substr(str, 0, space + 1);
    printf("srt - %s\n", tmp);
    free(str);
    return(tmp);
}

char *delete_space_left(char *str, int i)
{
    char *tmp;
    int count;
    char *tmp2;

    count = count_space(&i, str);
    tmp2 = ft_substr(str, count + 1, ft_strlen(str));
    printf("srt2 - %s\n", tmp2);
    free(str);
    return(tmp2);
}



