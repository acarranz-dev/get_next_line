# get_next_line

**Una función que lee un fichero línea a línea, desde cualquier descriptor de fichero.**

[English](README.md) · [Català](README.ca.md) · **Español**

`Parte del Common Core de 42 Barcelona` · `Rango 1` · `C` · `File descriptors`

---

## Descripción

Cada llamada a `get_next_line(fd)` devuelve la siguiente línea del fichero, con el `\n` incluido, o `NULL` cuando no queda nada por leer. Funciona con ficheros, la entrada estándar y cualquier otro descriptor de fichero.

## Qué enseña

- Cómo funciona `read` y por qué no se detiene al final de una línea.
- **Variables estáticas** para guardar el texto que sobra entre llamadas.
- Gestión del buffer: el tamaño se elige al compilar con `-D BUFFER_SIZE=n` (32 por defecto).
- Gestión cuidadosa de la memoria para que no haya fugas, aunque la lectura se detenga a medias.

## Cómo funciona

La función lee bloques de `BUFFER_SIZE` bytes y los añade a un buffer hasta que encuentra un `\n` o llega al final del fichero. Devuelve el texto hasta el salto de línea y guarda el resto para la siguiente llamada. La versión bonus guarda un buffer por cada descriptor de fichero, así que se pueden leer varios ficheros alternando sin mezclar sus líneas.

## Compilar y ejecutar

```bash
git clone https://github.com/acarranz-dev/get_next_line.git
cd get_next_line

# compile with your own main.c, choosing the buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl

# bonus version (several files at the same time)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

## Estructura del proyecto

```
get_next_line/
├── get_next_line.c / .h              # mandatory part
├── get_next_line_utils.c             # helper functions
├── get_next_line_bonus.c / .h        # bonus: many file descriptors at once
└── get_next_line_utils_bonus.c
```

---

[Más proyectos en mi perfil](https://github.com/acarranz-dev)
