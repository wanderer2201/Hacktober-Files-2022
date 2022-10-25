#include<stdio.h>
// declaring the function
int fact(int);  // function prototyping

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int num, f;
    printf("\n\nEnter a number: ");
    scanf("%d", &num);
    f= fact(num); //function calling
    printf("\n\nFactorial of  %d is  %d\n\n", num, f);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}

int fact(int aj)  // function defining
{
    if(aj==1 || aj==0)
        return 1;
    else
        return (aj*fact(aj-1));
}
