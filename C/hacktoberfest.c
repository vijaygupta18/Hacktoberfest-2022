#include <stdio.h>
#include <stdlib.h>
void main () {
    char name[100], link[100];

    printf("Welcome to hacktoberfest 2021!\n");
    printf("Visit this link for join: https://hacktoberfest.digitalocean.com\n");

    // Input your name
    printf("\nEnter your name: ");
    scanf(" %s", &name);

    // Input your github link
    printf("Enter your github link: ");
    scanf(" %s", &link);

    //  Recap your data
    printf("\n\n================\n");
    printf("Your name: %s", name);
    printf("\nYour github link: %s\n\n", link);


    printf("Happy hacking mate!\n\n");
}
