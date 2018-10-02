#include <cstdio>
#include <vector>

using namespace std;

void precompute_sieve(vector <int> &prime_divisors_sum, int MAX_N)
{
    vector <int> is_prime(MAX_N, true);
    for(int i = 2; i < MAX_N; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = i; multiple < MAX_N; multiple += i)
            {
                prime_divisors_sum[multiple] += i;

                is_prime[multiple] = false;
            }
        }
    }
}

void solve(vector <int> &prime_divisor_sum, int MAX_N)
{
    vector <long long> frequency(MAX_N, 0);

    int no_of_elements;
    scanf("%d", &no_of_elements);

    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);

        frequency[element]++;
    }

    long long good_pairs = 0;
    for(int i = 1; i < MAX_N; i++)
    {
        if(frequency[i] == 0) continue;

        good_pairs += frequency[i]*(frequency[i] - 1);

        for(int multiple = 2*i; multiple < MAX_N; multiple += i)
        {
            if(frequency[multiple] > 0 && prime_divisor_sum[multiple]%prime_divisor_sum[i] == 0)
            {
                good_pairs += frequency[i]*frequency[multiple];
            }
        }
    }

    printf("%lld\n", good_pairs);
}

int main()
{
    const int MAX_N = 1e6 + 6;
    vector <int> prime_divisors_sum(MAX_N, 0);
    precompute_sieve(prime_divisors_sum, MAX_N);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve(prime_divisors_sum, MAX_N);

    return 0;
}
