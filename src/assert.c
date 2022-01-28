/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:46:46 by flohrel           #+#    #+#             */
/*   Updated: 2022/01/28 19:47:48 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int32_t	test_assert(bool condition, const char *message, va_list *ap)
{
	int32_t	result;

	result = EXIT_FAILURE;
	fprintf(stderr, RESET);
	if (condition == true)
		result = EXIT_SUCCESS;
	else
	{
		vfprintf(stderr, message, *ap);
		fprintf(stderr, "\n");
	}
	va_end(*ap);
	return (result);
}

int32_t	assert_int_lt(intmax_t threshold, intmax_t actual,
			const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((actual < threshold), message, &ap));
}

int32_t	assert_int_le(intmax_t threshold, intmax_t actual,
			const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((actual <= threshold), message, &ap));
}

int32_t	assert_int_gt(intmax_t threshold, intmax_t actual,
			const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((actual > threshold), message, &ap));
}

int32_t	assert_int_ge(intmax_t threshold, intmax_t actual,
			const char *message, ...)
{
	va_list	ap;

	va_start(ap, message);
	return (test_assert((actual >= threshold), message, &ap));
}
