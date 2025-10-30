/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:16:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:22:22 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                             FUNCIONES DE CONVERSIÓN                        */
/* ************************************************************************** */

/**
 * Estas funciones convierten valores numéricos o cadenas de forma segura.
 * Incluyen versiones seguras de las funciones estándar (atoi, atol, atoll)
 * que validan la entrada, detectan desbordamientos y devuelven el resultado
 * mediante un puntero de salida.
 */

/* Conversión básica */

bool	ft_is_valid_base(const char *src_base);
size_t	ft_numlen_base(long long num, size_t base, bool count_signed);
size_t	ft_unumlen_base(uint64_t num, size_t base);
int		ft_atoi(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_base(uint64_t un, const char *src_base);

/* Conversión segura (Safe Ato*) */

bool	ft_atoll_safe(const char *s, long long *n, bool strict);
bool	ft_atol_safe(const char *s, long *n, bool strict);
bool	ft_atoi_safe(const char *s, int *n, bool strict);

/* ************************************************************************** */
/*                             FUNCIONES DE ARRAYS                            */
/* ************************************************************************** */

/**
 * Estas funciones operan sobre arrays (`char **`) terminados en NULL 
 * Incluyen utilidades para duplicar, asignar, añadir o insertar elementos,
 * así como para calcular su longitud de forma segura.
 */

ssize_t	ft_arraylen(void **array);
ssize_t	ft_strslen(char **array);
size_t	ft_putstrs_op(char **array, bool with_index, bool show_num, \
	bool with_total);
size_t	ft_putstrs(char **array);
char	**ft_arraydup(char **array);
bool	ft_arrayassign(char ***dst, char **array);
bool	ft_arraypush(char ***array, const char *val);
bool	ft_arrayunshift(char ***array, const char *val);
void	ft_free_strs_safe(char ***array);
void	ft_free_strs(char **array);
void	*ft_free_strs_ret(char **array);

/* ************************************************************************** */
/*                              FUNCIONES DE MATRICES                         */
/* ************************************************************************** */

/**
 * Funciones para crear matrices bidimensionales dinámicas (`void **`).
 * Permiten reservar memoria para una matriz genérica de tamaño configurable,
 * con opción a añadir un puntero NULL al final para compatibilidad con
 * funciones tipo array (ft_arraylen, ft_free_array_safe, etc.).
 */

void	**ft_create_matrix(size_t rows, size_t cols, size_t size, \
		bool add_null);
void	ft_sfree_matrix(void ***matrix, size_t n);
void	ft_free_matrix(void **matrix, size_t n);
void	*ft_free_matrix_ret(void **matrix, size_t n);

#endif
