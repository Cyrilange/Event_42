#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
    int right;
} Pair;

int calculate_similarity_score(int *left_list, int *right_list, int left_size, int right_size) 
{
    int similarity_score = 0;
    int i = 0;

    while (i < left_size) 
    {
        int j = 0; 
        int count = 0;
        while (j < right_size) 
        {
            if (left_list[i] == right_list[j])
            {
                count++;
            }
            j++;
        }
        similarity_score += left_list[i] * count;
        i++;
    }

    return similarity_score;
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
    int similarity_score = calculate_similarity_score(left_list, right_list, count, count);
    printf("Le score de similarité entre les deux listes est : %d\n", similarity_score);
    free(left_list);
    free(right_list);
    return 0;
}
