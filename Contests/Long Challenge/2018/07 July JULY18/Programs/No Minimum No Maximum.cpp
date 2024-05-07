#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 5015, MOD = 1e9 + 7;
long long combinations[MAX_N][MAX_N];

long long power(long long x, long long power, long long mod)
{
    //Keeping power positive using Fermat's Little Theorem
    while(power < 0)
        power += mod - 1;

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

void precompute_combinations()
{
    for(int n = 0; n < MAX_N; n++)
    {
        for(int r = 0; r <= n; r++)
        {
            if(r == 0 || r == n)
                combinations[n][r] = 1;
            else
                combinations[n][r] = (combinations[n - 1][r - 1] + combinations[n - 1][r])%(MOD - 1);
        }
    }
}

void solve()
{
    int no_of_elements, sequence_length;
    scanf("%d %d", &no_of_elements, &sequence_length);

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    sort(all(A));

    long long answer = 1;

    for(int i = 1; i <= no_of_elements; i++)
    {
        long long total_sequences = combinations[no_of_elements - 1][sequence_length - 1];
        long long sequences_where_smallest = 0, sequences_where_largest = 0;

        if(no_of_elements - i >= sequence_length - 1)
            sequences_where_smallest = combinations[no_of_elements - i][sequence_length - 1];

        if(i - 1 >= sequence_length - 1)
            sequences_where_largest = combinations[i - 1][sequence_length - 1];

        answer *= power(A[i], total_sequences - sequences_where_largest - sequences_where_smallest, MOD);
        answer %= MOD;
    }

    printf("%lld\n", answer);
}

int main()
{
    precompute_combinations();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
