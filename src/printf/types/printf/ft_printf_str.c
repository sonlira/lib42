/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:26 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static ssize_t	effective_str_length(char *s, t_flags *f)
{
	ssize_t	len;

	len = ft_strlen_safe(s);
	if (f->dot && f->precision < len)
		len = f->precision;
	return (len);
}

static ssize_t	print_str_with_flags(char *s, t_flags *f, int fd)
{
	ssize_t	bytes;
	ssize_t	len;

	bytes = 0;
	len = effective_str_length(s, f);
	if (f->minus)
	{
		bytes += ft_putstrl_fd(s, len, fd);
		bytes += ft_putnchar_fd(' ', f->width - len, fd);
	}
	else
	{
		bytes += ft_putnchar_fd(' ', f->width - len, fd);
		bytes += ft_putstrl_fd(s, len, fd);
	}
	return (bytes);
}

/**
 * @brief Imprime una cadena de texto aplicando las banderas de formato.
 *
 * @details
 * Gestiona la conversión del tipo `'s'` dentro de `ft_printf`.  
 * 
 * Antes de imprimir, la función normaliza las banderas mediante 
 * @ref ft_normalize_str_flags(), desactivando aquellas que no son válidas 
 * para cadenas (`0`, `+`, `#`, ` `).  
 * 
 * Si el puntero @p s es @c NULL, se sustituye por la cadena literal
 * <tt>"(null)"</tt> para mantener un comportamiento coherente con `printf()`.
 *
 * Finalmente, delega la salida a @c print_str_with_flags(), que aplica 
 * las banderas de alineación (`-`), precisión (`.`) y anchura (`width`)
 * según los valores presentes en @p f.
 *
 * @param s   Cadena de texto a imprimir (terminada en '\0').
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
 * - Si se especifica precisión (`.`), la impresión se limita a ese número de 
 * caracteres.
 * - Las banderas `+`, `#`, ` ` y `0` no tienen efecto sobre cadenas.  
 * - El puntero @p s nunca se desreferencia si es NULL.
 *
 * @example
 * @code
 * t_flags f;
 * init_flags(&f);
 * f.width = 10;
 * f.minus = true;
 * ssize_t n = ft_printf_str("Hola", &f, 1);
 * // imprime: "Hola      "
 * // n = 10
 * @endcode
 *
 * @see ft_normalize_str_flags()
 * @see print_str_with_flags()
 * @see ft_printf_format()
 */
ssize_t	ft_printf_str(char *s, t_flags *f, int fd)
{
	if (!f || fd < 0)
		return (FT_ERROR);
	ft_normalize_str_flags(f);
	if (!s)
		s = "(null)";
	return (print_str_with_flags(s, f, fd));
}
