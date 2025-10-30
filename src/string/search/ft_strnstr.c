/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:21:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Busca una subcadena dentro de otra cadena dentro de un límite dado.
 *
 * Esta función busca la primera aparición de la subcadena `needle` dentro de
 * los primeros `len` caracteres de `haystack`. Si la subcadena se encuentra,
 * se devuelve un puntero al inicio de la coincidencia dentro de `haystack`.
 * La búsqueda no modifica las cadenas originales.
 *
 * @param haystack Puntero a la cadena donde se realizará la búsqueda.
 * @param needle   Puntero a la subcadena que se desea localizar.
 * @param len      Número máximo de caracteres de `haystack` que se examinarán.
 *
 * @return Un puntero al inicio de la coincidencia si se encuentra;
 *         `NULL` si no se encuentra o si alguno de los argumentos es inválido.
 *
 * @note Si `needle` es una cadena vacía (`""`), se devuelve `haystack`.
 *       Esta versión valida punteros y evita accesos fuera de rango
 *       incluso si `len` es menor que la longitud real de las cadenas.
 *
 * @example
 * char *str = "hola mundo";
 * char *found = ft_strnstr(str, "ola", 4);  // found -> "ola mundo"
 * char *none  = ft_strnstr(str, "mundo", 4); // none  -> NULL
 * char *empty = ft_strnstr(str, "", 4);     // empty -> "hola mundo"
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	ssize_t	needle_len;

	if (!haystack || !needle || !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	needle_len = ft_strlen_safe(needle);
	if (needle_len == FT_ERROR)
		return (NULL);
	while (haystack[i] && i < len)
	{
		if ((len - i) < (size_t)needle_len)
			break ;
		j = 0;
		while ((i + j) < len && (haystack[i + j] == needle[j]))
		{
			if (!needle[++j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
