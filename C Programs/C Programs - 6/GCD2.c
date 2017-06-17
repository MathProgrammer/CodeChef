#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 250 + 1

int gcd(int a, int b) //b is always smaller than a
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int get_remainder(char b[], int a)
{
    int i, r = 0, no_of_digits = strlen(b);

    //Evaluate big num like a polynomial mod small num
    for(i = 0; i <  no_of_digits; i++)
    {
        r = r*10 + (b[i] - '0');
        r %= a;
    }

    return r;
}

int main()
{
    char b[MAX_LENGTH];
    int t, a;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %s",&a, b);

        if(a == 0)
            printf("%s\n",b);
        else
            printf("%d\n", gcd(a, get_remainder(b, a)) );

    }

    return 0;
}
