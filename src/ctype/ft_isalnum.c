/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:04:07 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 19:15:07 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Verifica si un carácter es alfanumérico.
 *
 * Comprueba si el valor recibido corresponde a una letra (mayúscula o minúscula)
 * o a un dígito decimal ('0'–'9'). Devuelve true si pertenece a alguno de esos
 * grupos, false en caso contrario.
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return true si el carácter es alfanumérico; false en caso contrario.
 *
 * @note Esta función reutiliza ft_isalpha() y ft_isdigit().
 *
 * @example
 * ft_isalnum('A'); // -> true
 * ft_isalnum('5'); // -> true
 * ft_isalnum('$'); // -> false
 */
bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
