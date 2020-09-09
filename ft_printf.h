/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:50:56 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/08 15:44:51 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"
# include "./ft_printf_type.h"

/*
** --- functions prototypes ---
*/
int					ft_printf(const char *str, ...);
void				str_print(const char **str, t_format *arg);
char				*nxt_conv_spec(char *str);
int					is_conv_spec(char c);
int					is_flag(char c);
int					is_valid(char *str);
void				pf_saveflag(const char *str, t_format *arg, int *i);
void				pf_savew(const char *str, t_format *arg, int *i, va_list *ap);
void				pf_savep(const char *str, t_format *arg, int *i, va_list *ap);
void				pf_savespec(const char *str, t_format *arg, int *i);
void				get_arg(const char **str, va_list *ap, t_format *new);
void				arg_print(t_format *arg, va_list *ap);
void				pf_c(t_format *arg, int c);
void				pf_s(t_format *arg, char *str);
void				pf_p(t_format *arg, unsigned long long int p);
void				pf_di(t_format *arg, long long int n);
int					ft_putnchar(char pad, int n);
int					ft_putnstr(char *str, int n);
int					ft_puthexa(char *nbr, int pad_zero);
int					ft_putint(char *nbr, int pad_zero, int is_neg);
void				pf_analyse_c(t_format *arg);
void				pf_analyse_s(t_format *arg, char *str);
char				*pf_analyse_di(t_format *arg, long long int n);
char				*pf_analyse_p(t_format *arg, long long int p);
void				arg_init(t_format *arg);
void				ft_pf_internal(const char *str, va_list *ap, t_format *arg);
#endif
