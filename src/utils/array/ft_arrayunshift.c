/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayunshift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:50:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/31 22:05:01 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Inserta una nueva cadena al inicio de un array dinámico.
 *
 * @details
 * La función ft_arrayunshift() amplía el array `*array` para insertar una nueva
 * cadena en la primera posición. Los punteros existentes se desplazan una
 * posición hacia la derecha (sin duplicarse) y el array anterior se libera
 * (solo el contenedor).
 *
 * El nuevo valor `val` se duplica internamente mediante ft_strassign(),
 * garantizando que pueda liberarse de forma segura más adelante.
 *
 * @param array Doble puntero al array de destino (terminado en NULL).
 *        Si `*array` es NULL, se crea un nuevo array con un único elemento.
 * @param val   Cadena que se desea añadir al inicio del array.
 *
 * @return `true` si la operación se realiza correctamente,
 *     o `false` si ocurre un error de memoria o si los parámetros son inválidos.
 *
 * @note No es necesario asignar manualmente el puntero NULL final, ya que
 *       ft_calloc() inicializa todo el bloque a cero.
 *
 * @see ft_arraylen(), ft_calloc(), ft_strassign()
 */
bool	ft_arrayunshift(char ***array, const char *val)
{
	ssize_t	size;
	size_t	i;
	size_t	j;
	char	**buff;

	if (!array || !val)
		return (false);
	size = ft_arraylen((void **)*array);
	buff = ft_calloc((size_t)(size + 2), sizeof(*buff));
	if (!buff)
		return (false);
	if (!ft_strassign(&buff[0], val))
		return (free(buff), false);
	i = 1;
	j = 0;
	while (j < (size_t)size && (*array)[j])
		buff[i++] = (*array)[j++];
	free(*array);
	*array = buff;
	return (true);
}
