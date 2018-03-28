#include <cstdio>
#include <vector>

using namespace std;
typedef vector <int> v_int;

void precompute(vector <int> &primes, int LIMIT)
{
    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] <= LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

long long power_mod(long long x, int power, int mod)
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

int get_exponent(int n, int p)
{
    int answer = 0;

    while(n%p == 0)
    {
        answer++;
        n /= p;
    }

    return answer;
}

int main()
{
    const int LIMIT = 100;
    vector <int> primes;
    precompute(primes, LIMIT);

    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    vector <v_int> exponent_sum( primes.size() + 1, v_int(no_of_elements + 1, 0) );
    for(int p = 0; p < primes.size(); p++)
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            exponent_sum[p][i] = exponent_sum[p][i - 1] + get_exponent(A[i], primes[p]);
        }
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int left, right, mod;
        scanf("%d %d %d", &left, &right, &mod);

        long long segment_product = 1;

        for(int p = 0; p < primes.size(); p++)
        {
            int exponent = exponent_sum[p][right] - exponent_sum[p][left - 1];

            segment_product *= power_mod(primes[p], exponent, mod);
            segment_product %= mod;
        }

        printf("%lld\n", segment_product);
    }

    return 0;
}
