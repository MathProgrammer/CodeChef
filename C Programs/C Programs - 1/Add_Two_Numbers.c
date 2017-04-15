#include <stdio.h>

int main()
{
    int no_of_test_cases, i, a, b;
    scanf("%d",&no_of_test_cases);
    for(i = 1; i <=no_of_test_cases; i++)
    {
        scanf("%d %d",&a, &b);
        printf("%d\n",(a+b));
    }
    return 0;
}
