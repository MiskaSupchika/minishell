/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:12:57 by panda             #+#    #+#             */
/*   Updated: 2022/09/05 00:26:19 by panda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

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

char *ft_cut(char *str, int i, int j)
{
    char *tmp;
    char *tmp1;
    char *tmp2;

    tmp = ft_substr(str, 0, j);
    tmp1 = ft_substr(str, j + 1, i - j - 1);
    tmp2 = ft_strdup(str + i + 1);
    tmp = ft_strjoin(tmp, tmp1);
    tmp = ft_strjoin(tmp, tmp2);
    free(tmp1);
    free(tmp2);
    return(tmp);
}

int key(char c)
{
    if(c == '_' || ft_isalnum(c))
        return 1;
    return 0;
}

char *cut_dollar(char *str, int *i, int j, char *tmp2)
{
    char *tmp3;
    char *tmp4;

    tmp3 = ft_substr(str, 0, j);
    tmp4 = ft_strdup(str + *i + 1);
    tmp3 = ft_strjoin(tmp3, tmp2);
    tmp3 = ft_strjoin(tmp3, tmp4);    
    free(tmp2);
    free(tmp4);
    return(tmp3);
}

char *dollar_pars2(char *tmp, char **envp)
{
    int t;
    char *tmp2;
    int k;

    k = 0;
    t = -1;
    while(envp[++t])
    {
        if(strstr(envp[t], tmp))
        {
            k = 0;
            while(envp[t][k] && envp[t][k] != '=')
                k++;
            tmp2 = ft_substr(envp[t], 0, k);
            if(strcmp(tmp, tmp2) == 0)
                break;
        }
    }
    tmp2 = ft_substr(envp[t], k + 1, ft_strlen(envp[t]) - k);
    return(tmp2);
}

char *dollar_pars(char *str, int *i, char **envp)
{
    int j;
    char *tmp;
    char *tmp2;
    char *dol;

    j = *i;
    while(str[++(*i)])
        if (!key(str[*i]))
            break ;
    if(*i == j + 1)
        return (str);
    tmp = ft_substr(str, j + 1, *i - j - 1);
    tmp2 = dollar_pars2(tmp, envp);
    dol = cut_dollar(str, i, j, tmp2);
    return(dol);
}

char *skip_character(char *str, int *i)
{
    
    char *tmp;     // функция вырезания символа
    char *tmp1;
    
    tmp = ft_substr(str, 0, *i);  // часть до символа
    tmp1 = ft_strdup(str + *i + 1); // часть после символа
    tmp = ft_strjoin(tmp, tmp1);
    ++(*i);
    free(tmp1);
    return(tmp);
}


char *ft_quote(char *str, int *i, char **envp)
{
    int j;       // если в строке была найдена двойная ковычка, то мы заходим сюда
    char *tmp;

    j = *i;
    while(str[++(*i)])
    {
        if(str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$' || str[*i + 1] == '\\'))
            skip_character(str, i);
        if(str[*i] == '$')
            dollar_pars(str, i, envp);
        if(str[*i] == '\"')
            break ;
    }
    tmp = ft_cut(str, *i, j);
    return(tmp);
    
}

char *ft_single_quote(char *str, int *i)
{
    int j;     // если в строке была найдена ковычка, то мы заходим сюда 
    int t;
    char *tmp;

    j = *i;
    while(str[++(*i)])   // идем по строке пока не найдем следущую ковычку
    {
        if(str[*i] == '\'')
            break ;
    }
    tmp = ft_cut(str, *i, j);  // вырезаем ковычки
    return(tmp);
}

void parser(char *str, char **envp)
{
    int i;

    i = -1;
    while(str[++i])
    {
        if(str[i] == '\'')
            str = ft_single_quote(str, &i);   // обрабатываем одну ковычку
        if(str[i] == '\"')
            str = ft_quote(str, &i, envp);    // также обрабатываем двойную ковычку
        if(str[i] == '\\')
            str = skip_character(str, &i);    // обработка слеша
        if(str[i] == '$')
            str = dollar_pars(str, &i, envp);  // обработка доллара
    }
    printf("str - %s\n", str);
}

int main(int argc, char **argv, char **env)
{
    char *str = strdup("k$USER l/sd'f/h  eljfgr\"jl\"\"fe'sgdgb'd/g'f");
    
    parser(str, env);
    return 0;
}