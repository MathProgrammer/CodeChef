#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &no_of_primes_till, int LIMIT)
{
    vector <int> is_prime(LIMIT, true);
    is_prime[0] = is_prime[1] = false;

    vector <int> primes;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }

    for(int i = 1; i < LIMIT; i++)
        no_of_primes_till[i] = no_of_primes_till[i - 1] + (is_prime[i]);
}

void solve(vector <int> &no_of_primes_till)
{
    int left, right;
    scanf("%d %d", &left, &right);

    printf("%d\n", no_of_primes_till[right] - no_of_primes_till[left - 1]);
}

int main()
{
    const int LIMIT = 1e6 + 2;
    vector <int> no_of_primes_till(LIMIT, 0);
    precompute(no_of_primes_till, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve(no_of_primes_till);

    return 0;
}
