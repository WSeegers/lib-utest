/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 07:51:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 05:34:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "report.h"

char *get_result(int err)
{
	static char *msg[] = {
		S_RED("[SYSE]"),
		S_GREEN("[PASS]"),
	    S_YELLOW("[FAIL]"),	
		S_RED("[SEGF]"),
		S_YELLOW("[TOUT]")
	};

	switch (err)
	{
		case R_PASS :
			return (msg[1]);
		case 0x100 :
			return (msg[2]);
		case R_SEGF : 
			return (msg[3]);
		case R_TOUT : 
			return (msg[4]);
		default :
			return (msg[0]);
	}
	return (msg[0]);
}
