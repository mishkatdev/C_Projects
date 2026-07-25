#include <stdio.h>

struct Student
{
    char name[50];
    int roll;
    float cgpa;
};

int main()
{
    struct Student s1;

    strcpy(s1.name, "Mishkat");
    s1.roll = 101;
    s1.cgpa = 3.75;

    printf("Name: %s\n", s1.name);
    printf("Roll: %d\n", s1.roll);
    printf("CGPA: %.2f", s1.cgpa);

    return 0;
}