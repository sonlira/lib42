/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:59:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 19:16:24 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Verifica si un carácter es una letra del alfabeto.
 *
 * Comprueba si el valor recibido corresponde a una letra
 * mayúscula ('A'–'Z') o minúscula ('a'–'z') en el conjunto ASCII.
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return true si el carácter es una letra; false en caso contrario.
 *
 * @example
 * ft_isalpha('A'); // -> true
 * ft_isalpha('g'); // -> true
 * ft_isalpha('3'); // -> false
 * ft_isalpha('$'); // -> false
 */
bool	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
