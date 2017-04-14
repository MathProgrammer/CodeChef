#include <stdio.h>

int main()
{
    unsigned int no_of_test_cases, i, remainder, divisor, dividend;
    scanf("%u",&no_of_test_cases);
    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%u %u",&dividend, &divisor);
        remainder = dividend%divisor;
        printf("%u\n",remainder);
    }
    return 0;
}
