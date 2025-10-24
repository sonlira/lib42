/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:12:20 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 19:22:29 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Verifica si un carácter es un espacio en blanco.
 *
 * Comprueba si el valor recibido corresponde a un carácter
 * de espacio en blanco del conjunto ASCII:
 * '\t' (tabulación), '\n' (nueva línea), '\v' (tab vertical),
 * '\f' (salto de página), '\r' (retorno de carro) o ' ' (espacio).
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return true si el carácter es un espacio en blanco;
 *         false en caso contrario.
 *
 * @example
 * ft_isspace(' ');  // -> true
 * ft_isspace('\n'); // -> true
 * ft_isspace('A');  // -> false
 * ft_isspace('\a'); // -> false
 */
bool	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
