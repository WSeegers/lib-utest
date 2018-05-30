/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 03:09:44 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 03:34:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "utest.h"

t_test			*create_test(char *desc, int timeout, int (*f_test)(void))
{
	t_test *test;

	test = (t_test*)malloc(sizeof(*test));
	test->desc = strdup(desc);
	test->timeout = timeout;
	test->f_test = f_test;
	return (test);
}
