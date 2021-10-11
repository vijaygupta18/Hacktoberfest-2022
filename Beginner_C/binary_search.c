#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int indexOf(int array[], int find, int left, int right);
int compare(int num1, int num2);

int main()
{
    int array[] = {1, 2, 3, 4, 5};

    // Finding 3 in array.
    printf("%d\n", indexOf(array, 3, 0, 4));

    // Finding 4 in array.
    printf("%d\n", indexOf(array, 4, 0, 4));

    // Finding 1 in array.
    printf("%d\n", indexOf(array, 1, 0, (int)(sizeof(array) / sizeof(array[0]))));

    return 0;
}

int indexOf(int array[], int find, int left, int right)
{
    // If left is greater than right, object not found in array.
    if (left > right) { return -1; }

    int middle = (int)(floor((right - left) / 2)) + left;
    int query = compare(find, array[middle]);
    switch(query) {
        case 1 :
            left = middle + 1;
            break;
        case -1 :
            right = middle - 1;
            break;
        default :
            return middle;
    }

    indexOf(array, find, left, right);
}

int compare(int num1, int num2)
{
    if (num1 > num2) { return 1; }
    if (num1 < num2) { return -1; }
    return 0;
}