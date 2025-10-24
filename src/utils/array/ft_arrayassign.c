/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayassign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:56:57 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 19:05:45 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Duplica un array de cadenas y lo asigna al destino indicado.
 *
 * La función ft_arrayassign() crea una copia del array de cadenas `array`
 * y la asigna al puntero `*dst`. Si el destino ya contenía un array previo,
 * este se libera de forma segura mediante ft_free_array().
 *
 * @param dst Doble puntero al array de destino. Debe ser válido.
 *            Se espera que sea del tipo `char ***`, compatible con `void ***`.
 * @param array Array de cadenas a copiar. No puede ser NULL.
 *
 * @return `true` si la operación se realiza correctamente,
 *      o `false` si alguno de los parámetros es NULL o si la duplicación falla.
 *
 * @note La memoria anterior apuntada por `*dst` se libera automáticamente
 *       y el puntero se actualiza con la nueva copia.
 *
 * @see ft_arraydup(), ft_free_array()
 */
bool	ft_arrayassign(char ***dst, char **array)
{
	char	**assigned;

	if (!dst || !array)
		return (false);
	assigned = ft_arraydup(array);
	if (!assigned)
		return (false);
	ft_free_array((void ***)dst);
	*dst = assigned;
	return (true);
}
