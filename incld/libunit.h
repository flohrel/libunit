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
void	save_registers(t_register *saved_reg);
int32_t	check_registers(t_register *saved_reg);

/*
**			assert.c
*/
int32_t	assert_equal_int(int32_t expected, int32_t actual,
						const char *message, ...);
int32_t	assert_not_equal_int(int32_t threshold, int32_t actual,
						const char *message, ...);
int32_t	assert_null(void *pointer, const char *message, ...);
int32_t	assert_not_null(void *pointer, const char *message, ...);

/*
**			suite.c
*/
void	add_suite(char const *ft_name, void (*add_units)(t_unit **));
void	add_test_simple(t_unit **suite, char const *test_name,
						test_simple test);
void	add_test_output(t_unit **suite, const char *test_name,
						test_out test, const char *expected_output);

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
size_t	ft_strlen(const char *s);
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