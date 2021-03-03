#include <stdio.h>

int main(void)
{
    int i, j, temp;
    int arr[] = {10, 2, 5, 1, 8, 6, 8, 9, 3, 4};

    for(int i = 1; i < 10; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(arr[j] <= arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
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