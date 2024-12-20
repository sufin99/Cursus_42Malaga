/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:57:55 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/20 02:04:00 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				cost_tot;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int			*numbers;
	char		**nums_str;
	int			num_count;
	t_stack		*sa;
	t_stack		*sb;
}				t_data;

void	ft_parsing(int argc, char *argv[], t_data *data);

int		ft_error(t_data	*data, char *str);
void	free_ar(char **ar);
void	ft_freeall(t_data *data);
void	ft_freestacks(t_data *data);

int		ft_atops(const char *str, t_data *data);

void	ft_algorithm(t_data *data);
t_stack	*ft_newnode(int value, t_data *data);
void	ft_connectstack(t_stack **lst, t_stack *new);
void	ft_bubbleshort(t_data *data);
int		ft_isordered(t_stack *stack);

void	print_stack(t_stack *stack, const char *name);

void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_s(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_r(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_r(t_stack **a, t_stack **b);

void	ft_order3(t_stack **stack, t_data *data);
void	ft_bigorder(t_stack	**sa, t_stack **sb, t_data *data);

int		ft_sizestack(t_stack **stack);

void	ft_addcost(t_stack **stack, int is_sa);
void	ft_ordersa(t_stack **sa);
void	ft_addpos(t_stack **sa, t_stack	**sb);
void	ft_moveonlysa(t_stack **sa, int csa);
void	ft_moveonlysb(t_stack **sb, int csb);
void	ft_choosenode(t_stack **sa, t_stack **sb);

int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_find_cost_a(t_stack *sa, int target_pos);

#endif