/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 03:49:05 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 05:13:15 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include "utest.h"
#include "report.h"

int		basic_pass(void)
{
	return (R_PASS);
}

int		basic_fail(void)
{
	sleep(1);
	return (R_FAIL);
}

int		basic_segf(void)
{
	char *seg;

	seg = NULL;
	*seg = 'f';
	return (1);
}

int		basic_tout(void)
{
	sleep(60);
	return (1);
}

int		main(void)
{
	t_unit *u_basic;

	u_basic = create_unit("Basic");

	add_test(u_basic, create_test("Expect a pass result", 1, basic_pass));
	add_test(u_basic, create_test("Expect a pass result", 1, basic_pass));
	add_test(u_basic, create_test("Expect a time out result", 1, basic_tout));
	add_test(u_basic, create_test("Expect a pass result", 1, basic_pass));
	add_test(u_basic, create_test("Expect a fail result", 0, basic_fail));
	add_test(u_basic, create_test("Expect a segfault", 5, basic_segf));
	add_test(u_basic, create_test("Expect a segfault", 5, basic_segf));
	add_test(u_basic, create_test("Expect a time out result", 1, basic_tout));
	add_test(u_basic, create_test("Expect a pass result", 1, basic_pass));
	add_test(u_basic, create_test("Expect a time out result", 1, basic_tout));
	
	printf("Testing starting\n");
	run_unit(u_basic, NULL, false);
	printf("Writing to file\n");
	run_unit(u_basic, "result.log", true);
	printf("Done\n");
}
