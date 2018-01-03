#include <cstdio>

int power_mod(int x, long long power, int mod)
{
    int result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

	return result;
}

void solve()
{
	long long A, n;
	scanf("%lld %lld", &A, &n);

	A %= 9;

	switch(A)
	{
	    case 0: printf("9\n"); break;

	    case 3:
	    case 6: printf("%d\n", n >= 2 ? 9 : A); break;

	    default: const int PHI_9 = 6;
                 printf("%d\n", power_mod(A, n%PHI_9, 9));
	}
}

int main()
{
	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);

	while(no_of_test_cases--)
		solve();

	return 0;
}
