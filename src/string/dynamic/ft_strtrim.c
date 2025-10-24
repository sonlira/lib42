/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:43:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 12:41:01 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Elimina los caracteres especificados del inicio y del final de una 
 * cadena.
 *
 * Crea una nueva cadena que es una copia de `s1`, pero sin los caracteres
 * presentes en `set` al principio ni al final. Los caracteres intermedios no
 * se modifican. La memoria para la nueva cadena se reserva dinámicamente y debe
 * liberarse con `free()` cuando ya no sea necesaria.
 *
 * Si `s1` o `set` son nulos, la función devuelve `NULL`. Si todos los caracteres
 * de `s1` están incluidos en `set`, la función devuelve una cadena vacía (`""`).
 *
 * @param s1   Puntero a la cadena original que se desea recortar.
 * @param set  Conjunto de caracteres a eliminar del inicio y del final de `s1`.
 *
 * @return Un puntero a la nueva cadena recortada, o `NULL` si se produce un 
 *         error de memoria o si alguno de los punteros de entrada es nulo.
 *
 * @note Esta función es segura frente a punteros nulos, y utiliza internamente
 *       `ft_substr()` para construir la cadena resultante. La longitud de la
 *       nueva cadena se ajusta automáticamente en función de los recortes.
 *
 * @example
 * const char *s = "  Hola mundo  ";
 * char *trimmed;
 *
 * trimmed = ft_strtrim(s, " ");
 * // trimmed -> "Hola mundo"
 *
 * trimmed = ft_strtrim("###42Madrid###", "#");
 * // trimmed -> "42Madrid"
 *
 * trimmed = ft_strtrim("......", ".");
 * // trimmed -> "" (cadena vacía)
 *
 * free(trimmed);
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	ssize_t	size;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, (int)*s1))
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && ft_strchr(set, (int)s1[size - 1]))
		size--;
	return (ft_substr(s1, 0, (size_t)size));
}
