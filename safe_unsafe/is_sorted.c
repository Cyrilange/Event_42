#include "safe_unsafe.h"

#include <stdbool.h>

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
