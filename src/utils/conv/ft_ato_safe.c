/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:59:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:24:25 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Convierte una cadena en un entero sin signo de 64 bits de forma segura.
 *
 * Esta función interna realiza la conversión de una cadena decimal a un valor
 * `uint64_t` (entero sin signo de 64 bits). Admite espacios iniciales,
 * un signo opcional ('+' o '-') y valida que no se produzcan errores de formato
 * ni desbordamientos.
 *
 * Si la conversión tiene éxito, almacena el resultado en `*n` y devuelve `true`.
 * En caso de error de formato o desbordamiento, no modifica el valor apuntado
 * y devuelve `false`.
 *
 * El parámetro `strict` determina si se permiten caracteres adicionales
 * después del número convertido:
 * - `strict = true`: la conversión falla si hay cualquier carácter no vacío
 *   tras el número (excepto espacios finales).
 * - `strict = false`: se ignoran los caracteres restantes tras los espacios.
 *
 * @param s Cadena terminada en nulo que representa el número a convertir.
 * @param n Puntero donde se almacenará el valor convertido en caso de éxito.
 * @param strict Si es `true`, requiere que la cadena contenga solo el número
 *               y espacios; si es `false`, ignora el resto de la cadena.
 *
 * @return `true` si la conversión es válida, `false` en caso de error o 
 *        desbordamiento.
 *
 * @note Si la cadena contiene un signo negativo, el valor absoluto se almacena
 *       en `*n`, pero la función puede fallar si el resultado excede el rango
 *       representable por `long long`.
 *
 * @example
 * uint64_t num;
 * if (ft_atoull_safe_core("  +12345  ", &num, true))
 *     printf("%llu\\n", (unsigned long long)num); // imprime 12345
 * else
 *     printf("Error de conversión\\n");
 *
 * @see ft_atoll_safe(), ft_atol_safe(), ft_atoi_safe()
 */
static bool	ft_atoull_safe_core(const char *s, uint64_t *n, bool strict)
{
	int			sign;
	uint64_t	num;

	sign = 1;
	num = 0;
	s = ft_strdrop(s, ft_isspace);
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		num = num * 10 + (*s - '0');
		if ((sign == 1 && num > LLONG_MAX)
			|| (sign == -1 && num > (uint64_t)LLONG_MAX + 1))
			return (false);
		s++;
	}
	s = ft_strdrop(s, ft_isspace);
	if (*s && strict)
		return (false);
	*n = num;
	return (true);
}

/**
 * @brief Convierte una cadena a un número entero largo largo (`long long`)
 *        de forma segura.
 *
 * @details
 * La función `ft_atoll_safe()` convierte la cadena `s` en un valor de tipo
 * `long long`. Controla los espacios iniciales, el signo y verifica
 * que no se produzca un desbordamiento dentro del rango representable
 * por `long long`.
 *
 * Si la conversión tiene éxito, almacena el resultado en `*n` y devuelve `true`.
 * En caso de error de formato o desbordamiento, devuelve `false` y no modifica 
 * `*n`.
 *
 * El parámetro `strict` determina si se permiten caracteres adicionales
 * después del número convertido:
 * - `strict = true`: la cadena debe contener únicamente el número y espacios 
 * opcionales.
 * - `strict = false`: se permiten otros caracteres después del número.
 *
 * @param s Cadena terminada en nulo que representa el número a convertir.
 * @param n Puntero donde se almacenará el valor convertido si la conversión es 
 * 	      válida.
 * @param strict Si es `true`, exige que la cadena contenga solo el número; si es
 *       `false`, se ignoran los caracteres restantes tras los espacios finales.
 *
 * @return `true` si la conversión es válida, `false` si hay error de formato
 *         o desbordamiento.
 *
 * @note Esta función utiliza internamente `ft_atoull_safe_core()` para realizar
 *       la conversión y validar el rango de `long long`.
 *
 * @example
 * long long value;
 * if (ft_atoll_safe("  -9223372036854775807", &value, true))
 *     printf("%lld\\n", value);
 * else
 *     printf("Conversión inválida\\n");
 *
 * @see ft_atoull_safe_core(), ft_atol_safe(), ft_atoi_safe()
 */
