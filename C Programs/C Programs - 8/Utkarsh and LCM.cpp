#include <cstdio>
#include <map>

using namespace std;

int main()
{
	long long no_of_pairs = 0;
	int number_of_elements, element_i;
	scanf("%d", &number_of_elements);

	map <int, int> frequency;
	for(int i = 1; i <= number_of_elements; i++)
	{
		scanf("%d", &element_i);
		frequency[element_i]++;
	}

	map <int, int> :: iterator it;
	for(it = frequency.begin(); it != frequency.end(); it++)
	{
		int frequency_i = it->second;
		no_of_pairs += frequency_i*1LL*(number_of_elements - frequency_i);
	}

	printf("%lld\n", no_of_pairs/2); //Each pair has been counted twice.
	return 0;
}
