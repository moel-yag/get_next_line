

#include "get_next_line_bonus.h"
// #include "get_next_line.h"

int main()
{
    char *line;
    int fd[3];
    fd[0] = open("test.txt", O_RDONLY);
    fd[1] = open("test2.txt", O_RDONLY);
    fd[2] = open("test3.txt", O_RDONLY);

    line = get_next_line(fd[0]);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd[0]);
    }
    printf("\n================================================\n");
    line = get_next_line(fd[1]);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd[1]);
    }
    printf("\n================================================\n");
    line = get_next_line(fd[2]);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd[2]);
    }
    
    return (0);
}