#include <cstdio>

long long lucky(int n)
{
	long long answer = 0;
	n = n << 1;

	for(int i = 31; i >= 0; i--)
	{
		answer = answer*5 + ( (n & (1 << i) ) != 0)	;
	}
	return answer;
}

int main()
{
	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);

	while(no_of_test_cases--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", lucky(n));
	}

	return 0;
}

