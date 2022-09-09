/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panda <panda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:51:57 by panda             #+#    #+#             */
/*   Updated: 2022/09/08 05:01:27 by panda            ###   ########.fr       */
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


void check_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] == ' ' && ((str[i + 1] == '>') || (str[i + 1] == '<') || str[i + 1] == '|'))
            delete_space_before(str, i);
        if(((str[i] == '>') || (str[i] == '<') || str[i] == '|') && str[i] == ' ')
            delete_space_after(str, i);
    }
    
}