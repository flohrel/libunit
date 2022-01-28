/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:53:25 by flohrel           #+#    #+#             */
/*   Updated: 2022/01/28 20:20:10 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	save_registers2(t_saved_reg *saved_reg)
{
	register uint64_t r13	asm("r13");
	register uint64_t r14	asm("r14");
	register uint64_t r15	asm("r15");

	saved_reg->r13 = r13;
	saved_reg->r14 = r14;
	saved_reg->r15 = r15;
}

void	save_registers(t_saved_reg *saved_reg)
{
	register uint64_t rbx	asm("rbx");
	register uint64_t rsp	asm("rsp");
	register uint64_t rbp	asm("rbp");
	register uint64_t r12	asm("r12");

	saved_reg->rbx = rbx;
	saved_reg->rsp = rsp;
	saved_reg->rbp = rbp;
	saved_reg->r12 = r12;
	save_registers2(saved_reg);
}

static int32_t	check_registers2(t_saved_reg *saved_reg)
{
	register uint64_t r13	asm("r13");
	register uint64_t r14	asm("r14");
	register uint64_t r15	asm("r15");

	if (saved_reg->r13 != r13
		|| saved_reg->r14 != r14
		|| saved_reg->r15 != r15)
		return (-1);
	return (0);
}

int32_t	check_registers(t_saved_reg *saved_reg)
{
	register uint64_t rbx	asm("rbx");
	register uint64_t rsp	asm("rsp");
	register uint64_t rbp	asm("rbp");
	register uint64_t r12	asm("r12");

	if (saved_reg->rbx != rbx
		|| saved_reg->rsp != rsp
		|| saved_reg->rbp != rbp
		|| saved_reg->r12 != r12)
		return (-1);
	return (check_registers2(saved_reg));
}
