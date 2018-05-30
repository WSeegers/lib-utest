/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 06:17:58 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 03:33:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTEST_H
# define UTEST_H

#include <sys/wait.h>
#include <stdbool.h>

typedef	struct 	s_test
{
	char			*desc;
	int				(*f_test)(void);
	int				timeout;
	struct s_test	*next;
}				t_test;

typedef	struct	s_unit
{
	char 			*name;
	t_test			*test_list;
	t_test			*last;
}				t_unit;

t_unit			*create_unit(char *name);
void			run_unit(t_unit *unit, char *file_name, bool clear);
t_test			*create_test(char *desc, int timeout, int (*f_test)(void));
void			add_test(t_unit *unit, t_test *test);
int				run_test(unsigned int timeout, int (*test)(void));
void			kill_timer(unsigned int timeout, pid_t pid);

#endif
