/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_unit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 02:18:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 03:35:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "utest.h"

t_unit			*create_unit(char *name)
{
	t_unit	*unit;

	unit = (t_unit*)malloc(sizeof(*unit));
	if (name)
		unit->name = strdup(name);
	else
		unit->name = strdup("[No Name]");
	unit->test_list = NULL;
	unit->last = NULL;
	return (unit);
}
