#include <cstdio>
#include <map>

using namespace std;

long long power(long long x, long long power, long long mod)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long n, long long mod)
{
    return power(n, mod - 2, mod); //Mod is prime here
}

void solve()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);

    const int MOD = 1e9 + 7;
    long long numerator = (power(k, n + 1, MOD) - k + MOD)%MOD;
    long long denominator = (k + MOD - 1)%MOD;

    long long answer = (k == 1 ? 1 : (numerator*inverse(denominator, MOD))%MOD);
    printf("%lld\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
