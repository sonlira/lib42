/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:54:14 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 13:59:05 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Busca la última aparición de un carácter en una cadena.
 *
 * Recorre la cadena `s` desde el final hacia el principio hasta encontrar
 * la última coincidencia con el carácter `c`. Devuelve un puntero a la posición
 * donde se encuentra dicha coincidencia dentro de `s`.
 *
 * Si el carácter buscado es `'\0'`, la función devuelve un puntero al
 * terminador nulo del final de la cadena. Si no se encuentra el carácter,
 * devuelve `NULL`.
 *
 * A diferencia de la función estándar `strrchr`, esta versión es segura frente
 * a punteros nulos: si `s` es inválido, devuelve `NULL` en lugar de provocar
 * un fallo de segmentación.
 *
 * @param s  Puntero a la cadena de caracteres donde se realizará la búsqueda.
 * @param c  Carácter que se desea localizar (interpretado como `unsigned char`).
 *
 * @return Un puntero a la última ocurrencia del carácter `c` dentro de `s`,
 *         un puntero al terminador nulo si `c` es `'\0'`, o `NULL` si el
 *         carácter no se encuentra o si `s` es nulo.
 *
 * @note La búsqueda se realiza en sentido inverso, comenzando desde el
 *       terminador nulo de la cadena y retrocediendo hasta el inicio.
 *
 * @example
 * const char *str = "Hola mundo";
 * char *ptr = ft_strrchr(str, 'o');
 * // ptr -> apunta al último 'o' en "mundo"
 *
 * ptr = ft_strrchr(str, 'x');
 * // ptr -> NULL (no se encontró el carácter)
 *
 * ptr = ft_strrchr(str, '\0');
 * // ptr -> apunta al terminador nulo al final de "Hola mundo"
 */
char	*ft_strrchr(const char *s, int c)
{
	ssize_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == (char)c)
			return ((char *)&s[length]);
		length--;
	}
	return (NULL);
}
