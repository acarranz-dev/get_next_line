# get_next_line

**A function that reads a file one line at a time, from any file descriptor.**

**English** · [Català](README.ca.md) · [Español](README.es.md)

`Part of the 42 Barcelona Common Core` · `Rank 1` · `C` · `File descriptors`

---

## Description

Each call to `get_next_line(fd)` returns the next line of the file, including the `\n`, or `NULL` when there is nothing left to read. It works with files, standard input and any other file descriptor.

## What it teaches

- How `read` works and why it does not stop at the end of a line.
- **Static variables** to keep the leftover text between calls.
- Buffer management: the buffer size is chosen at compile time with `-D BUFFER_SIZE=n` (32 by default).
- Careful memory handling so that nothing leaks, even when reading stops halfway.

## How it works

The function reads blocks of `BUFFER_SIZE` bytes and adds them to a buffer until it finds a `\n` or reaches the end of the file. It returns the text up to the newline and keeps the rest for the next call. The bonus version keeps one buffer per file descriptor, so several files can be read alternately without mixing their lines.

## Build and run

```bash
git clone https://github.com/acarranz-dev/get_next_line.git
cd get_next_line

# compile with your own main.c, choosing the buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl

# bonus version (several files at the same time)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

## Project structure

```
get_next_line/
├── get_next_line.c / .h              # mandatory part
├── get_next_line_utils.c             # helper functions
├── get_next_line_bonus.c / .h        # bonus: many file descriptors at once
└── get_next_line_utils_bonus.c
```

---

[More projects on my profile](https://github.com/acarranz-dev)
