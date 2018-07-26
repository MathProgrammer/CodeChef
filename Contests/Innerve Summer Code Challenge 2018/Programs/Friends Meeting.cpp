#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &is_prime, int LIMIT)
{
    vector <int> primes;

    is_prime[1] = false;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;


        }
    }
}

void solve(vector <int> &is_prime)
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int one_exists = false, smallest_prime = 101;
    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);

        if(element == 1)
            one_exists = true;

        if(is_prime[element])
            smallest_prime = min(smallest_prime, element);
    }

    printf("%d\n", one_exists && smallest_prime != 101 ? smallest_prime : -1);
}

int main()
{
    const int LIMIT = 105;
    vector <int> is_prime(LIMIT, true);
    precompute(is_prime, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve(is_prime);

    return 0;
}
