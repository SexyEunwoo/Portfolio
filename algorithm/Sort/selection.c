#include <stdio.h>

int main(void)
{
    int min, idx, temp;
    int arr[] = {10, 2, 5, 1, 8, 6, 8, 9, 3, 4};

    idx = 0;
    for(int i = 0; i < 10; i++)
    {
        min = 99999;
        for(int j = i; j < 10; j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}