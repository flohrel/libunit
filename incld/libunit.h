/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:24:28 by flohrel           #+#    #+#             */
/*   Updated: 2022/01/15 16:52:25 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <errno.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include "defs.h"

/*
**		print.c
*/
void	print_header(const char *str);

/*
**		register.c
*/
void	save_registers(t_register *saved_reg);
bool	check_registers(t_register *saved_reg);

/*
**		assert.c
*/
int32_t	assert_equal_int(int32_t expected, int32_t actual,
						const char *message, ...);
int32_t	assert_not_equal_int(int32_t threshold, int32_t actual,
						const char *message, ...);
int32_t	assert_null(void *pointer, const char *message, ...);
int32_t	assert_not_null(void *pointer, const char *message, ...);

/*
**		suite.c
*/
void	add_suite(t_suite **suite_list, char const *ft_name,
				void (*add_units)(t_unit **));
void	add_test_simple(t_unit **suite, char const *test_name,
						test_simple test);
void	add_test_output(t_unit **suite, char const *test_name,
						test_out test);

/*
**		memory.c
*/
void	*ft_calloc(size_t nmemb, size_t size);
void	clean_exit(int32_t return_value);

/*
**		flag.c
*/
int32_t	set_flag(int32_t *field, int32_t flag);
int32_t	check_flag(int32_t field, int32_t flag);
void	clear_flag(int32_t *field, int32_t flag);

/*
**		utils.c
*/
size_t	ft_strlen(const char *s);
t_suite	**get_suite_list(void);

#endif