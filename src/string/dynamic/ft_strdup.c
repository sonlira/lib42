/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:13:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/12 19:24:59 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Duplica una cadena de caracteres en memoria dinámica.
 *
 * Reserva memoria suficiente para crear una nueva copia de la cadena `s`
 * e incluye el carácter nulo final (`'\0'`). Devuelve un puntero al nuevo
 * bloque de memoria que contiene la copia exacta de la cadena original.
 *
 * Si `s` es nulo o la reserva de memoria falla, la función devuelve `NULL`.
 * La memoria devuelta debe liberarse con `free()` cuando ya no sea necesaria.
 *
 * @param s  Puntero a la cadena de caracteres a duplicar.
 *
 * @return Un puntero a la nueva cadena duplicada, o `NULL` si `s` es nulo o
 *         si `malloc` no pudo asignar memoria.
 *
 * @note Esta versión es segura frente a punteros nulos, a diferencia de la
 *       función estándar `strdup`, que provoca comportamiento indefinido si
 *       se le pasa un puntero inválido.
 *
 * @example
 * const char *src = "Hola mundo";
 * char *dup = ft_strdup(src);
 *
 * if (!dup)
 *     printf("Error: no se pudo duplicar la cadena.\n");
 * else
 * {
 *     printf("Copia: %s\n", dup);
 *     free(dup);
 * }
 */
char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dup;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	dup = malloc(size + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, (size + 1));
	return (dup);
}
