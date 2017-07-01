#include <stdio.h>

void solve()
{
    int number, i;
    long long sum_of_divisors = 0LL;

    scanf("%d", &number);

    for(i = 2; i*i <= number; i++)
        if(number%i == 0)
            sum_of_divisors += (i*i == number ? i : i + number/i); ///Divisors come in pairs(i, N/i) except the square root(i, i)

    if(number > 1) //If it's not one, then we need to count 1 as a proper divisor
        sum_of_divisors++;

    printf("%lld\n",sum_of_divisors);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
