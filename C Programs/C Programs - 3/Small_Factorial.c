#include <stdio.h>

#define MAX_LENGTH 170

void solve()
{
    const int base = 10;
    int digit_i, first_digit, num;
    int carry, replace, product;
    int factorial[MAX_LENGTH] = {0};

    scanf("%d", &num);

    first_digit = 0;
    factorial[first_digit] = 1;

    while(num >= 1)
    {
        carry = 0;
        for(digit_i = 0; digit_i <= first_digit; digit_i++)
        {
            product = num*factorial[digit_i] + carry;
            replace = product%base;
            carry = product/base;

            factorial[digit_i] = replace;

            if( (digit_i == first_digit) && (carry > 0) )
            {
                first_digit++;
            }
        }

        num--;
    }

    for(digit_i = first_digit; digit_i >= 0; digit_i--)
        printf("%d",factorial[digit_i]);

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
