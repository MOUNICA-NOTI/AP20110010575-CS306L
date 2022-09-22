#include <stdio.h>
#include <string.h>

char *ip;
char string[50];
int S(),L(),Ldash();
int main()
{
    printf("Enter the string:");
    scanf("%s",string);
    ip=string;
    printf("\n------Input Action:------\n");
    if(S() && *ip=='\0')
    {
        printf("\n----------------------------------- \n");
        printf("String is succesfully parsed\n");
    }
    else
    {
        printf("Error in parsing String\n");
    }
}
int S()
{
    if(*ip=='(')
    {
        printf("%s\tS->(L)\n",ip);
        ip++;
        if(L())
        {
            if(*ip==')')
            {
                ip++;
                return 1;
            }
            else
              return 0;
        }
        else{
           return 0;
        }
    }
    else if(*ip=='a')
    {
        ip++;
        printf("%s\tS->a\n",ip);
        return 1;
    }
    else{
        return 0;
    }
}
int L()
{
    printf("%s\tL->SL'\n",ip);
    if(S())
    {
        if(Ldash())
        {
            return 1;
        }
        else
           return 0;
    }
    else
       return 0;
}
int Ldash()
{
    if(*ip==',')
    {
        printf("%s\tL'->,SL\n",ip);
        ip++;
        if(S())
        {
            if(Ldash())
            {
                return 1;
            }
            else
               return 0;
        }
        else
           return 0;
    }  
    else
    {
        printf("%s\tL'->^\n",ip);
        return 1;
    }
}  