bool	ft_atoll_safe(const char *s, long long *n, bool strict)
{
	uint64_t	num;

	if (!s || !n)
		return (false);
	if (!ft_atoull_safe_core(s, &num, strict))
		return (false);
	*n = (long long)(num);
	return (true);
}

/**
 * @brief Convierte una cadena a un número entero largo (`long`) de forma segura.
 *
 * @details
 * La función `ft_atol_safe()` convierte la cadena `s` en un valor de tipo
 * `long`.
 * Internamente utiliza `ft_atoll_safe()` para la conversión y luego verifica
 * que el resultado esté dentro del rango válido de `LONG_MIN` a `LONG_MAX`.
 *
 * Si la conversión tiene éxito, almacena el resultado en `*n` y devuelve `true`.
 * En caso de error de formato, desbordamiento o punteros inválidos, devuelve 
 * `false` y no modifica `*n`.
 *
 * El parámetro `strict` determina si se permiten caracteres adicionales
 * después del número convertido:
 * - `strict = true`: no se permite ningún carácter después del número 
 * (salvo espacios).
 * - `strict = false`: se ignoran los caracteres restantes.
 *
 * @param s Cadena terminada en nulo que representa el número a convertir.
 * @param n Puntero donde se almacenará el valor convertido si la conversión es 
 *       válida.
 * @param strict Controla si se permiten caracteres adicionales después del 
 * 		 número.
 *
 * @return `true` si la conversión se realizó correctamente y el valor está
 * 		 dentro del rango de `long`, o `false` en caso contrario.
 *
 * @example
 * long num;
 * if (ft_atol_safe("  +123456", &num, true))
 *     printf("%ld\\n", num); // imprime 123456
 * else
 *     printf("Conversión inválida\\n");
 *
 * @see ft_atoll_safe(), ft_atoi_safe()
 */
bool	ft_atol_safe(const char *s, long *n, bool strict)
{
	long long	num;

	if (!s || !n)
		return (false);
	if (!ft_atoll_safe(s, &num, strict))
		return (false);
	if (num > LONG_MAX || num < LONG_MIN)
		return (false);
	*n = (long)num;
	return (true);
}

/**
 * @brief Convierte una cadena a un número entero (`int`) de forma segura.
 *
 * @details
 * La función `ft_atoi_safe()` convierte la cadena `s` en un valor de tipo `int`.
 * Internamente utiliza `ft_atol_safe()` para realizar la conversión y comprueba
 * que el valor esté dentro del rango permitido por `INT_MIN` y `INT_MAX`.
 *
 * Si la conversión tiene éxito, almacena el resultado en `*n` y devuelve `true`.
 * En caso de error de formato, punteros inválidos o desbordamiento,
 * devuelve `false` sin modificar `*n`.
 *
 * El parámetro `strict` determina si se permiten caracteres adicionales
 * después del número convertido:
 * - `strict = true`: la cadena debe contener solo el número 
 * (y espacios opcionales).
 * - `strict = false`: se ignoran los caracteres restantes.
 *
 * @param s Cadena terminada en nulo que representa el número a convertir.
 * @param n Puntero donde se almacenará el valor convertido si la conversión es
 * 		 válida.
 * @param strict Controla si se permiten caracteres adicionales tras el número.
 *
 * @return `true` si la conversión es válida y el valor está dentro del rango 
 * 		`int`, `false` en caso contrario.
 *
 * @example
 * int val;
 * if (ft_atoi_safe("42", &val, true))
 *     printf("%d\\n", val); // imprime 42
 * else
 *     printf("Error: cadena inválida\\n");
 *
 * @see ft_atol_safe(), ft_atoll_safe()
 */
bool	ft_atoi_safe(const char *s, int *n, bool strict)
{
	long	num;

	if (!s || !n)
		return (false);
	if (!ft_atol_safe(s, &num, strict))
		return (false);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	*n = (int)num;
	return (true);
}
