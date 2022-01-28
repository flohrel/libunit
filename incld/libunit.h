/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:24:28 by flohrel           #+#    #+#             */
/*   Updated: 2022/01/28 20:23:11 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <errno.h>
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

# include "defs.h"

/*
**			print.c
*/
void	print_header(const char *str);
void	print_signal(int32_t status);
void	print_result(t_unit *unit, int32_t count);

/*
**			register.c
*/
void	save_registers(t_saved_reg *saved_reg);
int32_t	check_registers(t_saved_reg *saved_reg);

/*
**			assert.c
*/
int32_t	test_assert(bool condition, const char *message, va_list *ap);
int32_t	assert_int_lt(intmax_t threshold, intmax_t actual,
			const char *message, ...);
int32_t	assert_int_le(intmax_t threshold, intmax_t actual,
			const char *message, ...);
int32_t	assert_int_gt(intmax_t threshold, intmax_t actual,
			const char *message, ...);
int32_t	assert_int_ge(intmax_t threshold, intmax_t actual,
			const char *message, ...);

/*
**			assert2.c
*/
int32_t	assert_str_eq(const char *expected, const char *actual,
			const char *message, ...);
int32_t	assert_int_eq(intmax_t expected, intmax_t actual,
			const char *message, ...);
int32_t	assert_int_ne(intmax_t threshold, intmax_t actual,
			const char *message, ...);
int32_t	assert_null(void *pointer, const char *message, ...);
int32_t	assert_not_null(void *pointer, const char *message, ...);

/*
**			assert3.c
*/
int32_t	assert_ptr_eq(uintptr_t expected, uintptr_t actual,
			const char *message, ...);
int32_t	assert_ptr_ne(uintptr_t threshold, uintptr_t actual,
			const char *message, ...);

/*
**			suite.c
*/
void	add_suite(char const *ft_name, void (*add_units)(t_unit **));
void	suite_add_test(t_unit **suite, char const *test_name, t_test test,
			int32_t flags);

/*
**			memory.c
*/
void	*ft_calloc(size_t nmemb, size_t size);
void	clean_exit(int32_t return_value);

/*
**			flag.c
*/
int32_t	set_flag(int32_t *field, int32_t flag);
int32_t	check_flag(int32_t field, int32_t flag);
void	clear_flag(int32_t *field, int32_t flag);

/*
**			utils.c
*/
size_t	f_strlen(const char *s);
int		f_strcmp(const char *s1, const char *s2);
t_suite	**get_suite_list(void);

/*
**			run.c
*/
void	run_all(void);

/*
 **			time.c
 */
void	chrono_start(void);
void	chrono_end(void);
float	get_execution_time(void);

#endif
