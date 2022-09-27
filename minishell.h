
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:48:45 by rburner           #+#    #+#             */
/*   Updated: 2022/01/12 06:04:02 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINISHELL_H
# define MINISHELL_H

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
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>


# define TERM_PURPLE		"\033[1;95m"
# define PANDA		"\033[31m Panda$ \033[0m"


typedef struct s_all
{
int flag;
t_list **list;
int i;

}   t_all;

// check_space.c
int count_space(int *i, char *str);
char *delete_space_before(char *str, int *i);
char	*delete_space_after(char *str, int *i);
char *check_space(char *str);

// error.c
void wrong_quote(char *str, char j);
void error_arrow(char *str, int i, int flag);

// get_next_line.c
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

// check.c
int check_quotes(char *str, int *i);
void check_quotes_wrong(char *str, int *i);
void check_right_left(char *str, int *i, int fl);
void check_dobble(char *str, int *i, int fl);
void    check_pipe(char *str, int *i);

// delete_space.c
int count_space(int *i, char *str);
char *delete_space_middle(char *str);
char *delete_space_left(char *str, int i);








void	print_prompt1(void);
void	print_prompt2(void);
char	*read_cmd(char *buf);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);

#endif 


