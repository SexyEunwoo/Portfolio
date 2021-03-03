#include <stdio.h>

int main(void)
{
    int min, idx, temp;
    int arr[] = {10, 2, 5, 1, 8, 6, 8, 9, 3, 4};

    idx = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}