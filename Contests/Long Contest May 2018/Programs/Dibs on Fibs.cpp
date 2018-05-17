#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void precompute(vector <long long> &fibonacci, int LIMIT)
{
    const int MOD = 1e9 + 7;

    fibonacci.push_back(0);
    fibonacci.push_back(1);

    for(int i = 2; i <= LIMIT; i++)
        fibonacci.push_back( (fibonacci[i - 1] + fibonacci[i - 2])%MOD );
}

void solve(vector <long long> &fibonacci)
{
    int no_of_elements, length_of_series;
    scanf("%d %d", &no_of_elements, &length_of_series);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    vector <int> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &B[i]);

    const int MOD = 1e9 + 7;
    long long result = 0;

    if(length_of_series == 1)
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            result += A[i];
            result %= MOD;
        }
    }
    else if(length_of_series == 2)
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            result += B[i];
            result %= MOD;
        }
    }
    else
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            result += B[i]*fibonacci[length_of_series - 1]; // F(2)F(n - 1)
            result %= MOD;

            result += A[i]*fibonacci[length_of_series - 2]; // F(1)F(n - 2)
            result %= MOD;
        }
    }


    result *= no_of_elements;
    result %= MOD;

    printf("%lld\n", result);
}

int main()
{
    const int LIMIT = 1e5 + 15;
    vector <long long> fibonacci;
    precompute(fibonacci, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve(fibonacci);

    return 0;
}
