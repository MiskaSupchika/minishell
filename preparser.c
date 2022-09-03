/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:59:13 by panda             #+#    #+#             */
/*   Updated: 2022/09/02 21:53:21 by rburner          ###   ########.fr       */
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

int check_quotes(char *str, int *i)
{
    if(str[*i] == '\'')
        while (str[++(*i)] != '\'' && str[*i])
            ;
    else if  (str[*i] == '\"')
        while (str[++(*i)] != '\"' && str[*i])
            ;
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

void wrong_quote(char *str)
{
    printf("wrong!!! - %s\n", str);
    
}

void check_quotes_wrong(char *str, int *i)
{
    printf("wrong!!! - %d\n", *i);
    
    if(str[*i] == '\'')
        while (str[++(*i)] != '\'' && str[*i])
            ;
    else if  (str[*i] == '\"')
        while (str[++(*i)] != '\"' && str[*i])
            ;
    printf("wrong!!! - %d\n", i);
    
    if (str[*i] == '\0')
        printf("blyat!!! - %s\n", str);
    else
        printf("qwer!!! - %s\n", str);
        

}

void check_error(char *str)
{
    int i;

    i = -1;
    while(str[++i])
    {
        
        if(str[i] == '\'' || str[i] == '\"')
        {
            printf("wronytyfhfg!!! - %d\n", i);
            
            check_quotes_wrong(str, &i);
        }
    }
}

void space(char *str)
{
    int i;
    
    i = -1;
    if(str[0] == ' ')
        str = delete_space_left(str, 0);
    str = delete_space_middle(str);
    printf("ng!!! - %s\n", str);
    
    check_error(str);
}


int main(int argc, char **argv, char **env)
{
    char *str = strdup("  k$USERl/sd'f/hel     jfgr\"jl\"\"fe'sg'd'g      bdgf");
    
    space(str);
    return 0;
}