#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	char	type;
	int		width;
	int		accuracy;
	int		minus;
	int		zero;
	int		star;
}				t_flags;

int		ft_printf(const char *format, ...);

int		check_digit(char *format, int i);
int		check_type(char *format, int i);
int		check_flag(char *format, int i);

int		we_met_zero(char *format, int i, t_flags *flagi);
int		check_next_char_after_zero(char *format, int i);

void	analyze_minus(t_flags *flagi);
int		analyze_accuracy(char *format, int i, t_flags *flagi, va_list arg);
void	analyze_width(va_list arg, t_flags *flagi);
void	analyze_width_2(char c, t_flags *flagi);

int		process_types(char type, t_flags *flagi, va_list arg);
int		process_char(char c, t_flags *flagi);
int		process_string(char *str, t_flags *flagi);
int		process_pointer(unsigned long adress, t_flags *flagi);
int		process_integer(int nb, t_flags *flagi);
int		process_uns_int(unsigned int nb, t_flags *flagi);
int		process_hexa(unsigned int nb, t_flags *flagi, int capitals);
int		process_percent(t_flags *flagi);

int		handle_no_minus(char *str, t_flags *flagi, int str_len, int len);
int		minus_one(char *str, t_flags *flagi);

void	ft_putchar(char c);
int		my_putstr(char *s, t_flags *flagi);
int		no_ad_acc_minus_p(char *str, t_flags *flagi, int str_len, int len);
int		no_add_acc_with_min(char *str, t_flags *flagi);

int		u_handle_no_minus_int(t_flags *flagi, char *str);
int		u_handle_width_with_minus(t_flags *flagi);
int		u_putstr_for_minus(t_flags *flagi, char *str, int str_len);
int		u_handle_minus(char *str, t_flags *flagi);
int		u_putstr_no_minus(t_flags *flagi, char *str, int str_len);
int		u_no_min_wid_with_ac(t_flags *flagi, char *str, int str_len, int len);
int		u_no_minus_no_acc(t_flags *flagi, int str_len, int len);

int		putstr_no_minus(t_flags *flagi, char *str, int str_len);
int		no_minus_width_with_acc(t_flags *flagi, char *str, int nb, int str_len);
int		no_minus_no_acc(t_flags *flagi, int str_len, int nb, int len);
int		handle_no_minus_int(t_flags *flagi, char *str, int nb);

int		handle_width_with_minus(t_flags *flagi);
int		putstr_for_minus(t_flags *flagi, char *str, int str_len, int nb);
int		handle_minus(char *str, t_flags *flagi, int nb);

#	endif