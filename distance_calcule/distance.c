#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
    int right;
} Pair;

void sort_array(int *arr, int size) 
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1) 
    {
        j = i + 1;
        while (j < size) 
        {
            if (arr[i] > arr[j]) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int calculate_total_distance(int *left_list, int *right_list, int size)
{
    int total_distance = 0;
    int i = 0;
    while (i < size) 
    {
        total_distance += abs(left_list[i] - right_list[i]);
        i++;
    }

    return total_distance;
}

int main() 
{
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        perror("File opening failed");
        return 1;
    }

    int count = 0;
    Pair pair;
    while (fscanf(file, "%d %d", &pair.left, &pair.right) == 2) {
        count++;
    }
    rewind(file);
    int *left_list = malloc(count * sizeof(int));
    int *right_list = malloc(count * sizeof(int));
    
    if (!left_list || !right_list) {
        perror("Memory allocation failed");
        return 1;
    }

    
    int i = 0;
    while (fscanf(file, "%d %d", &pair.left, &pair.right) == 2) 
    {
        left_list[i] = pair.left;
        right_list[i] = pair.right;
        i++;
    }

    fclose(file);


    sort_array(left_list, count);
    sort_array(right_list, count);

    int total_distance = calculate_total_distance(left_list, right_list, count);

    printf("La distance totale entre les deux listes est : %d\n", total_distance);

    free(left_list);
    free(right_list);

    return 0;
}
