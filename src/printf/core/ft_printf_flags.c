/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:50:24 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:38:15 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static bool	parse_flag(const char **s, t_flags *f)
{
	const char	*src;

	src = *s;
	if (!ft_isflag_simple(*src))
		return (false);
	if (*src == '-')
		f->minus = true;
	else if (*src == '0')
		f->zero = true;
	else if (*src == '#')
		f->hash = true;
	else if (*src == '+')
		f->plus = true;
	else
		f->space = true;
	src++;
	*s = src;
	return (true);
}

static bool	parse_width(const char **s, t_flags *f)
{
	const char	*src;

	src = *s;
	if (!ft_isdigit(*src))
		return (false);
	f->width = ft_atoi(src);
	src = ft_strdrop(src, ft_isdigit);
	*s = src;
	return (true);
}

static bool	parse_precision(const char **s, t_flags *f)
{
	const char	*src;

	src = *s;
	if (*src != '.')
		return (false);
	f->dot = true;
	src++;
	f->precision = ft_atoi(src);
	src = ft_strdrop(src, ft_isdigit);
	*s = src;
	return (true);
}

static bool	parse_type(const char **s, t_flags *f)
{
	const char	*src;

	src = *s;
	if (!ft_is_valid_type(*src))
		return (false);
	f->type = *src;
	src++;
	*s = src;
	return (true);
}

/**
 * @brief Analiza y extrae las banderas, anchura, precisión y tipo de un formato
 *        de printf.
 * @details
 * Esta función recorre la cadena de formato que sigue a un carácter '%'
 * y actualiza los campos correspondientes dentro de la estructura @p t_flags.
 * 
 * Detecta y maneja, en este orden:
 * - Flags: '-', '0', '#', '+', ' '  
 * - Ancho (width): número entero positivo
 * - Precisión (precision): indicada tras un punto '.'
 * - Tipo (conversion specifier): 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'
 *
 * Cada elemento reconocido avanza el puntero @p s, de modo que al terminar
 * la función este apunta al primer carácter después del especificador de tipo.
 *
 * @param s Puntero constante a la cadena de formato (justo después de '%').
 * @param f Puntero a una estructura @p t_flags donde se guardarán los valores
 *        detectados.
 *
 * @return Un puntero al carácter siguiente al especificador de tipo si el
 *         formato es válido, o @c NULL si se encuentra un carácter inválido 
 *         o un formato incompleto.
 *
 * @note Esta función no imprime nada; solo interpreta la parte del formato.
 *
 * @example
 * @par Ejemplo
 * @code
 * const char *fmt = "08.3d";
 * t_flags flags;
 * init_flags(&flags);
 * fmt = ft_printf_flags(fmt, &flags);
 * // Resultado:
 * // flags.zero = true
 * // flags.width = 8
 * // flags.dot = true
 * // flags.precision = 3
 * // flags.type = 'd'
 * // fmt ahora apunta al carácter después de 'd'
 * @endcode
 */
const char	*ft_printf_flags(const char *s, t_flags *f)
{
	if (!s || !f)
		return (NULL);
	while (*s)
	{
		if (parse_flag(&s, f))
			continue ;
		if (parse_width(&s, f))
			continue ;
		if (parse_precision(&s, f))
			continue ;
		if (parse_type(&s, f))
			break ;
		return (NULL);
	}
	return (s);
}
