/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:15:29 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:38:31 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

/**
 * @brief Núcleo interno de ft_snprintf: analiza y procesa la cadena de formato.
 *
 * @details
 * Esta función recorre la cadena de formato @p s carácter por carácter, 
 * escribiendo los resultados en el buffer de @p snf.
 * 
 * Cuando encuentra un símbolo de formato ('%'), inicializa y analiza 
 * las banderas almacenadas en @c snf->f mediante @c ft_printf_flags(),
 * luego delega el manejo del tipo en @c ft_snprintf_format().
 *
 * Si se encuentra una secuencia de formato inválida (por ejemplo, '%q') o
 * incompleta ('%' al final), la función interrumpe el proceso y deja el buffer
 * en un estado consistente, garantizando el terminador nulo.
 *
 * @param snf    Puntero a una estructura @ref t_snformat que gestiona
 *               el estado de escritura (posición, longitud y banderas).
 * @param s      Cadena de formato que contiene texto y especificadores.
 * @param vlist  Lista de argumentos variable (tipo @c va_list) con los valores a
 *               imprimir.
 *
 * @note Esta función es interna (@c static) y no debe llamarse directamente 
 *       desde el usuario final. Su comportamiento replica el de printf, 
 *       pero escribe en memoria en lugar de un descriptor.
 *
 * @post Siempre garantiza que el buffer resultante termina en '\0', 
 *       incluso si @p n == 0 o el formato se interrumpe.
 *
 * @see ft_snprintf_format()
 * @see ft_printf_flags()
 */
static void	ft_snprintf_core(t_snformat *snf, const char *s, va_list *vlist)
{
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				break ;
			s = ft_printf_flags(s, &snf->f);
			if (!s)
				break ;
			ft_snprintf_format(snf, vlist);
			continue ;
		}
		ft_putchar_to_snf(*s, snf);
		s++;
	}
	if (snf->i < snf->n)
		snf->s[snf->i] = '\0';
	else if (snf->n > 0)
		snf->s[snf->n - 1] = '\0';
}

/**
 * @brief Versión personalizada de snprintf.
 *
 * @details
 * Escribe texto formateado en el buffer @p s, con un tamaño máximo de @p n
 * bytes.
 * 
 * Internamente, utiliza una estructura @ref t_snformat para controlar la
 * posición
 * actual de escritura, el tamaño máximo permitido y el total de bytes escritos.
 * Los especificadores de formato y banderas se procesan mediante
 * @c ft_snprintf_core(), que replica el comportamiento del núcleo de printf.
 *
 * @param s       Puntero al buffer destino donde se escribirá la salida.
 * @param n       Tamaño máximo del buffer (incluyendo el terminador nulo).
 * @param format  Cadena de formato que contiene texto y especificadores de 
 *       formato.
 * @param ...     Lista variable de argumentos a imprimir.
 *
 * @return
 * El número total de caracteres escritos (sin incluir el terminador nulo),
 * o @c FT_ERROR (-1) si ocurre un error (por ejemplo, si @p s o @p format son 
 * NULL, o si @c init_snformat() falla).
 *
 * @note
 * - Garantiza siempre que el buffer resultante esté terminado en '\0'.  
 * - Si el contenido excede el tamaño @p n, se trunca de forma segura.
 * - Compatible con las mismas banderas y tipos que ft_printf.
 *
 * @example
 * @code
 * char buffer[32];
 * ssize_t len = ft_snprintf(buffer, sizeof(buffer), "Valor: %08d", 42);
 * // buffer -> "Valor: 00000042"
 * // len -> 14
 * @endcode
 *
 * @see ft_snprintf_core()
 * @see init_snformat()
 */
ssize_t	ft_snprintf(char *s, size_t n, char *format, ...)
{
	va_list		vlist;
	t_snformat	snf;

	if (!s || !format || !init_snformat(&snf))
		return (FT_ERROR);
	snf.s = s;
	snf.n = n;
	va_start(vlist, format);
	ft_snprintf_core(&snf, format, &vlist);
	va_end(vlist);
	return (snf.bytes);
}
