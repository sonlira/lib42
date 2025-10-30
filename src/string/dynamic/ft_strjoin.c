/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:26:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Concatena dos cadenas de caracteres en una nueva cadena dinámica.
 *
 * Crea una nueva cadena en memoria dinámica que contiene el contenido de `s1`
 * seguido del contenido de `s2`, y finalizada con el carácter nulo `'\0'`.
 * La memoria para la nueva cadena se reserva con `malloc` y debe liberarse con
 * `free()` cuando ya no sea necesaria.
 *
 * Si `s1` o `s2` son nulos, o si la reserva de memoria falla, la función
 * devuelve `NULL`.
 *
 * @param s1  Primera cadena a concatenar.
 * @param s2  Segunda cadena a concatenar.
 *
 * @return Un puntero a la nueva cadena resultante, o `NULL` si se produce un
 *         error de memoria o si alguno de los punteros de entrada es nulo.
 *
 * @note Esta versión es segura frente a punteros nulos, a diferencia de la
 *       función estándar `strcat`, que provoca comportamiento indefinido si
 *       recibe argumentos inválidos.
 *
 * @example
 * const char *s1 = "Hola";
 * const char *s2 = " mundo";
 * char *joined = ft_strjoin(s1, s2);
 *
 * if (!joined)
 *     printf("Error: no se pudo unir las cadenas.\n");
 * else
 * {
 *     printf("%s\n", joined);  // Muestra "Hola mundo"
 *     free(joined);
 * }
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen_safe(s1) + ft_strlen_safe(s2);
	joined = malloc(size + 1);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, (size + 1));
	ft_strlcat(joined, s2, (size + 1));
	return (joined);
}
