# include "libunit.h"

int32_t	assert_ptr_eq(uintptr_t expected, uintptr_t actual, const char *message, ...)
{
	va_list ap;

	va_start(ap, message);
	return (test_assert((actual == expected), message, &ap));
}

int32_t	assert_ptr_ne(uintptr_t threshold, uintptr_t actual, const char *message, ...)
{
	va_list ap;

	va_start(ap, message);
	return (test_assert((actual != threshold), message, &ap));
}