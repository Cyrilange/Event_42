#include "safe.h"

bool    is_no_duplicate(int *arr, int size)
{
    int i = 0;
    int j;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool is_valid(int *arr, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int diff = abs(arr[i] - arr[i + 1]);
        if (!(diff >= 1 && diff <= 3))
            return (false);
        i++;
    }
    return (true);
}

bool is_sorted_ascending(int *num, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        if (num[i] > num[i + 1])
            return false;
        i++;
    }
    return true;
}

bool is_sorted_descending(int *num, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        if (num[i] < num[i + 1])
            return false;
        i++;
    }
    return true;
}

bool check_if_safe(int *arr, int size)
{
    return (is_sorted_ascending(arr, size) || is_sorted_descending(arr, size)) && is_no_duplicate(arr, size) && is_valid(arr, size);
}

bool    safe_removal(int *num, int size)
{
    int i = 0;
    int j;
    while (i < size)
    {
        int aux[size - 1];
        int aux_size = 0;
        j = 0;
        while (j < size)
        {
            if (j != i)
                aux[aux_size++] = num[j];
            j++;
        }
        if (check_if_safe(aux, aux_size))
            return true;
        i++;
    }
    return false;
}
