/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:50:56 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 11:26:23 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"
# include "./ft_printf_type.h"

/*
** --- FUNCTIONS PROTOTYPES ---
*/

/*
** Main flow of printf
*/

int					ft_printf(const char *str, ...);
void				ft_pf_internal(const char *str, va_list *ap, t_format *arg);

/*
** Print argument and string part
*/

void				str_print(const char **str, t_format *arg);
void				arg_print(t_format *arg, va_list *ap);

/*
** Auxiliar functions
*/

char				*nxt_conv_spec(char *str);
int					is_conv_spec(char c);
int					is_flag(char c);
int					ft_putnchar(char pad, int n);

/*
** Initialize, save flags, w, p and specs into structure
*/

void				arg_init(t_format *arg);
void				get_arg(const char **str, va_list *ap, t_format *new);
const char			*pf_saveflag(const char *str, t_format *arg);
const char			*pf_savew(const char *str, t_format *arg, va_list *ap);
const char			*pf_savep(const char *str, t_format *arg, va_list *ap);
const char			*pf_savespec(const char *str, t_format *arg);

/*
** Functions for printing the hole argument in right format
*/

void				pf_c(t_format *arg, int c);
void				pf_s(t_format *arg, char *str);
void				pf_p(t_format *arg, unsigned long long int p);
void				pf_di(t_format *arg, long long int n);
void				pf_x(t_format *arg, unsigned int x);

/*
** Functions for analysing current struct and complement with pad, n_pad
** and pad_zero attributes
*/

void				pf_analyse_c(t_format *arg);
void				pf_analyse_s(t_format *arg, char *str);
char				*pf_analyse_di(t_format *arg, long long int n);
char				*pf_analyse_p(t_format *arg, long long int p);
char				*pf_analyse_x(t_format *arg, long long int x);

/*
** Based on all structure, print the argument in the right formatting
** (width and left flags are treated in pf functions)
*/

int					ft_putnstr(char *str, int n);
int					ft_puthexa(char *nbr, int pad_zero, int is_p);
int					ft_putint(char *nbr, int pad_zero, int is_neg);

#endif
