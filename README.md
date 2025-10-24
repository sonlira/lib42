# lib42
Librería personal en C inspirada en la filosofía de la _libft_ de 42.  
Proporciona un conjunto de funciones reutilizables para proyectos en C, organizadas en módulos coherentes y fácilmente mantenibles.

## Descripción general

**lib42** es una colección modular de utilidades que extienden y mejoran las funciones estándar de C.  
Incluye herramientas para manejo de memoria, cadenas, arrays, entrada/salida, conversión de datos, y una implementación personalizada de `printf` y `get_next_line`.

Cada módulo está diseñado para ser independiente y legible, manteniendo compatibilidad con entornos POSIX.

## Estructura del proyecto

```php
├── include/           # Cabeceras públicas
│   ├── bases.h
│   ├── ctype.h
│   ├── error.h
│   ├── gnl.h
│   ├── includes.h
│   ├── io.h
│   ├── lib42.h
│   ├── memory.h
│   ├── printf.h
│   ├── string.h
│   └── utils.h
│
├── src/               # Código fuente organizado por módulos
│   ├── ctype/         # Funciones de clasificación de caracteres
│   ├── gnl/           # get_next_line
│   ├── io/            # Funciones de salida en file descriptors
│   ├── memory/        # Manejo de memoria
│   ├── printf/        # printf y snprintf personalizados
│   ├── string/        # Funciones de manipulación de cadenas
│   └── utils/         # Arrays, matrices, conversiones y utilidades
│
├── LICENSE
├── Makefile
└── README.md

```
## Instalación

#### 1. Clonar el repositorio:

```bash
git clone https://github.com/<usuario>/lib42.git
cd lib42
```
#### 2. Compilar la librería:

```bash
make
```
#### 3. Instalar en tu sistema (opcional):
```bash
sudo make install
```
Esto generará un archivo estático `lib42.a` dentro del directorio raíz o en `./lib/`, según tu Makefile.

## Uso

#### Para incluir la librería en tu proyecto:

```c
#include "lib42.h"
```
#### Y al compilar tu programa:

```bash
cc main.c -L. -l42 -o main
```
#### O, si usas un Makefile:

```makefile
NAME = my_program
SRC = main.c
LIBS = -L./lib42 -l42

all:
	cc $(SRC) $(LIBS) -o $(NAME)
```
### Módulos principales

| Módulo     |Descripción                                                                                            |
| ---------- | ----------------------------------------------------------------------------------------------------- |
| **memory** | Funciones de asignación, copia y limpieza de memoria (`ft_calloc`, `ft_memcpy`, etc.)                 |
| **string** | Manipulación de cadenas, concatenación, búsqueda y segmentación (`ft_split`, `ft_strdup`, etc.)       |
| **io**     | Salida en file descriptors (`ft_putendl_fd`, `ft_putnbr_fd`, etc.)                                    |
| **printf** | Implementación personalizada de `printf` y `snprintf`                                                 |
| **ctype**  | Clasificación de caracteres (`ft_isalpha`, `ft_isdigit`, etc.)                                        |
| **gnl**    | Lectura línea a línea (`get_next_line`)                                                               |
| **utils**  | Funciones auxiliares para arrays, matrices y conversiones (`ft_arraylen`, `ft_atoi`, `ft_itoa`, etc.) |

## Estilo de commits y ramas

El proyecto sigue una organización de ramas sencilla:

- **main** versiones estables o beta utilizables.
- **dev** rama de desarrollo activo y experimental.

Los mensajes de commit usan el formato **conventional commits:**

```makefile
feat(module): descripción corta de la funcionalidad
fix(module): descripción del bug corregido
chore: cambios menores o de mantenimiento
docs: documentación y comentarios
```
## Estado actual

Versión **0.9-beta**

Esta versión compila correctamente y es funcional.  
Actualmente se han realizado pruebas básicas de funcionamiento, pero aún faltan pruebas exhaustivas y de casos límite.

## Licencia

Este proyecto se distribuye bajo la licencia **MIT**.  
Consulta el archivo `LICENSE` para más detalle
