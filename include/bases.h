/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bases.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:28:11 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 14:38:16 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASES_H
# define BASES_H

/* ************************************************************************** */
/*                         DEFINICIONES DE BASES (BASES)                      */
/* ************************************************************************** */

/**
 * Este archivo define macros para representar distintas bases numéricas,
 * junto con las cadenas de caracteres que contienen sus dígitos válidos.
 *
 * Está pensado para ser usado en rutinas de conversión numérica,
 * formateo o validación.
 *
 * Ejemplo de uso:
 * @code
 * printf("Base %d: %s\n", BASE_HEX_UPPER, BASE_HEX_UPPER_STR);
 * // Salida: Base 16: 0123456789ABCDEF
 * @endcode
 */

/**
 * @brief Base binaria (2).
 *
 * Representa el sistema numérico binario, compuesto por dos dígitos posibles:
 * '0' y '1'.
 */
# define BASE_BIN        2
/** @brief Cadena de dígitos válidos para la base binaria ("01"). */
# define BASE_BIN_STR    "01"

/**
 * @brief Base octal (8).
 *
 * Representa el sistema numérico octal, compuesto por los dígitos del 
 * '0' al '7'.
 */
# define BASE_OCT        8
/** @brief Cadena de dígitos válidos para la base octal ("01234567"). */
# define BASE_OCT_STR    "01234567"

/**
 * @brief Base decimal (10).
 *
 * Representa el sistema numérico decimal, compuesto por los dígitos del 
 * '0' al '9'.
 */
# define BASE_DEC        10
/** @brief Cadena de dígitos válidos para la base decimal ("0123456789"). */
# define BASE_DEC_STR    "0123456789"

/**
 * @brief Base hexadecimal (16).
 *
 * Utiliza los dígitos '0'–'9' y las letras 'a'–'f'  o 'A'–'F' para representar 
 * valores del 0 al 15.
 */
# define BASE_HEX  16
/** @brief Cadena de dígitos válidos para la base hexadecimal en minúsculas 
 * ("0123456789abcdef"). */
# define BASE_HEX_LOWER_STR  "0123456789abcdef"
/** @brief Cadena de dígitos válidos para la base hexadecimal en mayúsculas 
 * ("0123456789ABCDEF"). */
# define BASE_HEX_UPPER_STR  "0123456789ABCDEF"

#endif
