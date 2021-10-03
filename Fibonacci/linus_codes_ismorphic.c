#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
// Function to check and return if strings
// str1 and str2 are ismorphic
bool areIsomorphic(char *str1, char *str2)
{
    // If the length of the strings
    // are not equal
    if (strlen(str1) != strlen(str2))
    {
        return false;
    }
    // Initialise two arrays
    int arr1[256] = {0}, arr2[256] = {0};
    // Travsersing both the strings
    for (int i = 0; i < strlen(str1); i++)
    {
        // If current characters don't map
        if (arr1[(int)str1[i]] != arr2[(int)str2[i]])
        {
            return false;
        }
        // Increment the count of characters
        // at their respective ASCII indices
        arr1[(int)str1[i]]++;
        arr2[(int)str2[i]]++;
    }
    return true;
}
int check_anagram(char s3[], char s4[])
{
    int first[26] = {0}, second[26] = {0}, c = 0;
    // Calculating frequency of characters of first string
    while (s3[c] != '\0')
    {
        first[s3[c] - 'a']++;
        c++;
    }
    c = 0;
    while (s4[c] != '\0')
    {
        second[s4[c] - 'a']++;
        c++;
    }
    // Comparing frequency of characters
    for (c = 0; c < 26; c++)
    {
        if (first[c] != second[c])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char s1[100], s2[100], s3[100], s4[100];
    printf("Input the first string for isomorphic checking: ");
    scanf("%s", s1);
    printf("Input the second string for isomorphic checking: ");
    scanf("%s", s2);
    printf("Input the first string for anagram checking: ");
    scanf("%s", s3);
    printf("Input the second string for anagram checking: ");
    scanf("%s", s4);
    pid_t pid = fork();
    if (pid == 0)
    {

        if (areIsomorphic(s1, s2))
        {
            printf("Yes, they are isomorphic\n");
        }
        else
        {
            printf("No, they are not isomorphic\n");
        }
    }

    else
    {
        if (check_anagram(s3, s4) == 1)
        {
            printf("The strings are anagrams\n");
        }
        else
        {
            printf("The strings are not anagrams\n");
        }
    }
}
