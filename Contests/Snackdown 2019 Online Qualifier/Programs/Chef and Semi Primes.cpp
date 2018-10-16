#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 205;
vector <int> primes;
vector <int> is_prime(MAX_N, true);

void precompute()
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < MAX_N; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < MAX_N; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

int is_semi_prime(int n)
{
    for(int i = 0; primes[i]*primes[i] < n; i++)
    {
        if(n%primes[i] == 0 && is_prime[n/primes[i]])
            return true;
    }

    return false;
}

void solve()
{
    int n;
    scanf("%d", &n);

    for(int i = 4; i <= n; i++)
    {
        if(is_semi_prime(i) && is_semi_prime(n - i))
        {
            printf("YES\n");
            return;
        }
    }

    printf("NO\n");
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

