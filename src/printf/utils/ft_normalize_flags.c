/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:24:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:40:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

/**
 * @brief Normaliza las banderas aplicables al tipo de formato de carácter 
 * ('c' o '%').
 *
 * @details
 * Desactiva las banderas incompatibles con la conversión de caracteres.
 * 
 * Reglas:
 * - Si está activa la bandera `-` (alineación izquierda) o el tipo es `'c'`,
 *   se desactiva la bandera `0` (relleno con ceros).
 * - Las banderas `+`, `#`, ` ` (espacio) y `.` (precisión) no tienen sentido
 *   para caracteres, por lo que se desactivan siempre.
 *
 * @param f Puntero a la estructura @ref t_flags que contiene las banderas a 
 * ajustar.
 *
 * @note No realiza ninguna acción si @p f es NULL o el tipo no es `'c'` 
 * ni `'%'`.
 *
 * @see ft_normalize_str_flags()
 * @see ft_normalize_num_flags()
 */
void	ft_normalize_char_flags(t_flags *f)
{
	if (!f || (f->type != 'c' && f->type != '%'))
		return ;
	if (f->minus || f->type == 'c')
		f->zero = false;
	f->plus = false;
	f->hash = false;
	f->space = false;
	f->dot = false;
}

/**
 * @brief Normaliza las banderas para conversiones numéricas con signo 
 * ('d' y 'i').
 *
 * @details
 * Ajusta las banderas de acuerdo a las reglas del estándar de printf:
 * - Si se utiliza la bandera `-` (alineación izquierda) o se especifica 
 *   precisión (`.`),
 *   se desactiva la bandera `0` (relleno con ceros).
 * - Si se usa la bandera `+`, se desactiva la bandera de espacio (` `).
 * - La bandera `#` no tiene efecto en enteros con signo y se desactiva.
 *
 * @param f Puntero a la estructura @ref t_flags con las banderas activas.
 *
 * @note No realiza ninguna acción si @p f es NULL o el tipo no es `'d'` 
 * ni `'i'`.
 *
 * @see ft_normalize_unum_flags()
 */
void	ft_normalize_num_flags(t_flags *f)
{
	if (!f || (f->type != 'd' && f->type != 'i'))
		return ;
	if (f->minus || f->dot)
		f->zero = false;
	if (f->plus)
		f->space = false;
	f->hash = false;
}

/**
 * @brief Normaliza las banderas para conversiones numéricas sin signo 
 * ('u', 'x', 'X').
 *
 * @details
 * - Si se utiliza la bandera `-` (alineación izquierda) o precisión (`.`),
 *   se desactiva la bandera `0` (relleno con ceros).
 * - La bandera `#` (prefijo) solo es válida para tipos hexadecimales (`x`/`X`),
 *   y se desactiva en el caso de `'u'`.
 * - Las banderas `+` y ` ` (espacio) no son aplicables a enteros sin signo.
 *
 * @param f Puntero a la estructura @ref t_flags con las banderas activas.
 *
 * @note No realiza ninguna acción si @p f es NULL o el tipo no es 
 * `'u'`, `'x'` ni `'X'`.
 *
 * @see ft_normalize_num_flags()
 */
void	ft_normalize_unum_flags(t_flags *f)
{
	if (!f || (f->type != 'u' && f->type != 'x' && f->type != 'X'))
		return ;
	if (f->minus || f->dot)
		f->zero = false;
	if (f->type == 'u')
		f->hash = false;
	f->space = false;
	f->plus = false;
}

/**
 * @brief Normaliza las banderas para conversiones de punteros ('p').
 *
 * @details
 * Los punteros se imprimen como valores hexadecimales precedidos de "0x".
 * 
 * Según el comportamiento estándar de printf:
 * - Ninguna bandera afecta su representación.
 * - Se desactivan todas las banderas (`0`, `+`, `#`, ` `, `.`).
 *
 * @param f Puntero a la estructura @ref t_flags que contiene las banderas.
 *
 * @note No realiza ninguna acción si @p f es NULL o el tipo no es `'p'`.
 *
 * @see ft_normalize_unum_flags()
 */
void	ft_normalize_ptr_flags(t_flags *f)
{
	if (!f || f->type != 'p')
		return ;
	f->zero = false;
	f->plus = false;
	f->hash = false;
	f->space = false;
	f->dot = false;
}

/**
 * @brief Normaliza las banderas para conversiones de cadena ('s').
 *
 * @details
 * Las banderas de formato numéricas no tienen efecto sobre las cadenas.
 * 
 * Reglas:
 * - Se desactivan las banderas `0`, `+`, `#` y ` `.
 * - La bandera de precisión (`.`) sigue siendo válida para limitar la longitud.
 *
 * @param f Puntero a la estructura @ref t_flags con las banderas a ajustar.
 *
 * @note No realiza ninguna acción si @p f es NULL o el tipo no es `'s'`.
 *
 * @see ft_normalize_char_flags()
 */
void	ft_normalize_str_flags(t_flags *f)
{
	if (!f || f->type != 's')
		return ;
	f->zero = false;
	f->plus = false;
	f->hash = false;
	f->space = false;
}
