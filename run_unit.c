/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_unit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 02:24:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 05:05:35 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utest.h"
#include "report.h"

static void	free_test(t_test *test, bool clear)
{
	if (clear)
	{
		free(test->desc);
		free(test);
	}
}

static void	free_unit(t_unit *unit, bool clear)
{
	if (clear)
	{
		free(unit->name);
		free(unit);
	}
}

void			run_unit(t_unit *unit, char *file_name, bool clear)
{
	t_test	*test;
	t_test 	*next;
	char 	report[2048];
	char	buf[128];
	int 	result;
	FILE	*file;

	bzero(report, 2048);
	bzero(buf, 128);
	if (file_name)
		file = fopen(file_name, "w");
	else
		file = stdout;
	fprintf(file, "%s :", unit->name);
	test = unit->test_list;
	while (test)
	{
		next = test->next;
		result = run_test(test->timeout, test->f_test);
		snprintf(buf, 128, "%s: %s\n", get_result(result), test->desc);
		if (result)
			strlcat(report, buf, 2048);
		fprintf(file, " %s", get_result(result));
		free_test(test, clear);
		test = next;
		fflush(file);
	}
	fprintf(file, "\n%s", report);
	fflush(NULL);
	if (file != stdout)
		fclose(file);
	free_unit(unit, clear);
}
