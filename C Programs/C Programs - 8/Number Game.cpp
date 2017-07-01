#include <cstdio>

int main()
{
	int no_of_games;
	scanf("%d", &no_of_games);

	while(no_of_games--)
	{
		int number;
		scanf("%d", &number);

		printf(number%4 == 0 ? "Second\n" : "First\n");
	}

	return 0;
}
