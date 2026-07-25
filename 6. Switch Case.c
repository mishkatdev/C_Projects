#include <stdio.h>

int main()
{
    int choice;

    printf("Enter 1-3: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("C Language");
            break;

        case 2:
            printf("C++ Language");
            break;

        case 3:
            printf("Java Language");
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}