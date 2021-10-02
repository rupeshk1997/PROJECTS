#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 10
char *st[MAX];
int top=-1;

char *pop(char *st[]);
void push(char *st[],char *c);
void postfixtoprefix(char source[],char prefix[]);

void main()
{
 char prefix[100],postfix[100];

 printf("\n Enter any postfix expression: ");
   gets(postfix);

 strcpy(prefix,"");

 postfixtoprefix(postfix,prefix);

 printf("\n The prefix expression that corresponds to it is: ");
   puts(prefix);
}


void postfixtoprefix(char source[],char prefix[])
{
    int i=0,j;
    char *temp,*op1,*op2;
    while(source[i]!='\0')
    {
        if(isdigit(source[i]) || isalpha(source[i]))
        {
            temp=malloc(100*sizeof(char));
            temp[0]=source[i];temp[1]='\0';
            push(st,temp);
        }
        else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' ||source[i]=='%')
        {
            temp=malloc(100*sizeof(char));
            temp[0]=source[i];j=1;
            op1=pop(st);
            op2=pop(st);
            for(int k=0;op2[k]!='\0';k++)
            {
                temp[j]=op2[k];
                j++;
            }
            for(int k=0;op1[k]!='\0';k++)
            {
                temp[j]=op1[k];
                j++;
            }
            temp[j]='\0';
            push(st,temp);
            
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN THE EXPRESSION");
            exit(1);
        }
        i++;
    }
    while(top!=-1)
    {
        temp=pop(st);j=0;
        for(int k=0;temp[k]!='\0';k++)
        {
            prefix[j]=temp[k];
            j++;
        }
    }

    prefix[j]='\0';
}

void push(char *st[],char *val)
{
  if(top==(MAX-1))
   printf("\nStack overflow");

   else
   {
    top++;
    st[top]=val;
   }
}

char *pop(char *st[])
{
  char *val;
  if(top==-1)
   printf("\nStack underflow");
  
  else
  {
    val=st[top];
    top--;
  }

   return val;
}