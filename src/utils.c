/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:50:40 by flohrel           #+#    #+#             */
/*   Updated: 2022/01/28 19:53:12 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_suite	**get_suite_list(void)
{
	static t_suite	*suite_list = NULL;

	return (&suite_list);
}

size_t	f_strlen(const char *s)
{
	const char	*str;

	str = s;
	if (str)
		while (*str++)
			;
	return (str - s - 1);
}

int	f_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
