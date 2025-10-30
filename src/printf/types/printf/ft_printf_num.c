/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:17 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:38:52 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static ssize_t	print_signed(bool neg, t_flags *f, int fd)
{
	if (neg)
		return (ft_putchar_fd('-', fd));
	if (f->plus)
		return (ft_putchar_fd('+', fd));
	if (f->space)
		return (ft_putchar_fd(' ', fd));
	return (0);
}

static ssize_t	print_dot_precision(uint32_t un, bool neg, t_flags *f, int fd)
{
	ssize_t	bytes;
	ssize_t	numlen;

	if (f->dot && !f->precision && !un)
		return (0);
	bytes = 0;
	numlen = ft_unumlen_base(un, BASE_DEC);
	bytes += print_signed(neg, f, fd);
	bytes += ft_putnchar_fd('0', f->precision - numlen, fd);
	bytes += ft_putunbr_fd(un, fd);
	return (bytes);
}

static ssize_t	effective_num_length(uint32_t un, bool neg, t_flags *f)
{
	ssize_t	len;

	if (f->dot && !f->precision && !un)
		return (0);
	len = ft_unumlen_base(un, BASE_DEC);
	if (f->dot && f->precision > len)
		len = f->precision;
	if (neg || f->plus || f->space)
		++len;
	return (len);
}

static ssize_t	print_num_with_flags(uint32_t un, bool neg, t_flags *f, int fd)
{
	ssize_t	bytes;
	ssize_t	len;

	bytes = 0;
	len = effective_num_length(un, neg, f);
	if (f->minus)
	{
		bytes += print_dot_precision(un, neg, f, fd);
		bytes += ft_putnchar_fd(' ', f->width - len, fd);
	}
	else
	{
		if (f->zero && !f->dot)
		{
			bytes += print_signed(neg, f, fd);
			bytes += ft_putnchar_fd('0', f->width - len, fd);
			bytes += ft_putunbr_fd(un, fd);
		}
		else
		{
			bytes += ft_putnchar_fd(' ', f->width - len, fd);
			bytes += print_dot_precision(un, neg, f, fd);
		}
	}
	return (bytes);
}

/**
 * @brief Imprime un número entero con signo aplicando las banderas de formato.
 *
 * @details
 * Gestiona las conversiones de tipo `'d'` y `'i'` dentro de `ft_printf`.  
 * 
 * La función convierte el entero @p n a positivo (si es negativo) y guarda
 * el signo en la variable local @p neg.  
 * Posteriormente, normaliza las banderas mediante 
 * @ref ft_normalize_num_flags() para ajustar las combinaciones inválidas:
 * - Desactiva `0` si hay `-` o precisión (`.`).  
 * - Desactiva `#`, que no aplica a enteros con signo.  
 * - Si `+` está activa, desactiva la bandera de espacio (` `).
 *
 * Finalmente, delega la impresión a @c print_num_with_flags(), que se encarga
 * de aplicar los signos (`+` / `-` / espacio), el relleno con ceros o espacios,
 * y la anchura o precisión configuradas.
 *
 * @param n   Valor entero (con signo) a imprimir.
 * @param f   Puntero a la estructura @ref t_flags con las banderas activas.
 * @param fd  Descriptor de archivo donde se escribirá la salida
 *            (por ejemplo, 1 para stdout).
 *
 * @return
 * El número total de caracteres escritos, o @c FT_ERROR (-1) si ocurre
 * un error o los parámetros son inválidos.
 *
 * @note
 * - Los valores negativos se imprimen con el signo `-`.  
 * - Las banderas `+` y ` ` controlan la impresión de signos positivos.  
 * - Si se especifica precisión, la bandera `0` se ignora.  
 * - El relleno se ajusta en función de `width` y `-`.
 *
 * @example
 * @code
 * t_flags f;
 * init_flags(&f);
 * f.type = 'd';
 * f.plus = true;
 * f.width = 6;
 * ssize_t n = ft_printf_num(-42, &f, 1);
 * // imprime: "   -42"
 * // n = 6
 * @endcode
 *
 * @see ft_normalize_num_flags()
 * @see print_num_with_flags()
 * @see ft_printf_format()
 */
ssize_t	ft_printf_num(int n, t_flags *f, int fd)
{
	long	un;
	bool	neg;

	if (!f || fd < 0)
		return (FT_ERROR);
	un = n;
	neg = (n < 0);
	if (neg)
		un = -un;
	ft_normalize_num_flags(f);
	return (print_num_with_flags(un, neg, f, fd));
}
