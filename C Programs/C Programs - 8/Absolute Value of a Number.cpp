#include <cstdio>
#define abs(x) ( (x) > 0 ? (x) : 0 - (x) )

int main()
{
	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);

	while(no_of_test_cases--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", abs(n));
	}

	return 0;
}
