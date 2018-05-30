/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 03:12:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 03:33:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"

void			add_test(t_unit *unit, t_test *test)
{
	if (unit->test_list)
		unit->last->next = test;
	else
		unit->test_list = test;
	unit->last = test;
}
