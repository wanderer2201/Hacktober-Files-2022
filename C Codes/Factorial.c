#include<stdio.h>
// declaring the function
int fact(int);

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int num, f;
    printf("\n\nEnter a number: ");
    scanf("%d", &num);
    f= fact(num);
    printf("\n\nFactorial of  %d is  %d\n\n", num, f);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}

int fact(int aj)
{
    if(aj==1 || aj==0)
        return 1;
    else
        return (aj*fact(aj-1));
}