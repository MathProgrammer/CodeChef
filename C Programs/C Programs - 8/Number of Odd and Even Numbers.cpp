#include <cstdio>
#define abs(x) ( (x) > 0 ? (x) : 0 - (x) )

int main()
{
	int no_of_numbers, no_of_odd_numbers = 0, no_of_even_numbers;
	scanf("%d", &no_of_numbers);

	for(int i = 1; i <= no_of_numbers; i++)
	{
		int n;
		scanf("%d", &n);

		no_of_odd_numbers += n%2;
	}

	no_of_even_numbers = no_of_numbers - no_of_odd_numbers;
	printf("%d\n", abs(no_of_even_numbers - no_of_odd_numbers) );

	return 0;
}
