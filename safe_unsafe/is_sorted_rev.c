#include "safe_unsafe.h"

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
