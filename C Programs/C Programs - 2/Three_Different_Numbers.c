#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

void solve()
{
    const int MOD = 1e9 + 7;
    long long N_1, N_2, N_3,sorted_N_1, sorted_N_2, sorted_N_3, number_of_triplets = 1LL;
    scanf("%lld %lld %lld", &N_1, &N_2, &N_3);

    sorted_N_1 = min(N_1, min(N_2, N_3));
    sorted_N_3 = max(N_1, max(N_2, N_3));
    sorted_N_2 = (N_1 + N_2 + N_3) - (sorted_N_1 + sorted_N_3);

    sorted_N_1 %= MOD;
    sorted_N_2 %= MOD;
    sorted_N_3 %= MOD;

    number_of_triplets = (number_of_triplets*sorted_N_1)%MOD;
    number_of_triplets = (number_of_triplets*(sorted_N_2-1 + MOD))%MOD;
    number_of_triplets = (number_of_triplets*(sorted_N_3-2 + MOD))%MOD;

    printf("%lld\n",number_of_triplets);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
