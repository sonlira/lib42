/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:59:05 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 14:38:04 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static char	*g_store[FD_MAX];

static bool	read_fd_to_store(int fd)
{
	char	*buffer;
	char	*joined;
	ssize_t	bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(*buffer));
	if (!buffer)
		return (false);
	while (true)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), false);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!g_store[fd] && !ft_strassign(&g_store[fd], ""))
			return (free(buffer), false);
		joined = ft_strjoin(g_store[fd], buffer);
		if (!joined)
			return (ft_free((void **)&g_store[fd]), free(buffer), false);
		ft_strreplace(&g_store[fd], joined);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), true);
}

static char	*extract_line(char **store)
{
	char	*newline_pos;
	char	*remaining;
	char	*line;

	newline_pos = ft_strchr(*store, '\n');
	if (newline_pos && newline_pos[1])
	{
		line = ft_substr(*store, 0, newline_pos - *store + 1);
		if (!line)
			return (ft_free((void **)store), NULL);
		remaining = ft_strdup(newline_pos + 1);
		if (!remaining)
			return (ft_free((void **)store), ft_free_ret(line));
	}
	else
	{
		line = ft_strdup(*store);
		if (!line)
			return (ft_free((void **)store), NULL);
		remaining = NULL;
	}
	ft_strreplace(store, remaining);
	return (line);
}

/**
 * @brief Lee y devuelve una línea del descriptor de archivo especificado.
 *
 * Esta función lee de forma incremental desde un descriptor de archivo `fd`
 * y devuelve la siguiente línea disponible, incluyendo el salto de línea `'\n'`
 * si lo hay. Internamente utiliza un almacenamiento estático (`g_store`)
 * para conservar los datos sobrantes entre llamadas sucesivas al mismo `fd`.
 *
 * @param fd Descriptor de archivo del cual se desea leer.
 *            Debe ser un valor válido y menor que `FD_MAX`.
 *
 * @return
 * - Un puntero a la cadena leída (incluyendo `'\n'` si existe).
 * - `NULL` en caso de error, fin de archivo, o si no hay más datos disponibles.
 *
 * @note
 * La memoria devuelta debe liberarse manualmente por el usuario con `free()`.
 * Es necesario llamar a `get_next_line_free(fd)` para limpiar la memoria
 * estática asociada a un descriptor cuando ya no se use.
 */
char	*get_next_line(int fd)
{
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_fd_to_store(fd))
		return (NULL);
	if (!g_store[fd] || !*g_store[fd])
		return (ft_free((void **)&g_store[fd]), NULL);
	return (extract_line(&g_store[fd]));
}

/**
 * @brief Libera la memoria interna asociada a un descriptor de archivo.
 *
 * Esta función limpia el almacenamiento estático (`g_store[fd]`) utilizado por
 * `get_next_line()` para el descriptor de archivo indicado. Es útil cuando se
 * termina de leer un archivo o antes de cerrar el `fd`, 
 * evitando fugas de memoria.
 *
 * @param fd Descriptor de archivo cuya memoria asociada debe liberarse.
 *        Si el descriptor no es válido, la función no realiza ninguna acción.
 */
void	get_next_line_free(int fd)
{
	if (fd < 0 || fd >= FD_MAX)
		return ;
	ft_free((void **)&g_store[fd]);
}
