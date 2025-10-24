/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:16:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 22:23:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

/* ************************************************************************** */
/*                         FUNCIONES DE MEMORIA (MEMORY)                      */
/* ************************************************************************** */

/**
 * Estas funciones operan sobre bloques de memoria o bytes individuales.
 * Incluyen utilidades de inicialización, copia, búsqueda y comparación.
 * Algunas versiones seguras controlan punteros nulos y desbordamientos.
 */

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
ssize_t	ft_memcmp(const void *s1, const void *s2, size_t n);

/* ************************************************************************** */
/*                   FUNCIONES DE MEMORIA DINÁMICA Y GESTIÓN                  */
/* ************************************************************************** */

/**
 * Funciones que gestionan memoria dinámica.
 * Incluyen inicialización segura, liberación total de arrays
 * y utilidades de liberación que retornan NULL (#add).
 */

void	*ft_calloc(size_t count, size_t size);
void	ft_free_array(void ***array); // # add
void	*ft_free_array_ret(void **array); // # add
void	ft_free_array_n(void ***array, size_t n); // # add
void	*ft_free_array_n_ret(void **array, size_t n); // # add
void	ft_free(void **ptr); // # add versión segura
void	*ft_free_ret(void *ptr); // # add versión cómoda

#endif
