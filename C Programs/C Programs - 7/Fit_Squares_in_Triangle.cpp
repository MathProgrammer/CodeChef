#include <stdio.h>

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int base;
        scanf("%d", &base);

        base = base/2;

        printf("%d\n", (base*base - base)/2);
    }

    return 0;
}
