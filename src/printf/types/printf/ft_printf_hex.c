/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:38:44 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static ssize_t	print_prefix(uint32_t un, t_flags *f, int fd)
{
	if (f->hash && un)
	{
		if (f->type == 'x')
			return (ft_putstr_fd("0x", fd));
		else
			return (ft_putstr_fd("0X", fd));
	}
	return (0);
}

static ssize_t	print_dot_precision(uint32_t un, t_flags *f, int fd)
{
	ssize_t	bytes;
	ssize_t	numlen;

	if (f->dot && !f->precision && !un)
		return (0);
	bytes = 0;
	numlen = ft_unumlen_base(un, BASE_HEX);
	bytes += print_prefix(un, f, fd);
	bytes += ft_putnchar_fd('0', f->precision - numlen, fd);
	bytes += ft_puthex_fd(un, fd, (f->type == 'X'));
	return (bytes);
}

static ssize_t	effective_num_length(uint32_t un, t_flags *f)
{
	ssize_t	len;

	if (f->dot && !f->precision && !un)
		return (0);
	len = ft_unumlen_base(un, BASE_HEX);
	if (f->dot && f->precision > len)
		len = f->precision;
	if (f->hash && un)
		len += 2;
	return (len);
}

static ssize_t	print_hex_with_flags(uint32_t un, t_flags *f, int fd)
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
			bytes += print_prefix(un, f, fd);
			bytes += ft_putnchar_fd('0', f->width - len, fd);
			bytes += ft_puthex_fd(un, fd, (f->type == 'X'));
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
 * @brief Imprime un número entero sin signo en formato hexadecimal.
 *
 * @details
 * Gestiona las conversiones de tipo `'x'` y `'X'` dentro de `ft_printf`.
 * 
 * Antes de imprimir, la función llama a @ref ft_normalize_unum_flags() para
 * ajustar las banderas de formato y eliminar combinaciones no válidas
 * (por ejemplo, `+`, ` ` o `0` cuando hay precisión).
 *
 * Luego, delega la escritura real a @c print_hex_with_flags(), que se encarga
 * de aplicar las banderas (`#`, `0`, `-`, `width`, `precision`, etc.) y
 * de seleccionar entre letras minúsculas o mayúsculas según `f->type`.
 *
 * @param un  Valor sin signo a imprimir (de tipo @c uint32_t).
 * @param f   Puntero a la estructura @ref t_flags que contiene las banderas 
 *            activas y la información del formato.
 * @param fd  Descriptor de archivo donde se escribirá la salida 
 *            (por ejemplo, 1 para stdout).
 *
 * @return
 * El número total de caracteres escritos, o @c FT_ERROR (-1) si ocurre un
 * error o si los parámetros son inválidos.
 *
 * @note
 * - La bandera `#` antepone el prefijo `0x` o `0X` cuando el número es distinto
 *  de cero.
 * - Las banderas `+` y ` ` (espacio) no tienen efecto sobre valores sin signo.  
 * - Si se especifica precisión, la bandera `0` se ignora.  
 * - El caso (`x` / `X`) depende de `f->type`.
 *
 * @example
 * @code
 * t_flags f;
 * init_flags(&f);
 * f.type = 'x';
 * f.hash = true;
 * f.width = 8;
 * ssize_t n = ft_printf_hex(3735928559u, &f, 1);
 * // imprime: "  0xdeadbeef"
 * // n = 12
 * @endcode
 *
 * @see ft_normalize_unum_flags()
 * @see print_hex_with_flags()
 * @see ft_printf_format()
 */
ssize_t	ft_printf_hex(uint32_t un, t_flags *f, int fd)
{
	if (!f || fd < 0)
		return (FT_ERROR);
	ft_normalize_unum_flags(f);
	return (print_hex_with_flags(un, f, fd));
}
