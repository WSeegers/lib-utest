/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 06:15:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 05:35:14 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_H
# define REPORT_H

#include <stdlib.h>
#include <stdio.h>
#include "utest.h"

/* Report Codes */
# define R_PASS 0
# define R_FAIL 1
# define R_SEGF 11
# define R_TOUT -128

/* Color for printf */
# define C_RED		"\x1b[31m"
# define C_GREEN	"\x1b[32m"
# define C_YELLOW	"\x1b[33m"
# define C_BLUE		"\x1b[34m"
# define C_MAGENTA	"\x1b[35m"
# define C_CYAN		"\x1b[36m"
# define C_RESET	"\x1b[0m"

# define S_RED(text)	C_RED text C_RESET
# define S_GREEN(text)	C_GREEN text C_RESET
# define S_YELLOW(text)	C_YELLOW text C_RESET

# define PRINT_FAIL(msg) fprintf(stderr, "%s ERROR: "msg"\n", __func__); exit(-1)

char *get_result(int result);

# endif

