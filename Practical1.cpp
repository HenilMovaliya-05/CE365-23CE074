#include<bits/stdc++.h>
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int flag=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='a')
        {
            continue;
        }
        else if(str[i]=='b' && str[i+1]=='b' && str[i+2]=='\0')
        {
            flag=1;
            printf("Valid");
            break;
        }
        else
        {
            break;
        }
    }
    if(flag==0)
    {
        printf("Invalid");
    }
}