#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

const int MOD = 1e9 + 7, MAX_N = 1e6;
long long factorial[MAX_N + 5], inverse_factorial[MAX_N + 5];

long long power(long long base, long long exponent)
{
    long long result = 1;

    while(exponent)
    {
        if(exponent%2 == 1)
            result = (result*base)%MOD;

        exponent = exponent >> 1;
        base = (base*base)%MOD;
    }

    return result;
}

long long inverse(long long n)
{
    return power(n, MOD - 2);
}

long long choose_pairs(long long n)
{
    long long numerator = (factorial[n]*inverse_factorial[n/2])%MOD;
    long long inverse_denominator = inverse(power(2, n/2));

    return (numerator*inverse_denominator)%MOD;
}

void precompute()
{
    factorial[0] = 1;
    for(int i = 1; i <= MAX_N; i++)
        factorial[i] = (i*factorial[i - 1])%MOD;

    inverse_factorial[MAX_N] = inverse(factorial[MAX_N]);
    for(int i = MAX_N - 1; i >= 0; i--)
        inverse_factorial[i] = ((i + 1)*inverse_factorial[i + 1])%MOD;
}

void solve()
{
    vector <long long> frequency(MAX_N, 0);

    vector <int> S;

    int no_of_people;
    scanf("%d", &no_of_people);

    for(int i = 1; i <= no_of_people; i++)
    {
        int strength;
        scanf("%d", &strength);

        frequency[strength]++;

        if(frequency[strength] == 1)
            S.push_back(strength);
    }

    sort(all(S));

    long long no_of_ways = 1;

    for(int i = S.size() - 1; i >= 0; i--)
    {
        int frequency_here = frequency[S[i]];

        if(frequency_here == 0) continue;

        if(frequency_here%2 == 0)
        {
            no_of_ways *= choose_pairs(frequency_here);
        }
        else if(frequency_here == 1)
        {
            no_of_ways *= (frequency[S[i - 1]]);

            frequency[S[i - 1]]--;
        }
        else if(frequency_here%2 == 1)
        {
            int previous_frequency = frequency[S[i - 1]];

            no_of_ways *= choose_pairs(frequency_here - 1);
            no_of_ways %= MOD;

            no_of_ways *= ((frequency_here*previous_frequency)%MOD);

            frequency[S[i - 1]]--;
        }

        no_of_ways %= MOD;
    }

    printf("%lld\n", no_of_ways);
}

int main()
{
    precompute();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
