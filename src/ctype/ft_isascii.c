/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:06:26 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 19:18:41 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Verifica si un valor pertenece al conjunto ASCII.
 *
 * Comprueba si el valor recibido se encuentra dentro del rango
 * ASCII estándar (0–127). Devuelve true si pertenece a ese rango.
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return true si el valor está en el rango ASCII (0–127);
 *         false en caso contrario.
 *
 * @example
 * ft_isascii('A');   // -> true
 * ft_isascii(200);   // -> false
 * ft_isascii(-5);    // -> false
 */
bool	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
