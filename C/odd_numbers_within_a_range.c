#include <stdio.h>
          //Q4.WAP to print all odd numbers from a range.
int main()
{   int a, b;
 
    printf("Enter the extremeties of your range\n");
    scanf("%d %d", &a, &b);
    
    for( ; a<=b;a++)
    {
        if(a%2!=0)   // for even numbers use ==
          {
              printf("%d\n",a);
          }
    }

    
  
    return 0;
}


