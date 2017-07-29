#include<stdio.h>
int main()
{
    char *s1="JAY PRAKASH";
    int i=0;
    char *s2="";
    i=strlen(s1)-1;
    while(*s1){
    s1++;
    }

    while(i!=0)
    {
        *s2=*s1;
        s2++;
        s1--;
        i--;
    }
    while(*s1){
        printf("Original Word",*s1);
        s1++;
 }
 while(*s2){
        printf("Reverse Word",*s2);
        s2++;
 }
}
