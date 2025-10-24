/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:22 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:22:44 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static ssize_t	effective_num_length(void *ptr)
{
	if (!ptr)
		return (ft_strlen("(nil)"));
	return (ft_unumlen_base((uint64_t)ptr, BASE_HEX) + 2);
}

static ssize_t	print_ptr_with_flags(void *ptr, t_flags *f, int fd)
{
	ssize_t	bytes;
	ssize_t	len;

	bytes = 0;
	len = effective_num_length(ptr);
	if (f->minus)
	{
		bytes += ft_putptr_fd(ptr, fd);
		bytes += ft_putnchar_fd(' ', f->width - len, fd);
	}
	else
	{
		bytes += ft_putnchar_fd(' ', f->width - len, fd);
		bytes += ft_putptr_fd(ptr, fd);
	}
	return (bytes);
}

/**
 * @brief Imprime un puntero de memoria en formato hexadecimal estándar.
 *
 * @details
 * Gestiona la conversión del tipo `'p'` dentro de `ft_printf`, mostrando la
 * dirección de memoria apuntada por @p ptr en formato hexadecimal precedido por
 * el prefijo `"0x"`, siguiendo el comportamiento estándar de `printf("%p")`.
 *
 * Antes de imprimir, se normalizan las banderas mediante 
 * @ref ft_normalize_ptr_flags(), ya que las banderas de formato (`+`, `#`,
 * ` `, `0`, `.`) no afectan a este tipo de conversión.
 *
 * La escritura real se delega a @c print_ptr_with_flags(), que formatea la
 * dirección según el ancho (`width`) o la alineación (`-`) indicadas en @p f.
 *
 * @param ptr  Puntero que se desea imprimir (de tipo @c void*).
 * @param f    Puntero a la estructura @ref t_flags con las banderas activas.
 * @param fd   Descriptor de archivo donde se escribirá la salida
 *             (por ejemplo, 1 para stdout).
 *
 * @return
 * El número total de caracteres escritos, o @c FT_ERROR (-1) si ocurre un
 * error o si los parámetros son inválidos.
 *
 * @note
 * - Los punteros nulos se imprimen generalmente como `"(nil)"`.  
 * - Las banderas `+`, `#`, ` `, `0` y `.` se desactivan automáticamente.  
 * - La alineación y el ancho (`width`) siguen siendo aplicables.
 *
 * @example
 * @code
 * t_flags f;
 * init_flags(&f);
 * f.width = 14;
 * ssize_t n = ft_printf_ptr((void *)0x7ffeefbff5b8, &f, 1);
 * // imprime: "  0x7ffeefbff5b8"
 * // n = 14
 * @endcode
 *
 * @see ft_normalize_ptr_flags()
 * @see print_ptr_with_flags()
 * @see ft_printf_format()
 */
ssize_t	ft_printf_ptr(void *ptr, t_flags *f, int fd)
{
	if (!f || fd < 0)
		return (FT_ERROR);
	ft_normalize_ptr_flags(f);
	return (print_ptr_with_flags(ptr, f, fd));
}
