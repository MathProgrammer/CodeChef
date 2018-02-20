#include <cstdio>

#define min(a, b) (a < b ? a : b)

long long sum_till(long long n)
{
    return (n*(n + 1))/2;
}

long long get_answer_till(long long n, int MOD)
{
    long long answer = 0;
    long long starting = 1, ending;

    for(int digit = 1; starting <= n ; digit++, starting = ending + 1)
    {
        ending = min(10*starting - 1, n);

        answer += digit*sum_till(ending) - digit*sum_till(starting - 1) + MOD;
        answer %= MOD;
    }

    return answer;
}

void solve()
{
    const int MOD = 1e9 + 7;

    int left, right;
    scanf("%d %d", &left, &right);

    long long answer = (get_answer_till(right, MOD) - get_answer_till(left - 1, MOD) + MOD)%MOD;
    printf("%lld\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
