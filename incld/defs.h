#ifndef DEFS_H
# define DEFS_H

# include "ansi_colors.h"

/*
**			MACROS
*/
	/** general **/
# define TEST_SUCCESS	0
# define TEST_FAILED	-1
	/** default parameters **/
# define DEFAULT_TIMER	10
	/**	bitfield flags **/
# define TIMER			0x01
# define OUTPUT			0x02
# define REGISTER		0x04
# define ERRNO			0x08
# define SIGNAL			0x10

/*
**			TYPEDEFS
*/
	/** function pointers **/
typedef int	(*test_out)(int *);
typedef int	(*test_simple)(void);
	/** data **/
typedef union u_test		t_test;
typedef struct s_param		t_param;
typedef struct s_suite		t_suite;
typedef struct s_unit		t_unit;
typedef struct s_register	t_register;

/*
**			DATA
*/
	/** test function **/
union	u_test
{
	test_out	out;
	test_simple	simple;
};
	/**	parameters of test **/
struct s_param
{
	int32_t			flags;
	uint32_t		time_limit;
	// t_register	saved_registers;
	// char const	*expected_output;
	// int32_t		expected_errno;
	// int32_t		expected_signal;
};
	/** linked list of tests **/
struct s_unit
{
	char const	*name;
	t_param		parameters;
	t_test		test;
	t_unit		*next;
};
	/** linked list of test suites **/
struct	s_suite
{
	char const	*ft_name;
	t_unit		*unit;
	t_suite		*next;
};
	/** registers **/
struct s_register
{
	uint64_t	rbx;
	uint64_t	rsp;
	uint64_t	rbp;
	uint64_t	r12;
	uint64_t	r13;
	uint64_t	r14;
	uint64_t	r15;
};

#endif