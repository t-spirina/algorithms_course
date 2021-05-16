#include <stdio.h>
#include <stdbool.h>

bool isSiple(int num)
{
    int mid = (num/2)+1;
    bool flag = true;
    if (num < 2)
        return false;
    for (int i = 2 ; i<mid ; i++)
    {
        if ((num%i)==0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{

    if(isSiple(11)) printf("simple\n");
    else printf("2\n");

    return 0;
}

