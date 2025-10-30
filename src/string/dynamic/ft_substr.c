/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:04:22 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Crea una subcadena a partir de una cadena dada.
 *
 * Devuelve una nueva cadena que comienza en el índice `start` de la cadena `s`
 * y tiene como máximo `len` caracteres. La subcadena resultante se almacena en
 * memoria dinámica e incluye el carácter nulo final (`'\0'`).
 *
 * Si `start` es mayor o igual que la longitud de `s`, la función devuelve una
 * cadena vacía (no `NULL`). Si `s` es nulo o la reserva de memoria falla, se
 * devuelve `NULL`.
 *
 * @param s      Puntero a la cadena original desde la cual extraer la subcadena.
 * @param start  Índice inicial (basado en cero) desde donde comienza la copia.
 * @param len    Longitud máxima de la subcadena a extraer.
 *
 * @return Un puntero a la nueva subcadena creada, o `NULL` si `s` es nulo o
 *         si no se pudo asignar memoria. Si `start` está fuera de rango, se
 *         devuelve una cadena vacía (`""`).
 *
 * @note Esta función es segura frente a punteros nulos, a diferencia de la
 *       función estándar `strndup`, y ajusta automáticamente la longitud si
 *       `len` excede el tamaño restante de `s`.
 *
 * @example
 * const char *text = "Hola mundo";
 *
 * char *sub = ft_substr(text, 5, 3);
 * // sub -> "mun"
 *
 * char *empty = ft_substr(text, 50, 5);
 * // empty -> "" (cadena vacía)
 *
 * free(sub);
 * free(empty);
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*result;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen_safe(s))
		return (ft_strdup(""));
	size = ft_strlen_safe(s + start);
	if (size > len)
		size = len;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (s + start), (size + 1));
	return (result);
}
