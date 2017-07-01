#include <cstdio>
#include <vector>

using namespace std;

vector <int> prime_sum_till(1000 + 1, 0);

void precompute_primes()
{
    vector <int> is_prime(1000 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1000; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = i*i; multiple <= 1000; multiple += i)
            {
                is_prime[multiple] = false;
            }
        }
    }

    for(int i = 2; i <= 1000; i++)
        prime_sum_till[i] = prime_sum_till[i - 1] + (is_prime[i] ? i : 0);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_primes();

    while(no_of_test_cases-- != 0)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", prime_sum_till[n] - prime_sum_till[29 - 1]);
    }

    return 0;
}
