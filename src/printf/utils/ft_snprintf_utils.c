/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:50:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:40:24 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

/**
 * @brief Inicializa una estructura de tipo @ref t_snformat.
 *
 * @details
 * Establece todos los campos de la estructura en cero mediante @c ft_bzero(),
 * dejando la estructura lista para su uso en una operación de formateo.
 *
 * No asigna memoria ni modifica punteros externos; únicamente limpia el
 * contenido existente en la estructura proporcionada.
 *
 * @param snf Puntero a la estructura @ref t_snformat que se desea inicializar.
 *
 * @retval true  Si la estructura fue inicializada correctamente.
 * @retval false Si @p snf es NULL.
 *
 * @note
 * Esta función debe llamarse siempre antes de usar la estructura en
 * @ref ft_snprintf() o @ref ft_snprintf_core().
 *
 * @example
 * @code
 * t_snformat snf;
 * if (!init_snformat(&snf))
 *     return (FT_ERROR);
 * snf.s = buffer;
 * snf.n = sizeof(buffer);
 * @endcode
 *
 * @see ft_snprintf()
 * @see ft_snprintf_core()
 */
bool	init_snformat(t_snformat *snf)
{
	if (!snf)
		return (false);
	ft_bzero(snf, sizeof(*snf));
	return (true);
}

/**
 * @brief Escribe un carácter en el buffer de @ref t_snformat.
 *
 * @details
 * Convierte el carácter recibido en un byte sin signo y lo escribe en la
 * posición actual del buffer si hay espacio disponible.  
 * Independientemente de si el carácter cabe o no, incrementa el contador de
 * bytes escritos (`bytes`), lo que permite conocer el total real de salida
 * incluso en caso de truncamiento.
 *
 * @param c   Carácter a escribir.
 * @param snf Puntero a la estructura @ref t_snformat que gestiona el buffer.
 *
 * @note
 * - Si @p snf es NULL, no realiza ninguna acción.  
 * - Si el buffer está lleno, no escribe pero incrementa `bytes`.  
 * - Siempre deja espacio para el terminador nulo.
 *
 * @see ft_putnchar_to_snf()
 * @see ft_putstr_to_snf()
 */
void	ft_putchar_to_snf(int c, t_snformat *snf)
{
	uint8_t	uc;

	if (!snf)
		return ;
	uc = (uint8_t)c;
	if (snf->i < snf->n - 1)
		snf->s[snf->i++] = uc;
	++snf->bytes;
}

/**
 * @brief Escribe el mismo carácter un número determinado de veces.
 *
 * @details
 * Llama repetidamente a @ref ft_putchar_to_snf() para escribir @p n veces el
 * carácter @p c en el buffer gestionado por @p snf.
 *
 * @param c   Carácter a escribir.
 * @param n   Número de veces que debe repetirse.
 * @param snf Puntero a la estructura @ref t_snformat donde se escribirá.
 *
 * @note
 * - Si @p snf es NULL o @p n <= 0, no realiza ninguna acción.  
 * - Controla automáticamente la truncación en caso de que el buffer no
 *   tenga espacio.
 *
 * @see ft_putchar_to_snf()
 */
void	ft_putnchar_to_snf(int c, ssize_t n, t_snformat *snf)
{
	ssize_t	total;

	if (!snf)
		return ;
	total = 0;
	while (total < n)
	{
		ft_putchar_to_snf(c, snf);
		++total;
	}
}

/**
 * @brief Escribe una cadena completa en el buffer de @ref t_snformat.
 *
 * @details
 * Copia carácter por carácter la cadena @p s en el buffer, actualizando tanto
 * la posición actual (`i`) como el contador total de bytes (`bytes`).
 *
 * @param s   Puntero a la cadena de origen (terminada en '\0').
 * @param snf Puntero a la estructura @ref t_snformat que gestiona el 
 * 		 buffer destino.
 *
 * @note
 * - Si @p s o @p snf son NULL, la función no hace nada.  
 * - Se detiene al llegar al terminador nulo o si se agota el espacio.
 * - Garantiza que nunca se escriba fuera del límite del buffer.
 *
 * @see ft_putstrl_to_snf()
 * @see ft_putchar_to_snf()
 */
void	ft_putstr_to_snf(const char *s, t_snformat *snf)
{
	if (!s || !snf)
		return ;
	while (*s)
	{
		ft_putchar_to_snf(*s, snf);
		++s;
	}
}

/**
 * @brief Escribe una cadena limitada por longitud en el buffer de @ref 
 * t_snformat.
 *
 * @details
 * Copia hasta @p len caracteres de la cadena @p s, sin requerir que esté
 * terminada en '\0'.  
 * Ideal para escribir subcadenas o contenido parcial con precisión controlada.
 *
 * @param s    Puntero a la cadena de origen.
 * @param len  Número máximo de caracteres a escribir.
 * @param snf  Puntero a la estructura @ref t_snformat que gestiona el 
 * buffer destino.
 *
 * @note
 * - Si @p s o @p snf son NULL, no realiza ninguna operación.  
 * - Se detiene si encuentra un '\0' antes de alcanzar @p len.  
 * - No añade terminador nulo; este se gestiona al final de @ref 
 *   ft_snprintf_core().
 *
 * @see ft_putstr_to_snf()
 * @see ft_putchar_to_snf()
 */
void	ft_putstrl_to_snf(const char *s, ssize_t len, t_snformat *snf)
{
	ssize_t	i;

	if (!s || !snf)
		return ;
	i = 0;
	while (s[i] && i < len)
		ft_putchar_to_snf(s[i++], snf);
}
