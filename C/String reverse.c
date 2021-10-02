#include<stdio.h>
#include<string.h>

int main(){
    char str1[20];
    printf("Enter the string: ");
    scanf("%s",str1);
    for(int i=0;i<strlen(str1)/2;i++){
        char t = str1[i];
        str1[i] = str1[strlen(str1)-i-1];
        str1[strlen(str1)-i-1] = t;
    }
    printf("The reversed string is: %s\n",str1);
    return 0;
}