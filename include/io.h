/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:05 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:54:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

/* ************************************************************************** */
/*                        SALIDA DE CARACTERES Y CADENAS                      */
/* ************************************************************************** */

/**
 * Funciones que imprimen caracteres o cadenas completas.
 * No asignan memoria ni modifican las cadenas originales.
 */

ssize_t	ft_putchar_fd(int c, int fd);
ssize_t	ft_putnchar_fd(int c, ssize_t n, int fd); // # add
ssize_t	ft_putstr_fd(const char *s, int fd);
ssize_t	ft_putstrl_fd(const char *s, ssize_t len, int fd); // # add
ssize_t	ft_putendl_fd(const char *s, int fd);

/* ************************************************************************** */
/*                           SALIDA DE NÚMEROS                                */
/* ************************************************************************** */

/**
 * Funciones que imprimen valores numéricos en distintas representaciones.
 * Todas son seguras frente a desbordamientos y controlan el signo.
 */

ssize_t	ft_putnbr_fd(int n, int fd);
ssize_t	ft_putunbr_fd(unsigned int un, int fd); // # add
ssize_t	ft_puthex_fd(uint64_t un, int fd, bool upper); // # add
ssize_t	ft_putptr_fd(void *ptr, int fd); // # add

/* ************************************************************************** */
/*                          SALIDA EN BASE PERSONALIZADA                      */
/* ************************************************************************** */

/**
 * Función que imprime un número entero en una base definida por el usuario.
 * 
 * La base debe ser una cadena con al menos dos caracteres únicos e imprimibles
 * (por ejemplo: "01", "0123456789ABCDEF", "poneyvif").
 * 
 * Soporta el caso `INT_MIN` mediante conversión a `unsigned int` para evitar
 * desbordamientos al invertir el signo.
 */

ssize_t	ft_putnbr_base_fd(unsigned int un, const char *base, int fd); // # add

#endif