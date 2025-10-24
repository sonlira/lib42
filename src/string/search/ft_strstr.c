/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:13:26 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 14:36:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Busca una subcadena dentro de otra cadena completa.
 *
 * Esta función localiza la primera aparición de la subcadena `needle`
 * dentro de la cadena `haystack`. Si se encuentra, devuelve un puntero
 * al inicio de la coincidencia. La búsqueda se realiza sobre toda la cadena
 * y no modifica ninguna de las dos.
 *
 * @param haystack Puntero a la cadena en la que se buscará la subcadena.
 * @param needle   Puntero a la subcadena que se desea localizar.
 *
 * @return Un puntero al inicio de la coincidencia si se encuentra `needle`;
 *         `haystack` si `needle` es una cadena vacía (`""`);
 *         `NULL` si los punteros son inválidos o si no se encuentra la 
 * 			subcadena.
 *
 * @note Esta versión es la variante sin límite de `ft_strnstr`.
 *       Internamente delega la búsqueda en `ft_strnstr` con un rango de 
 * 		 `SIZE_MAX` para garantizar seguridad y coherencia de comportamiento.
 *
 * @example
 * char *str = "hola mundo";
 * char *found = ft_strstr(str, "mundo"); // found -> "mundo"
 * char *none  = ft_strstr(str, "code");  // none  -> NULL
 * char *empty = ft_strstr(str, "");      // empty -> "hola mundo"
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!haystack || !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	return (ft_strnstr(haystack, needle, SIZE_MAX));
}
