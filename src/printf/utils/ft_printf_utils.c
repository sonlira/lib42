/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:17:33 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 14:12:12 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Comprueba si un carácter es una bandera (flag) válida de printf.
 *
 * Evalúa si el carácter pasado corresponde a alguna de las banderas básicas
 * reconocidas por ft_printf: '-', '0', '#', '+', o ' ' (espacio).
 *
 * @param c Carácter a comprobar.
 * @return @c true si el carácter es una flag válida, o @c false en caso
 *        contrario.
 *
 * @example
 * @par Ejemplo
 * @code
 * ft_isflag_simple('-'); // true
 * ft_isflag_simple('x'); // false
 * @endcode
 */
bool	ft_isflag_simple(int c)
{
	return (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ');
}

/**
 * @brief Comprueba si un carácter es un especificador de tipo válido en printf.
 *
 * Determina si el carácter pertenece al conjunto de conversiones soportadas
 * por ft_printf: 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X' o '%'.
 *
 * @param c Carácter a comprobar.
 * @return @c true si el carácter es un tipo válido, o @c false si no lo es.
 *
 * @example
 * @par Ejemplo
 * @code
 * ft_is_valid_type('d'); // true
 * ft_is_valid_type('k'); // false
 * @endcode
 */
bool	ft_is_valid_type(int c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

/**
 * @brief Inicializa una estructura de control de formato @p t_flags.
 *
 * @details
 * Limpia todos los campos de la estructura mediante @c ft_bzero() y establece
 * valores por defecto seguros para el parsing de formatos de printf.
 *
 * En caso de recibir un puntero nulo, la función no realiza ninguna acción
 * y devuelve @c false, lo que permite al llamador abortar el proceso de formato
 * de manera controlada.
 *
 * @param f Puntero a una estructura @p t_flags que se desea inicializar.
 *
 * @return @c true si la estructura fue inicializada correctamente,
 *         o @c false si el puntero @p f es nulo.
 *
 * @note Esta función debe llamarse antes de analizar un nuevo formato
 *       (normalmente al detectar un carácter '%').
 *
 * @example
 * @par Ejemplo
 * @code
 * t_flags flags;
 * if (!init_flags(&flags))
 *     return (FT_ERROR); // puntero inválido
 * // estructura lista para usar
 * // flags.zero == false
 * // flags.width == 0
 * @endcode
 */
bool	init_flags(t_flags *f)
{
	if (!f)
		return (false);
	ft_bzero(f, sizeof(*f));
	return (true);
}
