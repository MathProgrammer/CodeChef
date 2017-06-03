#include <stdio.h>

void solve()
{
	int no_of_numbers, no_of_ones = 0, number, no_of_zeroes = 0, i, no_of_ways_to_erase = 0;
	scanf("%d", &no_of_numbers);
	for(i = 1; i <= no_of_numbers; i++)
	{
		scanf("%d", &number);
		number == 0 ? no_of_zeroes++ : no_of_ones++;
	}

	no_of_ways_to_erase += (no_of_ones%2 == 1 ? no_of_ones : no_of_zeroes);

	printf("%d\n", no_of_ways_to_erase);
}
int main()
{
	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);
	while(no_of_test_cases-- != 0)
		solve();

	return 0;
}
