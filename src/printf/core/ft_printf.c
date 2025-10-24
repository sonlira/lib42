/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:15:29 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:03:32 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Núcleo principal de ft_printf: analiza y procesa la cadena de formato.
 *
 * @details
 * Recorre la cadena @p s carácter por carácter, escribiendo el resultado en el
 * descriptor de archivo @p fd. Cuando encuentra un símbolo '%', inicializa una
 * estructura @p t_flags, analiza las banderas, anchura, precisión y 
 * tipo mediante @c ft_printf_flags(), y finalmente delega la impresión en 
 * @c ft_printf_format().
 *
 * Si se detecta un formato inválido (por ejemplo, '%w') o una secuencia 
 * incompleta ('%' al final de la cadena), la función interrumpe el proceso 
 * y devuelve la cantidad total de caracteres válidamente escritos hasta el 
 * momento.
 *
 * @param fd     Descriptor de archivo donde se imprimirá la salida 
 * (por ejemplo, 1 para stdout).
 * @param s      Cadena de formato que contiene texto y especificadores 
 * de formato.
 * @param vlist  Lista de argumentos variable (tipo @c va_list) con los valores a
 * imprimir.
 *
 * @return El número total de caracteres escritos, o @c FT_ERROR (-1) 
 * si ocurre un error de escritura.
 *
 * @note Si @c init_flags() falla o el formato es inválido, la función se detiene
 *       de forma segura sin acceder a memoria no válida ni producir fugas.
 *
 * @example
 * @par Ejemplo
 * @code
 * va_list args;
 * va_start(args, fmt);
 * ssize_t printed = ft_printf_core(1, "hola %08d mundo", &args);
 * va_end(args);
 * // -> imprime: "hola 00000042 mundo"
 * // -> devuelve el número total de caracteres escritos
 * @endcode
 */
static ssize_t	ft_printf_core(int fd, const char *s, va_list *vlist)
{
	t_flags	flags;
	ssize_t	total;
	ssize_t	bytes;

	total = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s || !init_flags(&flags))
				break ;
			s = ft_printf_flags(s, &flags);
			if (!s)
				break ;
			bytes = ft_printf_format(&flags, vlist, fd);
			if (bytes == FT_ERROR)
				break ;
			total += bytes;
			continue ;
		}
		total += ft_putchar_fd(*s, fd);
		s++;
	}
	return (total);
}

/**
 * @brief Versión personalizada de printf que escribe en la salida estándar.
 *
 * @details
 * Imprime texto formateado en el descriptor de archivo estándar 
 * (`STDOUT_FILENO`),utilizando el mismo sistema de formato y banderas que
 * `ft_snprintf` y `ft_eprintf`.
 *
 * Internamente, esta función inicializa una lista de argumentos variable y
 * delega el procesamiento completo a @ref ft_printf_core(), que gestiona la
 * interpretación de banderas, anchura, precisión y tipos de formato.
 *
 * @param format  Cadena de formato que contiene texto y especificadores de 
 * formato.
 * @param ...     Lista variable de argumentos a imprimir.
 *
 * @return
 * El número total de caracteres escritos, o @c FT_ERROR (-1) si ocurre un error 
 * (por ejemplo, si @p format es NULL o si hay un fallo de escritura en el
 * descriptor).
 *
 * @note
 * - Equivalente funcional a `printf()` de la biblioteca estándar.  
 * - La salida se realiza directamente sobre `stdout` (descriptor 1).  
 * - El formato soporta los mismos especificadores que `ft_snprintf()`.
 *
 * @example
 * @code
 * ft_printf("Hola %s, tienes %d mensajes\n", "Carlos", 5);
 * // -> imprime: "Hola Carlos, tienes 5 mensajes"
 * @endcode
 *
 * @see ft_printf_core()
 * @see ft_eprintf()
 * @see ft_snprintf()
 */
ssize_t	ft_printf(const char *format, ...)
{
	va_list	vlist;
	ssize_t	bytes;

	if (!format)
		return (FT_ERROR);
	bytes = 0;
	va_start(vlist, format);
	bytes += ft_printf_core(STDOUT_FILENO, format, &vlist);
	va_end(vlist);
	return (bytes);
}

/**
 * @brief Versión personalizada de printf que escribe en la salida de error 
 * estándar.
 *
 * @details
 * Funciona igual que @ref ft_printf(), pero redirige la salida al descriptor
 * `STDERR_FILENO` (error estándar), lo cual resulta útil para mostrar mensajes
 * de error o depuración.
 *
 * Internamente, llama a @ref ft_printf_core() para realizar el análisis del
 * formato y la impresión, compartiendo el mismo conjunto de especificadores 
 * y banderas.
 *
 * @param format  Cadena de formato con texto y especificadores de formato.
 * @param ...     Lista variable de argumentos a imprimir.
 *
 * @return
 * El número total de caracteres escritos, o @c FT_ERROR (-1) si ocurre un error 
 * (por ejemplo, si @p format es NULL o si hay un fallo de escritura).
 *
 * @note
 * - Imprime directamente en `stderr` (descriptor 2).  
 * - Es útil para mensajes de error sin interrumpir la salida normal del 
 * 	 programa.
 * - Compatible con las mismas banderas y tipos de formato que `ft_printf()`.
 *
 * @example
 * @code
 * ft_eprintf("Error: archivo '%s' no encontrado\n", filename);
 * // -> imprime el mensaje en stderr
 * @endcode
 *
 * @see ft_printf()
 * @see ft_printf_core()
 */
ssize_t	ft_eprintf(const char *format, ...)
{
	va_list	vlist;
	ssize_t	bytes;

	if (!format)
		return (FT_ERROR);
	bytes = 0;
	va_start(vlist, format);
	bytes += ft_printf_core(STDERR_FILENO, format, &vlist);
	va_end(vlist);
	return (bytes);
}
