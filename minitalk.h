/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:40:55 by jmaryett          #+#    #+#             */
/*   Updated: 2021/11/18 17:40:57 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

void	sv_handler(int signum, siginfo_t *siginfo, void *unused);
void	cl_handler(int signum, siginfo_t *sig, void *context);
int		send_str(int pid, char *s);
void	sending_bits(char c, int pid);

void	errors(char *s);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif