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
# define TIME_LIMIT		10
	/**	bitfield flags **/
# define OUTPUT			0x01
# define CHRONO			0x02
# define TIMEOUT		0x04

/*
**			TYPEDEFS
*/
	/** function pointers **/
typedef int	(*t_test)(void);
	/** data **/
typedef struct s_param		t_param;
typedef struct s_suite		t_suite;
typedef struct s_unit		t_unit;
typedef struct s_saved_reg	t_saved_reg;
typedef struct s_chrono 	t_chrono;

/*
**			DATA
*/
	/**	parameters of test **/
struct s_param
{
	int32_t			flags;
	uint32_t		time_limit;
	const char *	expected_output;
};
	/** exec time data **/
struct  s_chrono
{
    clock_t		start;
    clock_t		end;
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
struct s_saved_reg
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
