/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:10 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:21:19 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static ssize_t	print_char_with_flags(int c, t_flags *f, int fd)
{
	ssize_t	bytes;

	bytes = 0;
	if (f->minus)
	{
		bytes += ft_putchar_fd(c, fd);
		bytes += ft_putnchar_fd(' ', f->width - 1, fd);
	}
	else
	{
		if (f->zero && f->type == '%')
			bytes += ft_putnchar_fd('0', f->width - 1, fd);
		else
			bytes += ft_putnchar_fd(' ', f->width - 1, fd);
		bytes += ft_putchar_fd(c, fd);
	}
	return (bytes);
}

/**
 * @brief Imprime un carácter con las banderas de formato aplicadas.
 *
 * @details
 * Esta función gestiona la conversión del tipo `'c'` (carácter) o `'%'` literal
 * dentro de `ft_printf`.  
 * 
 * Antes de imprimir, normaliza las banderas del formato mediante 
 * @ref ft_normalize_char_flags(), eliminando aquellas que no son válidas 
 * para caracteres (como `+`, `#` o `.`).  
 * 
 * Finalmente, delega la escritura real en la función interna 
 * @c print_char_with_flags(), que aplica el relleno o alineación necesarios
 * según las banderas (`-`, `0`, `width`, etc.).
 *
 * @param c   Carácter a imprimir.
 * @param f   Puntero a la estructura @ref t_flags que contiene las banderas
 *            activas y la información de formato.
 * @param fd  Descriptor de archivo donde se escribirá la salida
 *            (por ejemplo, 1 para stdout).
 *
 * @return
 * El número total de caracteres escritos, o @c FT_ERROR (-1) si ocurre
 * un error o si los parámetros son inválidos.
 *
 * @note
 * - Las banderas `+`, `#`, ` ` (espacio) y `.` no tienen efecto en este tipo.  
 * - La bandera `0` se ignora cuando está presente `-` (alineación izquierda).  
 * - La salida se realiza directamente sobre el descriptor indicado.
 *
 * @example
 * @code
 * t_flags f;
 * init_flags(&f);
 * f.width = 5;
 * ssize_t n = ft_printf_char('A', &f, 1);
 * // imprime: "    A" (alineado a la derecha)
 * // n = 5
 * @endcode
 *
 * @see ft_normalize_char_flags()
 * @see print_char_with_flags()
 * @see ft_printf_format()
 */
ssize_t	ft_printf_char(int c, t_flags *f, int fd)
{
	if (!f || fd < 0)
		return (FT_ERROR);
	ft_normalize_char_flags(f);
	return (print_char_with_flags(c, f, fd));
}
