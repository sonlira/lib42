/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:28:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:24:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static ssize_t	print_dot_precision(uint32_t un, t_flags *f, int fd)
{
	ssize_t	bytes;
	ssize_t	numlen;

	if (f->dot && !f->precision && !un)
		return (0);
	bytes = 0;
	numlen = ft_unumlen_base(un, BASE_DEC);
	bytes += ft_putnchar_fd('0', f->precision - numlen, fd);
	bytes += ft_putunbr_fd(un, fd);
	return (bytes);
}

static ssize_t	effective_num_length(uint32_t un, t_flags *f)
{
	ssize_t	len;

	if (f->dot && !f->precision && !un)
		return (0);
	len = ft_unumlen_base(un, BASE_DEC);
	if (f->dot && f->precision > len)
		len = f->precision;
	return (len);
}

static ssize_t	print_unum_with_flags(uint32_t un, t_flags *f, int fd)
{
	ssize_t	bytes;
	ssize_t	len;

	bytes = 0;
	len = effective_num_length(un, f);
	if (f->minus)
	{
		bytes += print_dot_precision(un, f, fd);
		bytes += ft_putnchar_fd(' ', f->width - len, fd);
	}
	else
	{
		if (f->zero && !f->dot)
		{
			bytes += ft_putnchar_fd('0', f->width - len, fd);
			bytes += ft_putunbr_fd(un, fd);
		}
		else
		{
			bytes += ft_putnchar_fd(' ', f->width - len, fd);
			bytes += print_dot_precision(un, f, fd);
		}
	}
	return (bytes);
}

/**
 * @brief Imprime un número entero sin signo en formato decimal.
 *
 * @details
 * Gestiona la conversión del tipo `'u'` dentro de `ft_printf`.  
 * 
 * Antes de imprimir, la función normaliza las banderas mediante 
 * @ref ft_normalize_unum_flags(), eliminando aquellas que no son válidas
 * para enteros sin signo (`+`, ` `, `#`).  
 * 
 * Luego, delega la impresión real a @c print_unum_with_flags(), que aplica
 * las reglas de anchura (`width`), alineación (`-`), precisión (`.`) y
 * relleno (`0`) según corresponda.
 *
 * @param un  Valor entero sin signo (de tipo @c uint32_t) a imprimir.
 * @param f   Puntero a la estructura @ref t_flags que contiene las banderas 
 * activas.
 * @param fd  Descriptor de archivo donde se escribirá la salida 
 *            (por ejemplo, 1 para stdout).
 *
 * @return
 * El número total de caracteres escritos, o @c FT_ERROR (-1) si ocurre un error
 * o los parámetros son inválidos.
 *
 * @note
 * - La bandera `#` no tiene efecto en el formato decimal.  
 * - Las banderas `+` y ` ` (espacio) se ignoran en enteros sin signo.  
 * - Si se especifica precisión (`.`), la bandera `0` se desactiva 
 * automáticamente.
 *
 * @example
 * @code
 * t_flags f;
 * init_flags(&f);
 * f.type = 'u';
 * f.width = 8;
 * ssize_t n = ft_printf_unum(12345u, &f, 1);
 * // imprime: "   12345"
 * // n = 8
 * @endcode
 *
 * @see ft_normalize_unum_flags()
 * @see print_unum_with_flags()
 * @see ft_printf_format()
 */
ssize_t	ft_printf_unum(uint32_t un, t_flags *f, int fd)
{
	if (!f || fd < 0)
		return (FT_ERROR);
	ft_normalize_unum_flags(f);
	return (print_unum_with_flags(un, f, fd));
}
