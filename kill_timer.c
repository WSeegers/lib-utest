/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_timer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 07:05:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 04:35:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "report.h"

void	kill_timer(unsigned int timeout, pid_t pid)
{
	pid_t child_pid;
	
	child_pid = fork();
	if (child_pid < 0)
	{
		PRINT_FAIL("fork() failed");
	}
	else
	{
		if (!child_pid)
		{
			sleep(timeout);
			kill(pid, SIGKILL);
			_Exit(0);
		}
		else
			return ;
	}
}
