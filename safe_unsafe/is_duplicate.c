#include "safe_unsafe.h"

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