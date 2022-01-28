/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:43:59 by flohrel           #+#    #+#             */
/*   Updated: 2022/01/28 19:45:03 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int32_t	assert_str_eq(const char *expected, const char *actual,
			const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert(!f_strcmp(actual, expected), message, &ap));
}

int32_t	assert_null(void *pointer, const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((pointer == NULL), message, &ap));
}

int32_t	assert_not_null(void *pointer, const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((pointer != NULL), message, &ap));
}

int32_t	assert_int_eq(intmax_t expected, intmax_t actual,
			const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((actual == expected), message, &ap));
}

int32_t	assert_int_ne(intmax_t threshold, intmax_t actual,
			const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((actual != threshold), message, &ap));
}
