

#include "get_next_line.h"
// # define BUFFER_SIZE 0x7fffffff
// void func(size_t size)
// {
//     printf("%zu", size);
// }

int main()
{
    char *line;
    int fd;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }

    // func(BUFFER_SIZE + 1UL );
    return (0);
}