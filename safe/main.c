#include "safe.h"

int main()
{
    char *line;
    int fd = open("data.txt", O_RDONLY);
    int safe = 0;

     while ((line = get_next_line(fd)) != NULL)
    {
        int array[150];
        int size = 0;
        char *token = strtok(line , " \n");
        while (token)
        {
            array[size++] = atoi(token);
            token = strtok(NULL, " \n");
        }
        if (check_if_safe(array, size) || safe_removal(array, size))
        {
            safe++;
        }
        free(line);
    }
    close(fd);
    printf("resultat des safes : %d\n", safe);
    return 0;
}

