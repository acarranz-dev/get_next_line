# get_next_line

**Una funció que llegeix un fitxer línia a línia, des de qualsevol descriptor de fitxer.**

[English](README.md) · **Català** · [Español](README.es.md)

`Part del Common Core de 42 Barcelona` · `Rang 1` · `C` · `File descriptors`

---

## Descripció

Cada crida a `get_next_line(fd)` retorna la línia següent del fitxer, amb el `\n` inclòs, o `NULL` quan no queda res per llegir. Funciona amb fitxers, l'entrada estàndard i qualsevol altre descriptor de fitxer.

## Què ensenya

- Com funciona `read` i per què no s'atura al final d'una línia.
- **Variables estàtiques** per guardar el text que sobra entre crides.
- Gestió del buffer: la mida es tria en compilar amb `-D BUFFER_SIZE=n` (32 per defecte).
- Gestió acurada de la memòria perquè no hi hagi fuites, encara que la lectura s'aturi a mitges.

## Com funciona

La funció llegeix blocs de `BUFFER_SIZE` bytes i els afegeix a un buffer fins que troba un `\n` o arriba al final del fitxer. Retorna el text fins al salt de línia i guarda la resta per a la crida següent. La versió bonus guarda un buffer per cada descriptor de fitxer, així que es poden llegir diversos fitxers alternant sense barrejar-ne les línies.

## Compilar i executar

```bash
git clone https://github.com/acarranz-dev/get_next_line.git
cd get_next_line

# compile with your own main.c, choosing the buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl

# bonus version (several files at the same time)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

## Estructura del projecte

```
get_next_line/
├── get_next_line.c / .h              # mandatory part
├── get_next_line_utils.c             # helper functions
├── get_next_line_bonus.c / .h        # bonus: many file descriptors at once
└── get_next_line_utils_bonus.c
```

---

[Més projectes al meu perfil](https://github.com/acarranz-dev)
