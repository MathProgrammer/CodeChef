#include <cstdio>
#include <vector>

using namespace std;

vector <int> primes;
vector <int> is_prime(1e5 + 1, true); //All primes till square root

void precompute_primes()
{

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < 1e5; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 1e5; multiple += i)
            {
                is_prime[multiple] = false;
            }
            primes.push_back(i);
        }
    }
}

bool number_is_prime(int n)
{
    //If n has no factors less than it's square root, it has no factors other than 1 and itself
    for(int p = 0; primes[p]*primes[p] <= n; p++)
        if(n%primes[p] == 0)
            return false;

    return true;
}

void solve()
{
    int left, right;
    scanf("%d %d", &left, &right);

    for(int i = left; i <= right; i++)
    {
        if(i <= 1e5)
        {
            if(is_prime[i])
                printf("%d\n",i);
        }
        else
        {
            if(number_is_prime(i))
                printf("%d\n", i);
        }
    }
    printf("\n");
}

int main()
{
    precompute_primes();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
