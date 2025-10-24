/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:02:47 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 19:17:25 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Verifica si un carácter es un dígito decimal.
 *
 * Comprueba si el valor recibido corresponde a un número
 * entre '0' y '9' en el conjunto ASCII.
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return true si el carácter es un dígito ('0'–'9');
 *         false en caso contrario.
 *
 * @example
 * ft_isdigit('5'); // -> true
 * ft_isdigit('A'); // -> false
 * ft_isdigit(' '); // -> false
 */
bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
