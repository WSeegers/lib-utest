/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 05:39:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 04:37:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include "report.h"
#include "utest.h"

int		run_test(unsigned int timeout, int (*test)(void))
{
	pid_t	child_pid;
	int		status;
	
	child_pid = fork();
	if (child_pid < 0)
	{
		PRINT_FAIL("fork() failed");
		return (-1);
	}
	else
	{
		if (!child_pid)
			_Exit (test());
		else
		{
			if (timeout)
				kill_timer(timeout, child_pid);
			waitpid(child_pid, &status, 0);
			if (status == 0x09)
				return (R_TOUT);
			return (status);
		}
	}
}
