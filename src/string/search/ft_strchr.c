/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:43:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 19:07:12 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Busca la primera aparición de un carácter en una cadena.
 *
 * Recorre la cadena `s` desde el principio hasta encontrar la primera
 * coincidencia con el carácter `c`. Devuelve un puntero a la posición donde
 * se encuentra dicho carácter dentro de `s`.
 *
 * Si el carácter buscado es `'\0'`, la función devuelve un puntero al final
 * de la cadena (es decir, al terminador nulo). Si no se encuentra el carácter,
 * devuelve `NULL`.
 *
 * A diferencia de la función estándar `strchr`, esta versión es segura frente
 * a punteros nulos: si `s` es inválido, devuelve `NULL` en lugar de provocar
 * un fallo de segmentación.
 *
 * @param s  Puntero a la cadena de caracteres donde se realizará la búsqueda.
 * @param c  Carácter que se desea localizar (interpretado como `unsigned char`).
 *
 * @return Un puntero a la primera ocurrencia del carácter `c` dentro de `s`,
 *         un puntero al terminador nulo si `c` es `'\0'`, o `NULL` si el
 *         carácter no se encuentra o si `s` es nulo.
 *
 * @example
 * const char *str = "Hola mundo";
 * char *ptr = ft_strchr(str, 'm');
 * // ptr -> apunta a "mundo"
 *
 * ptr = ft_strchr(str, 'z');
 * // ptr -> NULL (no se encontró el carácter)
 *
 * ptr = ft_strchr(str, '\0');
 * // ptr -> apunta al terminador nulo al final de "Hola mundo"
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
