#include <cstdio>
#include <vector>

using namespace std;

int cube(int n)
{
    return n*n*n;
}

int square(int n)
{
    return n*n;
}

void precompute(vector <int> &is_prime, vector <int> &primes, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= LIMIT; multiple += i)
            {
                is_prime[multiple] = false;
            }
            primes.push_back(i);
        }
    }
}

void solve(int n, vector <int> &is_prime, vector <int> &primes)
{
    for(int i = 0; i < primes.size() && cube(primes[i]) <= n; i++)
    {
        for(int j = 0; j < primes.size() && square(primes[j]) <= n - cube(primes[i]); j++)
        {
            int k = n - cube(primes[i]) - square(primes[j]);

            if(is_prime[k])
            {
                printf("%d %d %d\n", k, primes[j], primes[i]);
                return;
            }
        }
    }

    printf("0 0 0\n");
}

int main()
{
    const int LIMIT = 1e6;
    vector <int> is_prime(LIMIT + 1, true);
    vector <int> primes;
    precompute(is_prime, primes, LIMIT);

    int n;
    while(true)
    {
        scanf("%d", &n);

        if(n == 0) return 0;

        solve(n, is_prime, primes);
    }

    return 0;
}
