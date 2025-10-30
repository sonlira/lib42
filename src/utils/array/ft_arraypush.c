/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:01:34 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:02:47 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Añade una nueva cadena al final de un array dinámico.
 *
 * La función ft_arraypush() amplía el array `*array` para añadir una nueva
 * cadena al final. Los punteros existentes se mueven al nuevo array sin
 * duplicar las cadenas, y el array anterior se libera (solo el contenedor).
 *
 * El nuevo valor `val` se duplica internamente mediante ft_strassign(),
 * garantizando que pueda liberarse de forma segura más adelante.
 *
 * @param array Doble puntero al array de destino (terminado en NULL).
 *        Si `*array` es NULL, se crea un nuevo array con un único elemento.
 * @param val   Cadena que se desea añadir al final del array.
 *
 * @return `true` si la operación se realiza correctamente,
 *   o `false` si ocurre un error de memoria o si los parámetros son inválidos.
 *
 * @note Las cadenas existentes no se duplican, solo se reubican.
 *       El nuevo valor se duplica para asegurar su propiedad dinámica.
 *
 * @see ft_arraylen(), ft_calloc(), ft_strassign(), ft_free_array_safe()
 */
bool	ft_arraypush(char ***array, const char *val)
{
	ssize_t	size;
	size_t	i;
	char	**buff;

	if (!array || !val)
		return (false);
	size = ft_arraylen((void **)*array);
	if (size == FT_ERROR)
		return (false);
	buff = ft_calloc((size_t)(size + 2), sizeof(*buff));
	if (!buff)
		return (false);
	if (!ft_strassign(&buff[size], val))
		return (free(buff), false);
	i = 0;
	while (i < (size_t)size && (*array)[i])
	{
		buff[i] = (*array)[i];
		i++;
	}
	free(*array);
	*array = buff;
	return (true);
}
