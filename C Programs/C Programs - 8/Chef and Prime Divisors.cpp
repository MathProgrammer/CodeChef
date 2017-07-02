#include <cstdio>

long long reduce_num(long long n)
{
    long long prime_factors_n = 1LL;

    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0)
            {
                n = n/i;
            }

            prime_factors_n *= i;
        }
    }

    if(n > 1) //1 factor greater than it's square root
        prime_factors_n *= n;

    return prime_factors_n;
}

void solve()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    b = reduce_num(b);

    printf(a >= b && a%b == 0 ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
