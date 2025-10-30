/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:16:24 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:12:49 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

/* ************************************************************************** */
/*                            STRINGS BÁSICAS                                 */
/* ************************************************************************** */

/**
 * Funciones que operan sobre cadenas sin asignar memoria dinámica.
 * No modifican ni liberan las cadenas originales.
 */

ssize_t		ft_strlen_safe(const char *str);
size_t		ft_strlen(const char *str);
ssize_t		ft_count_char(const char *s, int c); // # add
ssize_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
ssize_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
ssize_t		ft_strncmp(const char *s1, const char *s2, size_t n);
ssize_t		ft_strcmp(const char *s1, const char *s2); // # add
bool		ft_strreplace(char **dst, char *src); // # add
bool		ft_strreplace_safe(char **dst, char *src); // # add
int			ft_tolower(int c);
int			ft_toupper(int c);

/* ************************************************************************** */
/*                           STRINGS DE BÚSQUEDA                              */
/* ************************************************************************** */

/**
 * Funciones que buscan caracteres o subcadenas dentro de otras cadenas.
 * No modifican ni reservan memoria; devuelven punteros dentro de la cadena 
 * original.
 */

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strstr(const char *haystack, const char *needle); // # add

/* ************************************************************************** */
/*                           STRINGS DINÁMICAS                                */
/* ************************************************************************** */

/**
 * Funciones que crean, duplican o reemplazan cadenas
 * utilizando memoria dinámica (malloc/free).
 * El usuario es responsable de liberar la memoria resultante.
 */

char		*ft_strdup(const char *s);
bool		ft_strassign(char **dest, const char *src); // # add
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *s, char c);
void		ft_free_split_safe(char ***split); // # add
void		ft_free_split(char **split);
void		*ft_free_split_ret(char **split);

/* ************************************************************************** */
/*                           STRINGS FUNCIONALES                              */
/* ************************************************************************** */

/**
 * Funciones que aplican transformaciones o funciones externas
 * sobre cadenas (paradigma funcional).
 */

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
const char	*ft_strdrop(const char *s, bool (*f)(int)); // # add
const char	*ft_strseek(const char *s, bool (*f)(int)); // # add
#endif
