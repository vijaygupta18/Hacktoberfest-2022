#include <stdio.h>
#include <conio.h>

void main()
{
    int size, list[100];
    int i, j, min, swap;
    printf("Enter the size of list: ");
    scanf("%d", &size);
    printf("Enter  %d integer values:\n\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    printf("Printing array \n");
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", list[i]);
    }
    printf("\n");
    for (i = 0; i < size; i++)
    {
        //min = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                swap = list[j];
                list[j] = list[j + 1];
                list[j + 1] = swap;
            }
        }
    }
    
    printf("\nSorted Array:\n");
    printf("\n");
    for (i = 0; i < size; i++)
        printf("%d\t", list[i]);
    printf("\n");
}
