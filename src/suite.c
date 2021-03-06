/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:21:54 by flohrel           #+#    #+#             */
/*   Updated: 2022/01/28 20:26:30 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	suite_list_add_back(t_suite *new_suite)
{
	t_suite	**suite_list;
	t_suite	*tmp;

	suite_list = get_suite_list();
	if (*suite_list == NULL)
		*suite_list = new_suite;
	else
	{
		tmp = *suite_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_suite;
	}
}

void	add_suite(const char *ft_name, void (*add_unit)(t_unit **))
{
	t_suite	*new_suite;

	new_suite = ft_calloc(1, sizeof(*new_suite));
	if (new_suite == NULL)
		clean_exit(EXIT_FAILURE);
	new_suite->ft_name = ft_name;
	new_suite->unit = NULL;
	new_suite->next = NULL;
	add_unit(&(new_suite->unit));
	suite_list_add_back(new_suite);
}

static void	unit_list_add_back(t_unit **suite, t_unit *new_unit)
{
	t_unit	*tmp;

	if (*suite == NULL)
		*suite = new_unit;
	else
	{
		tmp = *suite;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_unit;
	}
}

void	suite_add_test(t_unit **suite, const char *test_name, t_test test,
			int32_t flags)
{
	t_unit	*new_unit;

	new_unit = ft_calloc(1, sizeof(*new_unit));
	if (new_unit == NULL)
		clean_exit(EXIT_FAILURE);
	new_unit->name = test_name;
	new_unit->test = test;
	set_flag(&new_unit->parameters.flags, flags | CHRONO);
	new_unit->parameters.time_limit = TIME_LIMIT;
	new_unit->next = NULL;
	unit_list_add_back(suite, new_unit);
}
