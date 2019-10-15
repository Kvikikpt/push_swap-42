/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:47:38 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 19:30:09 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_stack
{
	int					num;
	int					index;
	int					com[5];
	struct s_stack		*next;
}					t_st;

typedef struct		s_com
{
	char				*command;
	struct s_com		*next;
}					t_com_list;

typedef struct		s_bonuss
{
	int		v;
	int		c;
	int		a;
}					t_bonus;

void				pa_pb(t_st **stack_one, t_st **stack_two);
void				sa_sb_ss(t_st **stack);
void				ra_rb_rr(t_st **stack);
void				rra_rrb_rrr(t_st **stack);
void				sa(t_st **stack, int a);
void				sb(t_st **stack, int a);
void				ss(t_st **stack_a, t_st **stack_b, int a);
void				pa(t_st **stack_a, t_st **stack_b, int a);
void				pb(t_st **stack_a, t_st **stack_b, int a);
void				ra(t_st **stack, int a);
void				rb(t_st **stack, int a);
void				rr(t_st **stack_a, t_st **stack_b, int a);
void				rra(t_st **stack, int a);
void				rrb(t_st **stack, int a);
void				rrr(t_st **stack_a, t_st **stack_b, int a);
int					min_stack(t_st **stack);
int					max_stack(t_st **stack);
t_st				*st_new(void);
void				error_struct(t_com_list **com, t_st **a,
t_bonus **bonus, int error);
void				error(t_st **a, t_bonus **bonus);
void				command_fill(t_com_list **com, t_st **a, t_bonus **bonus);
void				stack_a_fill(t_st **stack_a, char ***argv, t_bonus **bonus);
int					check_and_fill(char **str, t_st **stack_a, t_bonus **bonus);
int					check_dublicates(t_st **stack_a, t_bonus **bonus);
void				stack_b_check_roll(t_st **b);
void				stack_a_check_roll(t_st **a, t_st **b);
void				a_end_roll(t_st **a, int min);
void				stack_a_erase(t_st **a);
void				comm_erase(t_com_list **comm);
void				bonus_erase(t_bonus **bonus);
void				pre_check(t_st **a);
void				few_elem_fill(t_st **stack_a);
void				print_stacks(t_st *a, t_st *b);
t_bonus				*bonus_new(void);
void				begin_check(int argc, char **argv, t_bonus **bonus);
void				print_check(t_st *a, t_st *b, t_bonus **bonus);

#endif
