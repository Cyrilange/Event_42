#include "safe_unsafe.h"

int main()
{
    char *line;
    int fd = open("data.txt", O_RDONLY);
    int safe = 0;

    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line reed : %s", line);
        int array[150];
        int size = 0;
        char *token = strtok(line, " \n");
        while (token != NULL)
        {
            array[size++] = atoi(token);
            token = strtok(NULL, " \n");
        }

   
        if ((is_sorted_ascending(array, size) || is_sorted_descending(array, size)) && is_no_duplicate(array, size) && is_valid(array, size))
         {  
            printf("SAFE\n");
            safe++;
         }
        free(line);
    }
    
   
    close(fd);
    printf("\nil y a %d ligne safe\n", safe);
    return 0;
}