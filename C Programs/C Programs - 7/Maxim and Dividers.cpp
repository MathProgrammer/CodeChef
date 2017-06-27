#include <cstdio>

int is_overlucky(int n)
{
    while(n > 0)
    {
        if(n%10 == 4 || n%10 == 7)
            return true;

        n = n/10;
    }

    return false;
}

void solve()
{
    int number, overlucky_divisors = 0;
    scanf("%d", &number);

    for(int i = 1; i*i <= number; i++)
    {
        if(number%i == 0)
        {
            overlucky_divisors += (is_overlucky(i) == true);

            if(i*i != number)
                overlucky_divisors += (is_overlucky(number/i) == true);
        }
    }

    printf("%d\n", overlucky_divisors);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
