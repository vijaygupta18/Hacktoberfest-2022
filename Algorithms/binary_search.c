#include <stdio.h>
#include <conio.H>

void main()
{
    int first, last, mid, size, sElement, list[50];
    printf("Enter the size of list: ");
    scanf("%d", &size);
    printf("Enter  %d integer values:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }

    printf("Enter the Search element value: ");
    scanf("%d", &sElement);

    first = 0;
    last = size - 1;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (list[mid] == sElement)
        {
            printf("Element found at index %d .\n", mid);
            break;
        }
        else if (list[mid] < sElement)
        {
            last = mid + 1;
        }
        else
        {
            last = mid - 1;
        }

        if (first > 1)
        {
            printf("Element Not found in the list.");
        }
    }
    getch();
}
