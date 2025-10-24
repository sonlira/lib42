/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:39:19 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/21 17:56:27 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Comprueba si un carácter es válido para formar parte de una base.
 *
 * @param c Carácter a verificar.
 * @return `true` si es imprimible y no es espacio, '+' ni '-'; 
 *          `false` en caso contrario.
 */
static bool	is_valid_base_char(int c)
{
	return (c != '-' && c != '+' && !ft_isspace(c) && ft_isprint(c));
}

/**
 * @brief Verifica que una base sea válida: caracteres únicos e imprimibles.
 *
 * @details
 * La función `ft_is_valid_base()` comprueba que la cadena `src_base` cumpla
 * las condiciones necesarias para representar una base numérica válida.
 * 
 * Para que una base sea válida, debe cumplir todas las siguientes reglas:
 *  - Contener al menos dos símbolos distintos.
 *  - Cada símbolo debe ser imprimible y distinto de los caracteres '+' y '-'.
 *  - No debe contener espacios ni caracteres repetidos.
 *
 * Internamente, la función utiliza un array de 256 elementos booleanos para
 * marcar los caracteres ya encontrados, permitiendo detectar duplicados en
 * tiempo lineal. La memoria del array se limpia con `ft_bzero()` al inicio.
 *
 * @param src_base Cadena que contiene los símbolos de la base.
 *
 * @return
 * `true` si la base es válida,  
 * `false` si:
 *  - El puntero `src_base` es nulo.
 *  - La longitud de la base es menor a 2.
 *  - Contiene caracteres no válidos o repetidos.
 *
 * @note Esta función no asigna memoria dinámica.
 */
bool	ft_is_valid_base(const char *src_base)
{
	bool	seen[256];
	ssize_t	len;
	size_t	i;
	uint8_t	c;

	ft_bzero(seen, sizeof(seen));
	if (!src_base)
		return (false);
	len = ft_strlen(src_base);
	if (len < 2)
		return (false);
	i = 0;
	while (i < (size_t)len)
	{
		c = (uint8_t)src_base[i];
		if (!is_valid_base_char(src_base[i]) || seen[c])
			return (false);
		seen[c] = true;
		i++;
	}
	return (true);
}
