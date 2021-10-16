#include<stdio.h>
int HCF(int, int); //You have to write this function which calculates the HCF. 
	 
int main()
{
   int a, b, c, d, result;
   scanf("%d %d %d %d", &a, &b, &c, &d); /* Takes 4 number as input from the test data */
   result = HCF(HCF(a, b), HCF(c,d));
   printf("The HCF is %d", result);
}

//Complete the rest of the program to calculate HCF
int HCF(int a, int b)
{
  int temp;
    if(b>a)
    {
      while(b%a!=0)
      {
        b%a = temp;
        b=a;
        a=temp;
      }
      return a;
    }
   if(a>b)
    {
      while(a%b!=0)
      {
        a%b = temp;
        a=b;
        b=temp;
      }
      return b;
    }
}
