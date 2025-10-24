/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:09:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 19:20:37 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Verifica si un carácter es imprimible.
 *
 * Comprueba si el valor recibido corresponde a un carácter
 * visible del conjunto ASCII, incluyendo el espacio (' ').
 * Devuelve true para los caracteres comprendidos entre
 * 32 y 126 inclusive.
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return true si el carácter es imprimible; false si es de control
 *         o está fuera del rango ASCII.
 *
 * @example
 * ft_isprint('A');  // -> true
 * ft_isprint(' ');  // -> true
 * ft_isprint('\n'); // -> false
 * ft_isprint(127);  // -> false
 */
bool	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
