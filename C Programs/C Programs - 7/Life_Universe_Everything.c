#include <stdio.h>

int main()
{
    int i;

    while(1)
    {
        scanf("%d\n",&i) ;
        if( i == 42 )
        {
            break;
        }
        printf("%d\n",i);
    }

    return 0;
}
