# get_next_line

## Project Overview
`get_next_line` is a project that implements a function that reads a line from a file descriptor (usually `STDIN`, a file, or a socket) one line at a time. The function is designed to read input until it encounters a newline (`\n`) character, allowing the program to process input line-by-line.

This function is useful for applications that need to process large amounts of data or text input in a more efficient, memory-conscious manner, such as reading from log files, text files, or network streams.

## Function Prototype
```c
char *get_next_line(int fd);
```
Parameters:

    fd: The file descriptor from which to read. This could represent a file, STDIN, or any other input stream.

Return Value:

    Returns a dynamically allocated string containing the next line of text from the file descriptor.
    Returns NULL when there is no more data to read (e.g., end of file or error).

Requirements

    The function must be able to handle any size of file or input stream.
    The function should read and return one line at a time.
    The function must handle large input efficiently by using memory allocation.
    It must not use the standard library function get_next_line or similar high-level I/O functions.

Memory Management:

    The function should handle memory properly, freeing the memory used to store lines when no longer needed.
    After returning a line, it should maintain state across multiple calls to continue reading from the same file descriptor.
Compilation

To compile the project, use the following make command:
```bash
make
```
This will compile the get_next_line function into an object file (get_next_line.o) and create an executable or static library depending on your setup.
