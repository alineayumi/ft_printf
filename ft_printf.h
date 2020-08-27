/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:50:56 by afukuhar          #+#    #+#             */
/*   Updated: 2020/08/27 12:26:05 by afukuhar         ###   ########.fr       */
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
void				arg_print(va_list *ap, t_format *arg);
void				str_print(const char **str, t_format *arg);
char				*nxt_conv_spec(char *str);
int					is_conv_spec(char c);
int					is_flag(char c);
int					is_valid(char *str);
void				pf_saveflag(const char *str, t_format *arg, int *i);
void				pf_savew(const char *str, t_format *arg, int *i, va_list *ap);
void				pf_savep(const char *str, t_format *arg, int *i, va_list *ap);
void				pf_savelen(const char *str, t_format *arg, int *i);
void				pf_savespec(const char *str, t_format *arg, int *i);
void				get_arg(const char **str, va_list *ap, t_format *new);
char				*pf_format(t_format *arg, va_list *ap);
char				*pf_formatc(t_format *arg, int c);
char				*pf_formats(t_format *arg, char *str);
char				*pf_sprecision(char *str, t_format *arg);
void				pf_width(char **dst, char *src, t_format *arg);
void				arg_init(t_format *arg);
void				ft_pf_internal(const char *str, va_list *ap, t_format *arg);
#endif
