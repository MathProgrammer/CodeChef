#include <stdio.h>

void solve()
{
    const int MOD = 1e9 + 7;
    int A, B, n;
    long long term_n;

    scanf("%d %d %d",&A, &B, &n);

    //Function is cyclic with period 6. f(7) = f(1), f(8) = f(2), and since two terms determine the third term. The cycle repeats
    switch(n%6)
    {
        case 1: term_n = A; break;
        case 2: term_n = B; break;
        case 3: term_n = (1LL*B - A + MOD); break;
        case 4: term_n = (0 - A + MOD); break;
        case 5: term_n = (0 - B + MOD); break;
        case 0: term_n = (1LL*A - B + MOD); break;
    }

    term_n = (term_n + MOD)%MOD;
    printf("%lld\n",term_n);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}

