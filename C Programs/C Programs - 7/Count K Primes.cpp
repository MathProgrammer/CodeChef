#include <stdio.h>
#include <vector>

using namespace std;

vector <int> no_of_prime_factors(1e5 + 1, 0);

void precompute_prime_factors()
{
    for(int i = 2; i <= 1e5; i++)
    {
        if(no_of_prime_factors[i] == 0)
        {
            for(int j = i; j <= 1e5; j+= i)
            {
                no_of_prime_factors[j]++;
            }
        }
    }
}

void solve()
{
    int left, right, k;
    scanf("%d %d %d", &left, &right, &k);

    int no_of_k_primes = 0;
    for(int i = left; i <= right; i++)
        no_of_k_primes += (no_of_prime_factors[i] == k);

    printf("%d\n",no_of_k_primes);

}

int main()
{
    precompute_prime_factors();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
