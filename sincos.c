#include<stdio.h>  
#include<math.h>  
  
int main()  
{  
    float sum = 0, angle, temp;  
  
    printf("Enter angle in Degree\n");  
    scanf("%f", &angle);  
  
    temp   = angle;  
  
    angle  = angle * ( M_PI / 180.0 );  
  
    sum    = (  pow(sin(angle), 2) + pow(cos(angle), 2)  );  
  
    if(sum == 1)  
    {  
        printf("Sum of square of sin(%0.2f) and cos(%0.2f) is 1\n", temp, temp);  
    }  
    else  
    {  
        printf("Sum of square of sin(%0.2f) and cos(%0.2f) is not 1\n", temp, temp);  
    }  
  
    return 0;  
}  